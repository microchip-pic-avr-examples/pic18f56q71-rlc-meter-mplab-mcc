/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define BUTTON_TRIS                 TRISAbits.TRISA0
#define BUTTON_LAT                  LATAbits.LATA0
#define BUTTON_PORT                 PORTAbits.RA0
#define BUTTON_WPU                  WPUAbits.WPUA0
#define BUTTON_OD                   ODCONAbits.ODCA0
#define BUTTON_ANS                  ANSELAbits.ANSELA0
#define BUTTON_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA0
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)
#define RA0_SetInterruptHandler  BUTTON_SetInterruptHandler

// get/set RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA4 aliases
#define oledC_RW_TRIS                 TRISAbits.TRISA4
#define oledC_RW_LAT                  LATAbits.LATA4
#define oledC_RW_PORT                 PORTAbits.RA4
#define oledC_RW_WPU                  WPUAbits.WPUA4
#define oledC_RW_OD                   ODCONAbits.ODCA4
#define oledC_RW_ANS                  ANSELAbits.ANSELA4
#define oledC_RW_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define oledC_RW_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define oledC_RW_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define oledC_RW_GetValue()           PORTAbits.RA4
#define oledC_RW_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define oledC_RW_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define oledC_RW_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define oledC_RW_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define oledC_RW_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define oledC_RW_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define oledC_RW_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define oledC_RW_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define RLC_CS_TRIS                 TRISAbits.TRISA5
#define RLC_CS_LAT                  LATAbits.LATA5
#define RLC_CS_PORT                 PORTAbits.RA5
#define RLC_CS_WPU                  WPUAbits.WPUA5
#define RLC_CS_OD                   ODCONAbits.ODCA5
#define RLC_CS_ANS                  ANSELAbits.ANSELA5
#define RLC_CS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RLC_CS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RLC_CS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RLC_CS_GetValue()           PORTAbits.RA5
#define RLC_CS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RLC_CS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RLC_CS_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RLC_CS_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RLC_CS_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RLC_CS_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RLC_CS_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RLC_CS_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 aliases
#define DEBUG_PIN1_TRIS                 TRISAbits.TRISA6
#define DEBUG_PIN1_LAT                  LATAbits.LATA6
#define DEBUG_PIN1_PORT                 PORTAbits.RA6
#define DEBUG_PIN1_WPU                  WPUAbits.WPUA6
#define DEBUG_PIN1_OD                   ODCONAbits.ODCA6
#define DEBUG_PIN1_ANS                  ANSELAbits.ANSELA6
#define DEBUG_PIN1_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DEBUG_PIN1_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DEBUG_PIN1_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DEBUG_PIN1_GetValue()           PORTAbits.RA6
#define DEBUG_PIN1_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DEBUG_PIN1_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define DEBUG_PIN1_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define DEBUG_PIN1_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define DEBUG_PIN1_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define DEBUG_PIN1_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define DEBUG_PIN1_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define DEBUG_PIN1_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB2 aliases
#define oledC_DC_TRIS                 TRISBbits.TRISB2
#define oledC_DC_LAT                  LATBbits.LATB2
#define oledC_DC_PORT                 PORTBbits.RB2
#define oledC_DC_WPU                  WPUBbits.WPUB2
#define oledC_DC_OD                   ODCONBbits.ODCB2
#define oledC_DC_ANS                  ANSELBbits.ANSELB2
#define oledC_DC_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define oledC_DC_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define oledC_DC_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define oledC_DC_GetValue()           PORTBbits.RB2
#define oledC_DC_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define oledC_DC_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define oledC_DC_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define oledC_DC_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define oledC_DC_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define oledC_DC_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define oledC_DC_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define oledC_DC_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.WPUC6
#define IO_RC6_OD                   ODCONCbits.ODCC6
#define IO_RC6_ANS                  ANSELCbits.ANSELC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define DEBUG_LED_TRIS                 TRISCbits.TRISC7
#define DEBUG_LED_LAT                  LATCbits.LATC7
#define DEBUG_LED_PORT                 PORTCbits.RC7
#define DEBUG_LED_WPU                  WPUCbits.WPUC7
#define DEBUG_LED_OD                   ODCONCbits.ODCC7
#define DEBUG_LED_ANS                  ANSELCbits.ANSELC7
#define DEBUG_LED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define DEBUG_LED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define DEBUG_LED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define DEBUG_LED_GetValue()           PORTCbits.RC7
#define DEBUG_LED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define DEBUG_LED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define DEBUG_LED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define DEBUG_LED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define DEBUG_LED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define DEBUG_LED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define DEBUG_LED_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define DEBUG_LED_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RD6 aliases
#define IO_RD6_TRIS                 TRISDbits.TRISD6
#define IO_RD6_LAT                  LATDbits.LATD6
#define IO_RD6_PORT                 PORTDbits.RD6
#define IO_RD6_WPU                  WPUDbits.WPUD6
#define IO_RD6_OD                   ODCONDbits.ODCD6
#define IO_RD6_ANS                  ANSELDbits.ANSELD6
#define IO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_GetValue()           PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define IO_RD6_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define IO_RD6_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define IO_RD6_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define IO_RD6_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RF2 aliases
#define IO_RF2_TRIS                 TRISFbits.TRISF2
#define IO_RF2_LAT                  LATFbits.LATF2
#define IO_RF2_PORT                 PORTFbits.RF2
#define IO_RF2_WPU                  WPUFbits.WPUF2
#define IO_RF2_OD                   ODCONFbits.ODCF2
#define IO_RF2_ANS                  ANSELFbits.ANSELF2
#define IO_RF2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define IO_RF2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define IO_RF2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define IO_RF2_GetValue()           PORTFbits.RF2
#define IO_RF2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define IO_RF2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define IO_RF2_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define IO_RF2_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define IO_RF2_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define IO_RF2_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define IO_RF2_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define IO_RF2_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set RF4 aliases
#define oledC_EN_TRIS                 TRISFbits.TRISF4
#define oledC_EN_LAT                  LATFbits.LATF4
#define oledC_EN_PORT                 PORTFbits.RF4
#define oledC_EN_WPU                  WPUFbits.WPUF4
#define oledC_EN_OD                   ODCONFbits.ODCF4
#define oledC_EN_ANS                  ANSELFbits.ANSELF4
#define oledC_EN_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define oledC_EN_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define oledC_EN_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define oledC_EN_GetValue()           PORTFbits.RF4
#define oledC_EN_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define oledC_EN_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define oledC_EN_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define oledC_EN_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define oledC_EN_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define oledC_EN_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define oledC_EN_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define oledC_EN_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set RF5 aliases
#define oledC_RST_TRIS                 TRISFbits.TRISF5
#define oledC_RST_LAT                  LATFbits.LATF5
#define oledC_RST_PORT                 PORTFbits.RF5
#define oledC_RST_WPU                  WPUFbits.WPUF5
#define oledC_RST_OD                   ODCONFbits.ODCF5
#define oledC_RST_ANS                  ANSELFbits.ANSELF5
#define oledC_RST_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define oledC_RST_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define oledC_RST_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define oledC_RST_GetValue()           PORTFbits.RF5
#define oledC_RST_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define oledC_RST_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define oledC_RST_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define oledC_RST_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define oledC_RST_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define oledC_RST_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define oledC_RST_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define oledC_RST_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set RF7 aliases
#define oledC_nCS_TRIS                 TRISFbits.TRISF7
#define oledC_nCS_LAT                  LATFbits.LATF7
#define oledC_nCS_PORT                 PORTFbits.RF7
#define oledC_nCS_WPU                  WPUFbits.WPUF7
#define oledC_nCS_OD                   ODCONFbits.ODCF7
#define oledC_nCS_ANS                  ANSELFbits.ANSELF7
#define oledC_nCS_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define oledC_nCS_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define oledC_nCS_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define oledC_nCS_GetValue()           PORTFbits.RF7
#define oledC_nCS_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define oledC_nCS_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define oledC_nCS_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define oledC_nCS_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define oledC_nCS_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define oledC_nCS_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define oledC_nCS_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define oledC_nCS_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

