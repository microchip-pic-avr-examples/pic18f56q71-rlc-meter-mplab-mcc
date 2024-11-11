/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MCP6S26_H
#define	MCP6S26_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    
    
#define MCP6S26_NOP_INS             (0x00)
#define MCP6S26_SHUTDOWN_INS        (0x20)
#define MCP6S26_WRITE_INS           (0x40)
    
#define MCP6S26_GAIN                (0x00)
#define MCP6S26_CH                  (0x01)
    
#define MCP6S26_GAIN_1X             (0x00)
#define MCP6S26_GAIN_2X             (0x01)
#define MCP6S26_GAIN_4X             (0x02)
#define MCP6S26_GAIN_5X             (0x03)
#define MCP6S26_GAIN_8X             (0x04)
#define MCP6S26_GAIN_10X            (0x05)
#define MCP6S26_GAIN_16X            (0x06)
#define MCP6S26_GAIN_32X            (0x07)
    
#define MCP6S26_MUX_CH0             (0x00)
#define MCP6S26_MUX_CH1             (0x01)
#define MCP6S26_MUX_CH2             (0x02)
#define MCP6S26_MUX_CH3             (0x03)
#define MCP6S26_MUX_CH4             (0x04)
#define MCP6S26_MUX_CH5             (0x05)

void MCP6S26_Write_Command(uint8_t command, uint8_t data);
void MCP6S26_Write_Double_Command(uint8_t command, uint8_t data_client1, uint8_t data_client2);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MCP6S26_H */

