#include <xc.h>
#include "rlc.h"
#include "math.h"


extern int16_t voltageSampleArray[WAVE_STEPS];
extern int16_t currentSampleArray[WAVE_STEPS];

float vReal_Raw, vImag_Raw, iReal_Raw, iImag_Raw;

static float zReal_Raw, zImag_Raw, yReal_Raw, yImag_Raw;
static float zMod, zArg;
static float vGain, iGain;

float getSin(uint8_t index)
{
    if (index >=   0 &&  index < 63 ) return sinTable[index];
    if (index >=  63 &&  index < 125 )  return (sinTable[125 - index]);
    if (index >= 125 &&  index < 188 ) return (-1.0 * sinTable[index - 125]);
    if (index >= 188 &&  index < 250 )  return (-1.0 * sinTable[250 - index]);
}

float getCos(uint8_t index)
{
    if (index >= 0   &&  index < 63 ) return cosTable[index];
    if (index >= 63  &&  index < 125 )  return (-1.0 * cosTable[125 - index]);
    if (index >= 125 &&  index < 188 ) return (-1.0 * cosTable[index - 125]);
    if (index >= 188 &&  index < 250 )  return ( cosTable[250 - index]);
    
}

void processImpedanceValues(void)
{
     vReal_Raw = 0;
     vImag_Raw = 0;
     iReal_Raw = 0;
     iImag_Raw = 0;
     
    for (uint8_t i = 0; i < WAVE_STEPS; i++)
    {
        uint16_t index;
        
        index  = (i * TIMESAMPLING_RATE) % WAVE_STEPS;
        vReal_Raw = vReal_Raw + (float)(voltageSampleArray[i] * 1.0) * (float)getCos(index);
        vImag_Raw = vImag_Raw + (float)(voltageSampleArray[i] * 1.0) * (float)getSin(index);
        iReal_Raw = iReal_Raw + (float)(currentSampleArray[i] * 1.0) * (float)getCos(index);
        iImag_Raw = iImag_Raw + (float)(currentSampleArray[i] * 1.0) * (float)getSin(index);
    }
   
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

float getZReal(void)
{
    return zReal_Raw;
}

float getZImag(void)
{
    return zImag_Raw;
}

float getVReal(void)
{
    return vReal_Raw;
}

float getVImag(void)
{
    return vImag_Raw;
}

float getIReal(void)
{
    return iReal_Raw;
}

float getIImag(void)
{
    return iImag_Raw;
}

float getzArg(void)
{
    return zArg;
}

float getzMod(void)
{
    return zMod;
}

void set_vGain(uint8_t index)
{
    if (index > 7) vGain = 1.00;
    else vGain = opaGainTable[index];

}

void set_iGain(uint8_t index)
{
    if (index > 7) iGain = 1.00;
    else iGain = opaGainTable[index];

}