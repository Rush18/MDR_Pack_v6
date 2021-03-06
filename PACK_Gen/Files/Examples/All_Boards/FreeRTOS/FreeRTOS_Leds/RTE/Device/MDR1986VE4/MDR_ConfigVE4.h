#ifndef MDR_CONFIG_VE4_H
#define MDR_CONFIG_VE4_H

#include <MDR_1986VE4.h>
  

//=============  Debug Uart printf settings  ==================
#define UART_DEBUG_IND              1    
#define UART_DEBUG_SHOW_WELLCOME    1
#define UART_DEBUG_BAUD_DEF         9600


//=============  Защита пинов совмещенных с Jtag  ==================
// Писать в пины порта совмещенные с Jtag можно только 0.
// Иначе отладчик потеряет соединение.

#define USE_SWD_A


//================  Параметры источников частоты ================
//  Internal Generators
#define HSI_FREQ_HZ         8000000UL
#define HSI_FREQ_TRIM       MDR_BKP_HSI_TRIM_8M0Hz
#define HSI_TIMEOUT         0x0600UL
#define HSI_LOW_SRI         MDR_LOWRI_le10MHz
#define HSI_DELAY_EEPROM    EEPROM_Delay_le18MHz


#define LSI_FREQ_HZ         40000UL
#define LSI_FREQ_TRIM       MDR_BKP_LSI_TRIM_40KHz
#define LSI_TIMEOUT         0x0600UL
#define LSI_LOW_SRI         MDR_LOWRI_le200KHz
#define LSI_DELAY_EEPROM    EEPROM_Delay_le18MHz

//  External Generators
#define HSE_FREQ_HZ         8000000UL
#define HSE_TIMEOUT         0x0600UL
#define HSE_LOW_SRI         MDR_LOWRI_le40MHz
#define HSE_DELAY_EEPROM    EEPROM_Delay_le36MHz

#define LSE_FREQ_HZ         32768UL
#define LSE_TIMEOUT         0xF0000UL
#define LSE_LOW_SRI         MDR_LOWRI_le200KHz
#define LSE_DELAY_EEPROM    EEPROM_Delay_le18MHz


//  PLL Ready Timeout
#define PLL_TIMEOUT       0x0600UL


// =========================   DMA   ================================
//  Для экономии памяти можно прописать 0, если альтернативные структуры DMA не используются
#define USE_DMA_ALTER_STRUCT   1
//  Можно завести собственную управляющую структуру каналов вместо глобальной (по умолчанию). 
#define USE_DMA_USER_CNTLS_CTRL_TABLE   0


// =========================   Timer Bugfixes   ================================
//  Прерывание возникает раньше, чем обновляются регистры CCR и CCR1
#define USE_TIM_CAP_FIX   0


// =========================   POWER Bugfixes   ================================
// Флаги событий не стираются с первого раза
#define USE_PWR_CLR_FIX   1


// =========================   MDR_Delay ===========================
//  Выбор реализации для MDR_Delay: 
//    По умолчанию используется ассемблерный вариант, универсальный
//    Вариант на Си сильно зависит от опций компилятора
#define   USE_MDR_DELAY_ASM
//#define   USE_MDR_DELAY_C

//  Исполнение функции задержки из ОЗУ / EEPROM происходит за разное количество тактов CPU. 
//  Данными параметрами можно уточнить сколько тактов CPU занимает один цикл задержки в MDR_Funcs, для повышения точности.
#define DELAY_LOOP_CYCLES_ASM       8
#define DELAY_LOOP_CYCLES_ASM_RAM   4
#define DELAY_LOOP_CYCLES_C         14
#define DELAY_LOOP_CYCLES_C_RAM     9

#ifdef USE_MDR_DELAY_C
  #define DELAY_LOOP_CYCLES         DELAY_LOOP_CYCLES_C
  #define DELAY_LOOP_CYCLES_RAM     DELAY_LOOP_CYCLES_C_RAM
#else
  #define DELAY_LOOP_CYCLES         DELAY_LOOP_CYCLES_ASM
  #define DELAY_LOOP_CYCLES_RAM     DELAY_LOOP_CYCLES_ASM_RAM
#endif


//===========================  FreeRTOS (for FreeRTOSConfig.h)  ===========================
//  Выбор таймера для отсчета configTICK_RATE_HZ, по умолчанию - системный таймер SysTimer
#define configOVERRIDE_DEFAULT_TICK_CONFIGURATION     0

#if configOVERRIDE_DEFAULT_TICK_CONFIGURATION != 0
  // Выбор аппаратного таймера для FreeRTOS (вместо SysTimer который в ВЕ1 и ВЕ3 имеет ошибку в errata)
  #define MDR_FREE_RTOS_TIMER                MDR_TIMER1ex
  #define MDR_FREE_RTOS_TIMER_HANDLER        TIMER1_IRQHandler
  
  // Подстройка отсчетов времени при configUSE_TICKLESS_IDLE = 1
  // !!! Значение неправильное (взято наглаз по скорости мигания светодиода), перемерить осциллографом и поменять!!!
  // см функцию - vPortSuppressTicksAndSleep() файл FreeRTOS/port.c
  #define MDR_FREE_RTOS_TIMER_MISSED_FACTOR  445
#endif


#endif  //  MDR_CONFIG_VE4_H
