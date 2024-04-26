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
 * @version Driver Version  3.1.0
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

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 aliases
#define RA4_IN1_TRIS                 TRISAbits.TRISA4
#define RA4_IN1_LAT                  LATAbits.LATA4
#define RA4_IN1_PORT                 PORTAbits.RA4
#define RA4_IN1_WPU                  WPUAbits.WPUA4
#define RA4_IN1_OD                   ODCONAbits.ODCA4
#define RA4_IN1_ANS                  ANSELAbits.ANSELA4
#define RA4_IN1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_IN1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_IN1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_IN1_GetValue()           PORTAbits.RA4
#define RA4_IN1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_IN1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_IN1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_IN1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_IN1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RA4_IN1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RA4_IN1_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_IN1_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define RA5_IN2_TRIS                 TRISAbits.TRISA5
#define RA5_IN2_LAT                  LATAbits.LATA5
#define RA5_IN2_PORT                 PORTAbits.RA5
#define RA5_IN2_WPU                  WPUAbits.WPUA5
#define RA5_IN2_OD                   ODCONAbits.ODCA5
#define RA5_IN2_ANS                  ANSELAbits.ANSELA5
#define RA5_IN2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_IN2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_IN2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_IN2_GetValue()           PORTAbits.RA5
#define RA5_IN2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_IN2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_IN2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_IN2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_IN2_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RA5_IN2_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RA5_IN2_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_IN2_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSELB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB3 aliases
#define RB3_IN2_TRIS                 TRISBbits.TRISB3
#define RB3_IN2_LAT                  LATBbits.LATB3
#define RB3_IN2_PORT                 PORTBbits.RB3
#define RB3_IN2_WPU                  WPUBbits.WPUB3
#define RB3_IN2_OD                   ODCONBbits.ODCB3
#define RB3_IN2_ANS                  ANSELBbits.ANSELB3
#define RB3_IN2_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_IN2_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_IN2_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_IN2_GetValue()           PORTBbits.RB3
#define RB3_IN2_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_IN2_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_IN2_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_IN2_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_IN2_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define RB3_IN2_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define RB3_IN2_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_IN2_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define RB4_IN0_TRIS                 TRISBbits.TRISB4
#define RB4_IN0_LAT                  LATBbits.LATB4
#define RB4_IN0_PORT                 PORTBbits.RB4
#define RB4_IN0_WPU                  WPUBbits.WPUB4
#define RB4_IN0_OD                   ODCONBbits.ODCB4
#define RB4_IN0_ANS                  ANSELBbits.ANSELB4
#define RB4_IN0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_IN0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_IN0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_IN0_GetValue()           PORTBbits.RB4
#define RB4_IN0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_IN0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_IN0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_IN0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_IN0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RB4_IN0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RB4_IN0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_IN0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC1 aliases
#define DEBUG_PIN_2_TRIS                 TRISCbits.TRISC1
#define DEBUG_PIN_2_LAT                  LATCbits.LATC1
#define DEBUG_PIN_2_PORT                 PORTCbits.RC1
#define DEBUG_PIN_2_WPU                  WPUCbits.WPUC1
#define DEBUG_PIN_2_OD                   ODCONCbits.ODCC1
#define DEBUG_PIN_2_ANS                  ANSELCbits.ANSELC1
#define DEBUG_PIN_2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DEBUG_PIN_2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DEBUG_PIN_2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DEBUG_PIN_2_GetValue()           PORTCbits.RC1
#define DEBUG_PIN_2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DEBUG_PIN_2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DEBUG_PIN_2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DEBUG_PIN_2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DEBUG_PIN_2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define DEBUG_PIN_2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define DEBUG_PIN_2_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define DEBUG_PIN_2_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

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
#define LED0_TRIS                 TRISCbits.TRISC7
#define LED0_LAT                  LATCbits.LATC7
#define LED0_PORT                 PORTCbits.RC7
#define LED0_WPU                  WPUCbits.WPUC7
#define LED0_OD                   ODCONCbits.ODCC7
#define LED0_ANS                  ANSELCbits.ANSELC7
#define LED0_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED0_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED0_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED0_GetValue()           PORTCbits.RC7
#define LED0_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED0_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.WPUD0
#define IO_RD0_OD                   ODCONDbits.ODCD0
#define IO_RD0_ANS                  ANSELDbits.ANSELD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.WPUD1
#define IO_RD1_OD                   ODCONDbits.ODCD1
#define IO_RD1_ANS                  ANSELDbits.ANSELD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSELD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set RD5 aliases
#define IO_RD5_TRIS                 TRISDbits.TRISD5
#define IO_RD5_LAT                  LATDbits.LATD5
#define IO_RD5_PORT                 PORTDbits.RD5
#define IO_RD5_WPU                  WPUDbits.WPUD5
#define IO_RD5_OD                   ODCONDbits.ODCD5
#define IO_RD5_ANS                  ANSELDbits.ANSELD5
#define IO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_GetValue()           PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_RD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_RD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_RD5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

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

