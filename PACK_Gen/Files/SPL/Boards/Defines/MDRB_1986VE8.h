#ifndef _MDRB_1986VE8_H
#define _MDRB_1986VE8_H

#ifdef USE_BOARD_VE8 

#include <MDR_CPU_ClockSelect.h>

//===================================    Частота тактирования    ========================================

#define MDRB_CLK_PLL_HSE_RES_MAX     MDR_CLK_PLL_HSE_RES_DEF(MDRB_PLL_8MHz_TO_40MHz, MDRB_CPU_FREQ_SUPP_40MHz)


//  Переопределение пинов для удобства поиска конфликтов

    //  Port_C
    #define PIN_PC16     MDR_Pin_16   //  LED1,
    #define PIN_PC17     MDR_Pin_17   //  LED2,
    #define PIN_PC18     MDR_Pin_18   //  LED3,
    #define PIN_PC19     MDR_Pin_19   //  LED4,
    #define PIN_PC20     MDR_Pin_20   //  LED5,
    #define PIN_PC21     MDR_Pin_21   //  LED6,
    #define PIN_PC22     MDR_Pin_22   //  LED7,
    #define PIN_PC23     MDR_Pin_23   //  LED8,

    //  Port_E
    #define PIN_PE18     MDR_Pin_18   //    KEY1,
    #define PIN_PE19     MDR_Pin_19   //  
    #define PIN_PE20     MDR_Pin_20   //  
    #define PIN_PE21     MDR_Pin_21   //    KEY2,
    #define PIN_PE22     MDR_Pin_22   //    KEY3,


//  ----------    LEDs Definition -------------
    #define MDRB_LED_1 	              PIN_PC16
    #define MDRB_LED_2 	              PIN_PC17
    #define MDRB_LED_3 	              PIN_PC18
    #define MDRB_LED_4 	              PIN_PC19
    #define MDRB_LED_5 	              PIN_PC20
    #define MDRB_LED_6 	              PIN_PC21
    #define MDRB_LED_7 	              PIN_PC22
    #define MDRB_LED_8 	              PIN_PC23

    #define MDRB_LED_GPIO             MDR_GPIO_C    
    #define MDRB_LED_PinAll          (MDRB_LED_1 | MDRB_LED_2 | MDRB_LED_3 | MDRB_LED_4 | MDRB_LED_5 | MDRB_LED_6 | MDRB_LED_7 | MDRB_LED_8)


//  --------------  Buttons Definition  ------------
    #define MDRB_BTN_PORT_KEY1        MDR_GPIO_E
    #define MDRB_BTN_PIN_KEY1         PIN_PE18  // Up
	
    #define MDRB_BTN_PORT_KEY2        MDR_GPIO_E
    #define MDRB_BTN_PIN_KEY2         PIN_PE21  // Right
	
    #define MDRB_BTN_PORT_KEY3        MDR_GPIO_E
    #define MDRB_BTN_PIN_KEY3         PIN_PE22  // Down
	
    // for Initialization
    #define MDRB_BTN_GPIO             MDR_GPIO_E
    #define MDRB_BTN_PinSel           (PIN_PE18 | PIN_PE21 | PIN_PE22)
    
    // Active buttons Level
    #define MDRB_BTNs_PUSH_TO_GND

//  ---------------  UART1 Pin Definition ----------------
    //  PORT_F: PF0, PF1 - Main
    #define MDRB_UART1_TX_PE15_Ind	    15
    #define MDRB_UART1_RX_PE16_Ind	    16

    #define MDRB_UART1_TX_PE15_Msk	    MDR_Pin_15
    #define MDRB_UART1_RX_PE16_Msk		  MDR_Pin_16

    #define MDRB_UART1_TX_PE15_Port	    MDR_GPIO_E
    #define MDRB_UART1_RX_PE16_Port		  MDR_GPIO_E
    
    #define MDRB_UART1_TX_PE15_Func	    MDR_PIN_FUNC_5
    #define MDRB_UART1_RX_PE16_Func	    MDR_PIN_FUNC_5 

#else
   Please, select board in MDRB_BoardSelect.h!

#endif // USE_BOARD_VE8


#endif // _MDRB_1986VE8_H