// get/set virtual Pin RW0 aliases
#define RW0_SetHigh()            do { LATWbits.LATW0 = 1; } while(0)
#define RW0_SetLow()             do { LATWbits.LATW0 = 0; } while(0)
#define RW0_Toggle()             do { LATWbits.LATW0 = ~LATWbits.LATW0; } while(0)
#define RW0_GetValue()           PORTWbits.RW0

// get/set virtual Pin RW1 aliases
#define RW1_SetHigh()            do { LATWbits.LATW1 = 1; } while(0)
#define RW1_SetLow()             do { LATWbits.LATW1 = 0; } while(0)
#define RW1_Toggle()             do { LATWbits.LATW1 = ~LATWbits.LATW1; } while(0)
#define RW1_GetValue()           PORTWbits.RW1

// get/set virtual Pin RW2 aliases
#define RW2_SetHigh()            do { LATWbits.LATW2 = 1; } while(0)
#define RW2_SetLow()             do { LATWbits.LATW2 = 0; } while(0)
#define RW2_Toggle()             do { LATWbits.LATW2 = ~LATWbits.LATW2; } while(0)
#define RW2_GetValue()           PORTWbits.RW2

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the BUTTON pin functionality
 * @param none
 * @return none
 */
void BUTTON_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BUTTON pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for BUTTON at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void BUTTON_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for BUTTON pin.
 *        This is a dynamic interrupt handler to be used together with the BUTTON_SetInterruptHandler() method.
 *        This handler is called every time the BUTTON ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*BUTTON_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BUTTON pin. 
 *        This is a predefined interrupt handler to be used together with the BUTTON_SetInterruptHandler() method.
 *        This handler is called every time the BUTTON ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void BUTTON_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/