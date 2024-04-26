/* 
 * File:   rlc.h
 * Author: M91266
 *
 * Created on March 21, 2024, 4:55 PM
 */

#ifndef RLC_H
#define	RLC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define EnableWaveformGenerator()      do { LATWbits.LATW2 = 1; } while(0)
#define DisableWaveformGenerator()     do { LATWbits.LATW2 = 0; } while(0)

#define EnableADCTrigger()              do { LATWbits.LATW1 = 1; } while(0)
#define DisableADCTrigger()             do { LATWbits.LATW1 = 0; } while(0)

#define EnableClock()                   do { LATWbits.LATW0 = 1; } while(0)
#define DisableClock()                  do { LATWbits.LATW0 = 0; } while(0)

#define SelectPhase(x)                  do { LATW = ((PORTW & 0x0F)|(0x10 << (x))); } while(0)

#define SelectCurrent()                 do { OPA2CON3bits.PSS = OPA2_RB3_IN2_pos;} while(0)          //OPA2_IN+ RB3
#define SelectVoltage()                 do { OPA2CON3bits.PSS = OPA2_RB2_IN3_pos;} while(0)          //OPA2_IN+ RB2

#define GainSet(x)                      do { OPA1CON1bits.GSEL = x; OPA2CON1bits.GSEL = x;} while(0)   

#define PI             3.141592654

#define FREQ            1000UL    
#define WAVE_STEPS      250

#define TIMER0_PERIOD    ((_XTAL_FREQ / (16 * WAVE_STEPS * FREQ)) - 1)

/*
 * TIMESAMPLING_RATE 
 * 
 *    Select the timesampling to ensure that ADC aquiring frequency is lower that 70 kHz
 *    The aquiring rate is computed as 
 *       FREQ * WAVE_STEPS / TIMESAMPLING_RATE
 * 
 *    TIMESAMPLING_RATE accepted values 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25
 * 
 */    
#define TIMESAMPLING_RATE       17
        
#define V_REAL_MAX              88000000.0       
#define V_IMAG_MAX              193000000.0
#define I_REAL_MAX              88000.0
#define I_IMAG_MAX              193000.0
#define V_REAL_MIN              17600000.0  // 20%MAX
#define V_IMAG_MIN              38600000.0
#define I_REAL_MIN              17600.0
#define I_IMAG_MIN              38600.0

#if WAVE_STEPS == 250

const uint16_t wave_ROM_250[] __at(0x001000) =
{
    512, 517, 522, 526, 531, 536, 541, 546, 550, 555, 560, 564, 569, 574, 578, 583, 
    587, 592, 596, 600, 604, 609, 613, 617, 621, 625, 629, 633, 636, 640, 643, 647, 
    650, 654, 657, 660, 663, 666, 669, 671, 674, 677, 679, 681, 684, 686, 688, 690, 
    691, 693, 695, 696, 697, 699, 700, 701, 701, 702, 703, 703, 704, 704, 704, 704, 
    704, 704, 703, 703, 702, 701, 701, 700, 699, 697, 696, 695, 693, 691, 690, 688, 
    686, 684, 681, 679, 677, 674, 671, 669, 666, 663, 660, 657, 654, 650, 647, 643, 
    640, 636, 633, 629, 625, 621, 617, 613, 609, 604, 600, 596, 592, 587, 583, 578, 
    574, 569, 564, 560, 555, 550, 546, 541, 536, 531, 526, 522, 517, 512, 507, 502, 
    498, 493, 488, 483, 478, 474, 469, 464, 460, 455, 450, 446, 441, 437, 432, 428, 
    424, 420, 415, 411, 407, 403, 399, 395, 391, 388, 384, 381, 377, 374, 370, 367, 
    364, 361, 358, 355, 353, 350, 347, 345, 343, 340, 338, 336, 334, 333, 331, 329, 
    328, 327, 325, 324, 323, 323, 322, 321, 321, 320, 320, 320, 320, 320, 320, 321, 
    321, 322, 323, 323, 324, 325, 327, 328, 329, 331, 333, 334, 336, 338, 340, 343, 
    345, 347, 350, 353, 355, 358, 361, 364, 367, 370, 374, 377, 381, 384, 388, 391, 
    395, 399, 403, 407, 411, 415, 420, 424, 428, 432, 437, 441, 446, 450, 455, 460, 
    464, 469, 474, 478, 483, 488, 493, 498, 502, 507
};

#else
    #error "The supported number of steps is 250"
#endif

const float sinTable[63] =
{
    0.000000000000, 0.025130095443, 0.050244318180, 0.075326805528, 0.100361714851, 0.125333233564, 0.150225589121, 0.175023058975, 
    0.199709980514, 0.224270760949, 0.248689887165, 0.272951935517, 0.297041581577, 0.320943609807, 0.344642923175, 0.368124552685, 
    0.391373666837, 0.414375580993, 0.437115766651, 0.459579860621, 0.481753674102, 0.503623201636, 0.525174629961, 0.546394346734, 
    0.567268949127, 0.587785252292, 0.607930297695, 0.627691361291, 0.647055961569, 0.666011867434, 0.684547105929, 0.702649969799, 
    0.720309024888, 0.737513117358, 0.754251380736, 0.770513242776, 0.786288432137, 0.801566984871, 0.816339250717, 0.830595899196, 
    0.844327925502, 0.857526656194, 0.870183754670, 0.882291226435, 0.893841424151, 0.904827052466, 0.915241172621, 0.925077206834, 
    0.934328942457, 0.942990535893, 0.951056516295, 0.958521789017, 0.965381638833, 0.971631732915, 0.977268123568, 0.982287250729, 
    0.986685944208, 0.990461425697, 0.993611310520, 0.996133609143, 0.998026728428, 0.999289472641, 0.999921044204   
};

const float cosTable[63] =
{
    1.000000000000, 0.999684189283, 0.998736956606, 0.997158900261, 0.994951016981, 0.992114701314, 0.988651744738, 0.984564334529, 
    0.979855052384, 0.974526872787, 0.968583161129, 0.962027671586, 0.954864544747, 0.947098304995, 0.938733857654, 0.929776485888, 
    0.920231847366, 0.910105970685, 0.899405251566, 0.888136448814, 0.876306680044, 0.863923417193, 0.850994481795, 0.837528040042, 
    0.823532597628, 0.809016994375, 0.793990398648, 0.778462301567, 0.762442511011, 0.745941145424, 0.728968627421, 0.711535677209, 
    0.693653305813, 0.675332808121, 0.656585755753, 0.637423989749, 0.617859613090, 0.597904983058, 0.577572703422, 0.556875616488, 
    0.535826794979, 0.514439533782, 0.492727341548, 0.470703932165, 0.448383216090, 0.425779291565, 0.402906435714, 0.379779095522, 
    0.356411878713, 0.332819544523, 0.309016994375, 0.285019262470, 0.260841506290, 0.236498997024, 0.212007109922, 0.187381314586, 
    0.162637165195, 0.137790290685, 0.112856384873, 0.087851196551, 0.062790519529, 0.037690182670, 0.012566039883 
};

const float opaGainTable[] = {1.07, 1.14, 1.33, 2.0, 2.67, 4.0, 8.0, 16.0};

void processImpedanceValues(void);

float getZReal(void);
float getZImag(void);
float getVReal(void);
float getVImag(void);
float getIReal(void);
float getIImag(void);
float getzArg(void);
float getzMod(void);
void set_vGain(uint8_t index);
void set_iGain(uint8_t index);


#ifdef	__cplusplus
}
#endif

#endif	/* RLC_H */