// get/set RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.WPUD7
#define IO_RD7_OD                   ODCONDbits.ODCD7
#define IO_RD7_ANS                  ANSELDbits.ANSELD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set RE2 aliases
#define DEBUG_PIN_1_TRIS                 TRISEbits.TRISE2
#define DEBUG_PIN_1_LAT                  LATEbits.LATE2
#define DEBUG_PIN_1_PORT                 PORTEbits.RE2
#define DEBUG_PIN_1_WPU                  WPUEbits.WPUE2
#define DEBUG_PIN_1_OD                   ODCONEbits.ODCE2
#define DEBUG_PIN_1_ANS                  ANSELEbits.ANSELE2
#define DEBUG_PIN_1_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define DEBUG_PIN_1_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define DEBUG_PIN_1_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define DEBUG_PIN_1_GetValue()           PORTEbits.RE2
#define DEBUG_PIN_1_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define DEBUG_PIN_1_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define DEBUG_PIN_1_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define DEBUG_PIN_1_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define DEBUG_PIN_1_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define DEBUG_PIN_1_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define DEBUG_PIN_1_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define DEBUG_PIN_1_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set RF0 aliases
#define IO_RF0_TRIS                 TRISFbits.TRISF0
#define IO_RF0_LAT                  LATFbits.LATF0
#define IO_RF0_PORT                 PORTFbits.RF0
#define IO_RF0_WPU                  WPUFbits.WPUF0
#define IO_RF0_OD                   ODCONFbits.ODCF0
#define IO_RF0_ANS                  ANSELFbits.ANSELF0
#define IO_RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define IO_RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define IO_RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define IO_RF0_GetValue()           PORTFbits.RF0
#define IO_RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define IO_RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define IO_RF0_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define IO_RF0_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define IO_RF0_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define IO_RF0_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define IO_RF0_SetAnalogMode()      do { ANSELFbits.ANSELF0 = 1; } while(0)
#define IO_RF0_SetDigitalMode()     do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set RF2 aliases
#define LCD_BL_TRIS                 TRISFbits.TRISF2
#define LCD_BL_LAT                  LATFbits.LATF2
#define LCD_BL_PORT                 PORTFbits.RF2
#define LCD_BL_WPU                  WPUFbits.WPUF2
#define LCD_BL_OD                   ODCONFbits.ODCF2
#define LCD_BL_ANS                  ANSELFbits.ANSELF2
#define LCD_BL_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define LCD_BL_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define LCD_BL_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define LCD_BL_GetValue()           PORTFbits.RF2
#define LCD_BL_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define LCD_BL_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define LCD_BL_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define LCD_BL_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define LCD_BL_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define LCD_BL_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define LCD_BL_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define LCD_BL_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set RF3 aliases
#define LCD_CS_TRIS                 TRISFbits.TRISF3
#define LCD_CS_LAT                  LATFbits.LATF3
#define LCD_CS_PORT                 PORTFbits.RF3
#define LCD_CS_WPU                  WPUFbits.WPUF3
#define LCD_CS_OD                   ODCONFbits.ODCF3
#define LCD_CS_ANS                  ANSELFbits.ANSELF3
#define LCD_CS_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define LCD_CS_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define LCD_CS_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define LCD_CS_GetValue()           PORTFbits.RF3
#define LCD_CS_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define LCD_CS_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define LCD_CS_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define LCD_CS_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define LCD_CS_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define LCD_CS_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define LCD_CS_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define LCD_CS_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set RF4 aliases
#define IO_RF4_TRIS                 TRISFbits.TRISF4
#define IO_RF4_LAT                  LATFbits.LATF4
#define IO_RF4_PORT                 PORTFbits.RF4
#define IO_RF4_WPU                  WPUFbits.WPUF4
#define IO_RF4_OD                   ODCONFbits.ODCF4
#define IO_RF4_ANS                  ANSELFbits.ANSELF4
#define IO_RF4_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define IO_RF4_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define IO_RF4_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define IO_RF4_GetValue()           PORTFbits.RF4
#define IO_RF4_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define IO_RF4_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define IO_RF4_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define IO_RF4_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define IO_RF4_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define IO_RF4_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define IO_RF4_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define IO_RF4_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set RF5 aliases
#define IO_RF5_TRIS                 TRISFbits.TRISF5
#define IO_RF5_LAT                  LATFbits.LATF5
#define IO_RF5_PORT                 PORTFbits.RF5
#define IO_RF5_WPU                  WPUFbits.WPUF5
#define IO_RF5_OD                   ODCONFbits.ODCF5
#define IO_RF5_ANS                  ANSELFbits.ANSELF5
#define IO_RF5_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define IO_RF5_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define IO_RF5_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define IO_RF5_GetValue()           PORTFbits.RF5
#define IO_RF5_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define IO_RF5_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define IO_RF5_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define IO_RF5_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define IO_RF5_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define IO_RF5_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define IO_RF5_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define IO_RF5_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set RF6 aliases
#define LCD_DC_TRIS                 TRISFbits.TRISF6
#define LCD_DC_LAT                  LATFbits.LATF6
#define LCD_DC_PORT                 PORTFbits.RF6
#define LCD_DC_WPU                  WPUFbits.WPUF6
#define LCD_DC_OD                   ODCONFbits.ODCF6
#define LCD_DC_ANS                  ANSELFbits.ANSELF6
#define LCD_DC_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define LCD_DC_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define LCD_DC_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define LCD_DC_GetValue()           PORTFbits.RF6
#define LCD_DC_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define LCD_DC_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define LCD_DC_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define LCD_DC_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define LCD_DC_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define LCD_DC_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define LCD_DC_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define LCD_DC_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)

// get/set RF7 aliases
#define LCD_RST_TRIS                 TRISFbits.TRISF7
#define LCD_RST_LAT                  LATFbits.LATF7
#define LCD_RST_PORT                 PORTFbits.RF7
#define LCD_RST_WPU                  WPUFbits.WPUF7
#define LCD_RST_OD                   ODCONFbits.ODCF7
#define LCD_RST_ANS                  ANSELFbits.ANSELF7
#define LCD_RST_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define LCD_RST_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define LCD_RST_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define LCD_RST_GetValue()           PORTFbits.RF7
#define LCD_RST_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define LCD_RST_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define LCD_RST_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define LCD_RST_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define LCD_RST_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define LCD_RST_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define LCD_RST_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define LCD_RST_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

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


#endif // PINS_H
/**
 End of File
*/