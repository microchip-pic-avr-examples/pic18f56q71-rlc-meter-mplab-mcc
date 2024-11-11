 /*
 * RLC File
 * 
 * @file rlc.c
 * 
 * @defgroup rlc
 * 
 * @brief This file contains the implementation of the RLC functions.
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
#include <xc.h>
#include "rlc.h"
#include "math.h"

extern int16_t voltageSampleArray[WAVE_STEPS];
extern int16_t currentSampleArray[WAVE_STEPS];

float vReal_Raw, vImag_Raw, iReal_Raw, iImag_Raw;
float vRealUnscaled, vImagUnscaled, iRealUnscaled, iImagUnscaled;

static float zReal_Raw, zImag_Raw, yReal_Raw, yImag_Raw;
static float zMod, zArg;
static float vGain, iGain;

float Get_Sin(uint8_t index)
{
    if (index >=   0 &&  index < 63 ) return sinTable[index];
    if (index >=  63 &&  index < 125 )  return (sinTable[125 - index]);
    if (index >= 125 &&  index < 188 ) return (-1.0 * sinTable[index - 125]);
    if (index >= 188 &&  index < 250 )  return (-1.0 * sinTable[250 - index]);
}

float Get_Cos(uint8_t index)
{
    if (index >= 0   &&  index < 63 ) return cosTable[index];
    if (index >= 63  &&  index < 125 )  return (-1.0 * cosTable[125 - index]);
    if (index >= 125 &&  index < 188 ) return (-1.0 * cosTable[index - 125]);
    if (index >= 188 &&  index < 250 )  return (cosTable[250 - index]);
}

void Process_Impedance_Values(void)
{ 
    uint16_t index = 0;
    
    vReal_Raw = 0.0;
    vImag_Raw = 0.0;
    iReal_Raw = 0.0;
    iImag_Raw = 0.0;

    for (uint16_t i = 0; i < WAVE_STEPS; i++)
    {
        index  = (i * timesamplingRates[TIMESAMPLING_RATE]) % WAVE_STEPS;
        vReal_Raw = vReal_Raw + (float)(voltageSampleArray[i] * 1.0) * (float)Get_Cos(index);
        vImag_Raw = vImag_Raw + (float)(voltageSampleArray[i] * 1.0) * (float)Get_Sin(index);
        iReal_Raw = iReal_Raw + (float)(currentSampleArray[i] * 1.0) * (float)Get_Cos(index);
        iImag_Raw = iImag_Raw + (float)(currentSampleArray[i] * 1.0) * (float)Get_Sin(index);
    }
    
    vRealUnscaled = vReal_Raw;
    vImagUnscaled = vImag_Raw;
    iRealUnscaled = iReal_Raw;
    iImagUnscaled = iImag_Raw;
   
    /* Scale by gain */     
    vReal_Raw = 1000.0 * vReal_Raw / vGain ;
    vImag_Raw = 1000.0 * vImag_Raw / vGain ;
    iReal_Raw = -1.0 * iReal_Raw / iGain ;
    iImag_Raw = -1.0 * iImag_Raw / iGain ;
     
    /* Impedance calculation, no compensation */
    zReal_Raw = (float)(vReal_Raw * iReal_Raw + vImag_Raw * iImag_Raw)/(float)(iReal_Raw * iReal_Raw + iImag_Raw * iImag_Raw);   
    zImag_Raw = (float)(vImag_Raw * iReal_Raw - vReal_Raw * iImag_Raw)/(float)(iReal_Raw * iReal_Raw + iImag_Raw * iImag_Raw);   
    
    zMod = sqrt(zReal_Raw * zReal_Raw + zImag_Raw * zImag_Raw);
    zArg = atan2(zImag_Raw, zReal_Raw);
}

float Get_ZReal(void)
{
    return zReal_Raw;
}

float Get_ZImag(void)
{
    return zImag_Raw;
}

float Get_VReal(void)
{
    return vReal_Raw;
}

float Get_VImag(void)
{
    return vImag_Raw;
}

float Get_IReal(void)
{
    return iReal_Raw;
}

float Get_IImag(void)
{
    return iImag_Raw;
}

float Get_ZArg(void)
{
    return zArg;
}

float Get_ZMod(void)
{
    return zMod;
}

float Get_VRealUnscaled(void)
{
    return vRealUnscaled;
}

float Get_VImagUnscaled(void)
{
    return vImagUnscaled;
}

float Get_IRealUnscaled(void)
{
    return iRealUnscaled;
}

float Get_IImagUnscaled(void)
{
    return iImagUnscaled;
}

float Get_Gain(uint8_t index)
{
    return opaGainTable[index];
}

void Set_VGain(uint8_t index)
{
    if (index > 7) vGain = 1.00;
    else vGain = opaGainTable[index];
}

void Set_IGain(uint8_t index)
{
    if (index > 7) iGain = 1.00;
    else iGain = opaGainTable[index];
}