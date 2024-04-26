/**
 * OPA2 Generated Driver File
 * 
 * @file opa2.c
 * 
 * @ingroup  opa2
 * 
 * @brief This is the generated driver implementation file for the OPA2 driver.
 *
 * @version OPA2 Driver Version 1.0.0
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

/**
   Section: Included Files
*/

#include <xc.h>
#include "../opa2.h"

/**
  Section: OPA2 Module APIs
*/

void OPA2_Initialize(void)
{
    //GSEL R1 = 8R and R2 = 8R, R2/R1 = 1; RESON Enabled; NSS OPA2IN0-; 
    OPA2CON1 = 0x38;

    //NCH GSEL; PCH OPA2IN+; 
    OPA2CON2 = 0x12;

    //FMS OPA2OUT; INTOE Disabled; PSS OPA2IN2+; 
    OPA2CON3 = 0x82;

    //PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    OPA2CON4 = 0x0;

    //OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    OPA2HWC = 0x0;

    //ORS OPAxORPPS; 
    OPA2ORS = 0x0;

    //EN Enabled; CPON Enabled; UG OPAIN- pin; 
    OPA2CON0 = 0xA0;
}

inline void OPA2_EnableChargePump(void)
{
    OPA2CON0bits.CPON = 1;
}
 
inline void OPA2_DisableChargePump(void)
{
    OPA2CON0bits.CPON = 0;
}

inline void OPA2_EnableSoftwareUnityGain(void)
{
    OPA2CON0bits.UG = 1;
}

inline void OPA2_DisableSoftwareUnityGain(void)
{
    OPA2CON0bits.UG = 0;
}

inline void OPA2_SetPositiveChannel(OPA2_posChannel_select posChannel)
{
    OPA2CON2bits.PCH = posChannel;
}

inline void OPA2_SetPositiveSource(OPA2_posSource_select posSource)
{
    OPA2CON3bits.PSS = posSource;
}

inline void OPA2_SetNegativeChannel(OPA2_negChannel_select negChannel)
{
    OPA2CON2bits.NCH = negChannel;
}

inline void OPA2_SetNegativeSource(OPA2_negSource_select negSource)
{
    OPA2CON1bits.NSS = negSource;
}

void OPA2_SetResistorLadder(OPA2_resistor_select resistorSelection)
{
    OPA2CON1bits.RESON = 1;
    OPA2CON1bits.GSEL = resistorSelection;
}

inline void OPA2_EnableHardwareOverride(void)
{
   OPA2HWCbits.OREN = 1;
}

void OPA2_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity)
{
    OPA2ORS = overrideSource;
    OPA2HWCbits.ORPOL = polarity;
}

inline void OPA2_DisableHardwareOverride(void)
{
    OPA2HWCbits.OREN = 0;
}

inline void OPA2_ManualInputOffsetCalibration(uint8_t offset)
{
    OPA2OFFSET = offset;
}

void OPA2_StartAutomaticOffsetCalibration(void)
{
	OPA2CON4bits.OFCSEL = 2;
    OPA2CON4bits.OFCST = 1;
}

inline bool OPA2_isAutomaticOffsetCalibrationDone(void)
{
    return (OPA2CON4bits.OFCST);
}

inline void OPA2_StartPeakTroughReset(void)
{
    OPA2CON4bits.PTRES = 1;
}

inline void OPA2_StopPeakTroughReset(void)
{
    OPA2CON4bits.PTRES = 0;
}