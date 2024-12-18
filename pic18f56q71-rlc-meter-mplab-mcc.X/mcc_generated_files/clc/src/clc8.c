/**
 * CLC8 Generated Driver File.
 * 
 * @file clc8.c
 * 
 * @ingroup  clc8
 * 
 * @brief This file contains the API implementations for the CLC8 driver.
 *
 * @version CLC8 Driver Version 1.2.0
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


#include <xc.h>
#include "../clc8.h"


static void (*CLC8_Callback)(void);
static void CLC8_DefaultCallback(void);

void CLC8_Initialize(void) 
{
    
    // SLCT 0x7; 
    CLCSELECT = 0x7;
    // LCG1POL not_inverted; LCG2POL not_inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLCnPOL = 0x0;
    // LCD1S TMR0; 
    CLCnSEL0 = 0x12;
    // LCD2S CLC8; 
    CLCnSEL1 = 0x2C;
    // LCD3S CLCIN0 (CLCIN0PPS); 
    CLCnSEL2 = 0x0;
    // LCD4S CLCIN0 (CLCIN0PPS); 
    CLCnSEL3 = 0x0;
    // LCG1D1N disabled; LCG1D1T enabled; LCG1D2N disabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLCnGLS0 = 0x2;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N enabled; LCG2D2T disabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLCnGLS1 = 0x4;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T disabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N enabled; LCG3D4T disabled; 
    CLCnGLS2 = 0x40;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLCnGLS3 = 0x0;
    // LCOUT 0x00; 
    CLCDATA = 0x0;
    // LCMODE 1-input D flip-flop with S and R; LCINTN disabled; LCINTP enabled; LCEN enabled; 
    CLCnCON = 0x94;

    //Set default callback for CLC8 interrupt Overflow.
    CLC8_CallbackRegister(CLC8_DefaultCallback);

    // Clear the CLC interrupt flag
    PIR10bits.CLC8IF = 0;
}

void CLC8_Enable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.EN = 1;
}

void CLC8_Disable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.EN = 0;
}

void CLC8_RisingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.INTP = 1;
}

void CLC8_RisingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.INTP = 0;
}

void CLC8_FallingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.INTN = 1;
}

void CLC8_FallingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 7;
    CLCnCONbits.INTN = 0;
}

void CLC8_CallbackRegister(void (* CallbackHandler)(void))
{
    CLC8_Callback = CallbackHandler;
}

static void CLC8_DefaultCallback(void)
{
    //Add your interrupt code here or
    //Use CLC8_CallbackRegister function to use Custom ISR
}

void CLC8_Tasks(void)
{
    if(PIR10bits.CLC8IF == 1)
    {
        if(CLC8_Callback != NULL)
        {
            CLC8_Callback();
        }
        PIR10bits.CLC8IF = 0;
    }
}


bool CLC8_OutputStatusGet(void) 
{
    return(CLCDATAbits.CLC8OUT);
}
/**
 End of File
*/
