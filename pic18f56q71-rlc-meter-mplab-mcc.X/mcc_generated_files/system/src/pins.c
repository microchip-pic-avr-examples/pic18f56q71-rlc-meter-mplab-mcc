/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

#include "../pins.h"

void (*BUTTON_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x20;
    LATB = 0x0;
    LATC = 0x0;
    LATD = 0x0;
    LATE = 0x0;
    LATF = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    ODCONF = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x8F;
    TRISB = 0xEA;
    TRISC = 0x7B;
    TRISD = 0xBF;
    TRISE = 0xF;
    TRISF = 0x4B;

    /**
    ANSELx registers
    */
    ANSELA = 0x8E;
    ANSELB = 0xCB;
    ANSELC = 0x1B;
    ANSELD = 0xFF;
    ANSELE = 0x7;
    ANSELF = 0x4F;

    /**
    WPUx registers
    */
    WPUA = 0x1;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
    WPUF = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;
    INLVLF = 0xFF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */
    CLCIN0PPS = 0x38; //RW0->CLC3:CLCIN0;
    CLCIN2PPS = 0x3A; //RW2->CLC7:CLCIN2;
    CLCIN1PPS = 0x39; //RW1->CLC6:CLCIN1;
    SPI1SDIPPS = 0x15; //RC5->SPI1:SDI1;
    U2RXPPS = 0xD; //RB5->UART2:RX2;
    RD6PPS = 0x03;  //RD6->CLC3:CLC3;
    RC2PPS = 0x1E;  //RC2->SPI1:SDO1;
    RB0PPS = 0x11;  //RB0->PWM2_16BIT:PWM21;
    RF2PPS = 0x0F;  //RF2->PWM1_16BIT:PWM11;
    RB4PPS = 0x18;  //RB4->UART2:TX2;
    SPI1SCKPPS = 0x16;  //RC6->SPI1:SCK1;
    RC6PPS = 0x1D;  //RC6->SPI1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x1;
    IOCAN = 0x1;
    IOCAF = 0x0;
    IOCWP = 0x0;
    IOCWN = 0x0;
    IOCWF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    BUTTON_SetInterruptHandler(BUTTON_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin BUTTON
    if(IOCAFbits.IOCAF0 == 1)
    {
        BUTTON_ISR();  
    }
}
   
/**
   BUTTON Interrupt Service Routine
*/
void BUTTON_ISR(void) {

    // Add custom BUTTON code

    // Call the interrupt handler for the callback registered at runtime
    if(BUTTON_InterruptHandler)
    {
        BUTTON_InterruptHandler();
    }
    IOCAFbits.IOCAF0 = 0;
}

/**
  Allows selecting an interrupt handler for BUTTON at application runtime
*/
void BUTTON_SetInterruptHandler(void (* InterruptHandler)(void)){
    BUTTON_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for BUTTON
*/
void BUTTON_DefaultInterruptHandler(void){
    // add your BUTTON interrupt custom code
    // or set custom function using BUTTON_SetInterruptHandler()
}
/**
 End of File
*/