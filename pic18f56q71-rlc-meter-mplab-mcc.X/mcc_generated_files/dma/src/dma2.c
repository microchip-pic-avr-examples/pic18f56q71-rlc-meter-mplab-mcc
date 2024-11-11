/**
 * DMA2 Generated Driver File.
 * 
 * @file dma2.c
 * 
 * @ingroup  dma2
 * 
 * @brief This file contains the API implementations for the DMA2 driver.
 *
 * @version DMA2 Driver Version 2.12.1
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

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../dma2.h"

void (*DMA2_SCNTI_InterruptHandler)(void);

void (*DMA2_AI_InterruptHandler)(void);

void (*DMA2_ORI_InterruptHandler)(void);

/**
 * @ingroup dma2
 * @brief Default interrupt handler for all interrupt events.
 * @param None.
 * @return None.
 */
void DMA2_DefaultInterruptHandler(void);

/**
  Section: DMA2 APIs
*/

void DMA2_Initialize(void)
{   
    
    //DMA Instance Selection : 0x1
    DMASELECT = 0x1;
    //Source Address : 0x001000
    DMAnSSA = 0x001000;
    //Destination Address : (uint16_t) &PWM2S1P1L
    DMAnDSA = (uint16_t) &PWM2S1P1L;
    //SSTP not cleared; SMODE incremented; SMR Program Flash; DSTP not cleared; DMODE unchanged; 
    DMAnCON1 = 0xA;
    //Source Message Size : 250
    DMAnSSZ = 250;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ CLC1; 
    DMAnSIRQ = 0x5;
    //Abort Trigger : AIRQ Software Interrupt; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR6bits.DMA2DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR6bits.DMA2SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR6bits.DMA2AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR6bits.DMA2ORIF =0; 
    
    PIE6bits.DMA2DCNTIE = 0;
    PIE6bits.DMA2SCNTIE = 1; 
	DMA2_SCNTIInterruptHandlerSet(DMA2_DefaultInterruptHandler);
    PIE6bits.DMA2AIE = 1; 
	DMA2_AIInterruptHandlerSet(DMA2_DefaultInterruptHandler);
    PIE6bits.DMA2ORIE =1; 
	DMA2_ORIInterruptHandlerSet(DMA2_DefaultInterruptHandler);
	
    //AIRQEN disabled; DGO not in progress; SIRQEN enabled; EN enabled; 
    DMAnCON0 = 0xC0;
	 
}

void DMA2_Enable(void)
{
    DMASELECT = 0x1;
    DMAnCON0bits.EN = 0x1;
}

void DMA2_Disable(void)
{
    DMASELECT = 0x1;
    DMAnCON0bits.EN = 0x0;
}

void DMA2_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x1;
	DMAnCON1bits.SMR  = region;
}

void DMA2_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x1;
	DMAnSSA = address;
}

uint24_t DMA2_SourceAddressGet(void)
{
    DMASELECT = 0x1;
    return DMAnSSA;
}

void DMA2_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x1;
	DMAnDSA = address;
}

uint16_t DMA2_DestinationAddressGet(void)
{
    DMASELECT = 0x1;
    return DMAnDSA;
}

void DMA2_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x1;
	DMAnSSZ= size;
}

uint16_t DMA2_SourceSizeGet(void)
{
    DMASELECT = 0x1;
    return DMAnSSZ;
}

void DMA2_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x1;
	DMAnDSZ= size;
}

uint16_t DMA2_DestinationSizeGet(void)
{                     
    DMASELECT = 0x1;
    return DMAnDSZ;
}

uint24_t DMA2_SourcePointerGet(void)
{
    DMASELECT = 0x1;
	return DMAnSPTR;
}

uint16_t DMA2_DestinationPointerGet(void)
{
    DMASELECT = 0x1;
	return DMAnDPTR;
}

uint16_t DMA2_SourceCountGet(void)
{
    DMASELECT = 0x1;
    return DMAnSCNT;
}

uint16_t DMA2_DestinationCountGet(void)
{                     
    DMASELECT = 0x1;
    return DMAnDCNT;
}

void DMA2_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x1;
	DMAnSIRQ = sirq;
}

void DMA2_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x1;
	DMAnAIRQ = airq;
}

void DMA2_TransferStart(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.DGO = 1;
}

void DMA2_TransferWithTriggerStart(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA2_TransferStop(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA2_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA2PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

void DMA2_DMASCNTI_ISR(void)
{
    // Clear the source count interrupt flag
    PIR6bits.DMA2SCNTIF = 0;

    if (DMA2_SCNTI_InterruptHandler)
            DMA2_SCNTI_InterruptHandler();
}

void DMA2_SCNTIInterruptHandlerSet(void (* InterruptHandler)(void))
{
	 DMA2_SCNTI_InterruptHandler = InterruptHandler;
}

void DMA2_DMAAI_ISR(void)
{
    // Clear the source count interrupt flag
    PIR6bits.DMA2AIF = 0;

    if (DMA2_AI_InterruptHandler)
            DMA2_AI_InterruptHandler();
}

void DMA2_AIInterruptHandlerSet(void (* InterruptHandler)(void))
{
	 DMA2_AI_InterruptHandler = InterruptHandler;
}

void DMA2_DMAORI_ISR(void)
{
    // Clear the source count interrupt flag
    PIR6bits.DMA2ORIF = 0;

    if (DMA2_ORI_InterruptHandler)
            DMA2_ORI_InterruptHandler();
}

void DMA2_ORIInterruptHandlerSet(void (* InterruptHandler)(void))
{
	 DMA2_ORI_InterruptHandler = InterruptHandler;
}

void DMA2_DefaultInterruptHandler(void){
    // add your DMA2 interrupt custom code
    // or set custom function using DMA2_SCNTIInterruptHandlerSet() /DMA2_DCNTIInterruptHandlerSet() /DMA2_AIInterruptHandlerSet() /DMA2_ORIInterruptHandlerSet()
}
/**
 End of File
*/
