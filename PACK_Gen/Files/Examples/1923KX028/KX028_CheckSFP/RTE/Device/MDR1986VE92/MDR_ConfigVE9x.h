#ifndef MDR_CONFIG_VE9x_H
#define MDR_CONFIG_VE9x_H

#include <MDR_1986VE9x.h> 


//=============  Debug Uart printf settings  ==================
#define UART_DEBUG_IND              2    
#define UART_DEBUG_SHOW_WELLCOME    1
#define UART_DEBUG_BAUD_DEF         9600


//=============  Защита пинов совмещенных с Jtag  ==================
// Писать в пины порта совмещенные с Jtag можно только 0.
// Иначе отладчик потеряет соединение. Активным может быть только один.

#define USE_JTAG_A
//#define USE_JTAG_B
//#define USE_SWD_A
//#define USE_SWD_B


//================  Параметры источников частоты ================
//  Internal Generators
#define HSI_FREQ_HZ         8000000UL
#define HSI_FREQ_TRIM       MDR_BKP_HSI_TRIM_8M0Hz
#define HSI_TIMEOUT         0x0600UL
#define HSI_LOW_SRI         MDR_LOWRI_le40MHz
#define HSI_DELAY_EEPROM    EEPROM_Delay_le25MHz


#define LSI_FREQ_HZ         40000UL
#define LSI_FREQ_TRIM       MDR_BKP_LSI_TRIM_40KHz
#define LSI_TIMEOUT         0x0600UL
#define LSI_LOW_SRI         MDR_LOWRI_le40MHz
#define LSI_DELAY_EEPROM    EEPROM_Delay_le25MHz

//  External Generators
#define HSE_FREQ_HZ         8000000UL
#define HSE_TIMEOUT         0x0600UL
#define HSE_LOW_SRI         MDR_LOWRI_le40MHz
#define HSE_DELAY_EEPROM    EEPROM_Delay_le25MHz

#define LSE_FREQ_HZ         32768UL
#define LSE_TIMEOUT         0xF0000UL
#define LSE_LOW_SRI         MDR_LOWRI_le40MHz
#define LSE_DELAY_EEPROM    EEPROM_Delay_le25MHz


//  PLL Ready Timeout
#define PLL_TIMEOUT       0x0600UL


// =========================   DMA   ================================
//  Для экономии памяти можно прописать 0, если альтернативные структуры DMA не используются
#define USE_DMA_ALTER_STRUCT            1
//  Можно завести собственную управляющую структуру каналов вместо глобальной (по умолчанию). 
#define USE_DMA_USER_CNTLS_CTRL_TABLE   0


// =========================   Timer Bugfixes   ================================
//  Прерывание возникает раньше, чем обновляются регистры CCR и CCR1
#define USE_TIM_CAP_FIX   1


// =========================   POWER Bugfixes   ================================
// Флаги событий не стираются с первого раза
#define USE_PWR_CLR_FIX   1


// =========================   MDR_Delay ===========================
//  Выбор реализации для MDR_Delay: 
//    По умолчанию используется ассемблерный вариант, универсальный
//    Вариант на Си сильно зависит от опций компилятора
//    Вариант на DWT есть только в Cortex-M3/M4 и требует предварительное включение вызовом MDR_Delay_Init().
#define   USE_MDR_DELAY_ASM
//#define   USE_MDR_DELAY_C
//#define   USE_MDR_DELAY_DWT

//  Исполнение функции задержки из ОЗУ / EEPROM происходит за разное количество тактов CPU. 
//  Данными параметрами можно уточнить сколько тактов CPU занимает один цикл задержки в MDR_Funcs, для повышения точности.
#define DELAY_LOOP_CYCLES_ASM       3
#define DELAY_LOOP_CYCLES_ASM_RAM   9
#define DELAY_LOOP_CYCLES_C         6
#define DELAY_LOOP_CYCLES_C_RAM    12
#define DELAY_LOOP_CYCLES_DWT       1


#ifdef USE_MDR_DELAY_C
  #define DELAY_LOOP_CYCLES         DELAY_LOOP_CYCLES_C
  #define DELAY_LOOP_CYCLES_RAM     DELAY_LOOP_CYCLES_C_RAM
#elif defined USE_MDR_DELAY_DWT  
  #define DELAY_LOOP_CYCLES         DELAY_LOOP_CYCLES_DWT
  #define DELAY_LOOP_CYCLES_RAM     DELAY_LOOP_CYCLES_WDT_RAM
#else
  #define DELAY_LOOP_CYCLES         DELAY_LOOP_CYCLES_ASM
  #define DELAY_LOOP_CYCLES_RAM     DELAY_LOOP_CYCLES_ASM
#endif


//===========================  Soft I2C  ===========================
// "Отключение" программного SlaveI2C, чтобы собирался MDR_SoftI2C_byTimer, если драйвер MDR_SoftI2C_SlaveStates не подключен
#define I2C_SOFT_SLAVE_DISABLE   1

// "Отключение" программного MasterI2C, чтобы собирался MDR_SoftI2C_byTimer, если драйвер MDR_SoftI2C_MasterStates не подключен
#define I2C_SOFT_MASTER_DISABLE  0

//  Включение задержки после формирования СТОП, чтобы отложить следующий СТАРТ. 
//  Иначе SDA фронт-спад возможно "сливаются" слишком близко для какого нибудь ведомого и он их не поймет.
#define I2C_STOP_DELAY_EN        1



#endif  //  MDR_CONFIG_VE9x_H
