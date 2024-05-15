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

#include <stdint.h>

#define FONT_WIDTH      0x08
#define FONT_HEIGHT     0x05

const uint8_t font_table[] = {
    // compact 5x8 font
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xE0, 0x00, //	'sp,!,"
    0x28, 0xFE, 0x28, 0xFE, 0x28,                                                             // #
    0x24, 0x54, 0xFE, 0x54, 0x48, 0xC4, 0xC8, 0x10, 0x26, 0x46, 0x6C, 0x92, 0x6A, 0x04, 0x0A, //	'$,%,&
    0x00, 0x10, 0xE0, 0xC0, 0x00, 0x00, 0x38, 0x44, 0x82, 0x00, 0x00, 0x82, 0x44, 0x38, 0x00, //	'',(,)
    0x54, 0x38, 0xFE, 0x38, 0x54, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00, 0x0E, 0x0C, 0x00, //	'*,+,,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x06, 0x06, 0x00, 0x04, 0x08, 0x10, 0x20, 0x40, //	'-,.,/
    0x7C, 0x8A, 0x92, 0xA2, 0x7C, 0x00, 0x42, 0xFE, 0x02, 0x00, 0x4E, 0x92, 0x92, 0x92, 0x62, //	'0,1,2
    0x84, 0x82, 0x92, 0xB2, 0xCC, 0x18, 0x28, 0x48, 0xFE, 0x08, 0xE4, 0xA2, 0xA2, 0xA2, 0x9C, //	'3,4,5
    0x3C, 0x52, 0x92, 0x92, 0x8C, 0x82, 0x84, 0x88, 0x90, 0xE0, 0x6C, 0x92, 0x92, 0x92, 0x6C, //	'6,7,8
    0x62, 0x92, 0x92, 0x94, 0x78, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x2C, 0x00, 0x00, //	'9,:,;
    0x00, 0x10, 0x28, 0x44, 0x82, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x82, 0x44, 0x28, 0x10, //	'<,=,>
    0x40, 0x80, 0x9A, 0x90, 0x60, 0x7C, 0x82, 0xBA, 0x9A, 0x72,                               //  '?,@
    0x3E, 0x48, 0x88, 0x48, 0x3E,                                                             //	'A
    0xFE, 0x92, 0x92, 0x92, 0x6C, 0x7C, 0x82, 0x82, 0x82, 0x44, 0xFE, 0x82, 0x82, 0x82, 0x7C, //	'B,C,D
    0xFE, 0x92, 0x92, 0x92, 0x82, 0xFE, 0x90, 0x90, 0x90, 0x80, 0x7C, 0x82, 0x82, 0x8A, 0xCE, //	'E,F,G
    0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00, 0x82, 0xFE, 0x82, 0x00, 0x04, 0x02, 0x82, 0xFC, 0x80, //	'H,I,J
    0xFE, 0x10, 0x28, 0x44, 0x82, 0xFE, 0x02, 0x02, 0x02, 0x02, 0xFE, 0x40, 0x38, 0x40, 0xFE, //	'K,L,M
    0xFE, 0x20, 0x10, 0x08, 0xFE, 0x7C, 0x82, 0x82, 0x82, 0x7C, 0xFE, 0x90, 0x90, 0x90, 0x60, //	'N,O,P
    0x7C, 0x82, 0x8A, 0x84, 0x7A, 0xFE, 0x90, 0x98, 0x94, 0x62, 0x64, 0x92, 0x92, 0x92, 0x4C, //	'Q,R,S
    0xC0, 0x80, 0xFE, 0x80, 0xC0, 0xFC, 0x02, 0x02, 0x02, 0xFC, 0xF8, 0x04, 0x02, 0x04, 0xF8, //	'T,U,V
    0xFC, 0x02, 0x1C, 0x02, 0xFC, 0xC6, 0x28, 0x10, 0x28, 0xC6, 0xC0, 0x20, 0x1E, 0x20, 0xC0, //	'W,X,Y
    0x86, 0x9A, 0x92, 0xB2, 0xC2,                                                             //  'Z
    0x00, 0xFE, 0x82, 0x82, 0x82, 0x40, 0x20, 0x10, 0x08, 0x04,                               //	'[,'\'
    0x00, 0x82, 0x82, 0x82, 0xFE, 0x20, 0x40, 0x80, 0x40, 0x20, 0x02, 0x02, 0x02, 0x02, 0x02, //	'],^,_
    0x00, 0xC0, 0xE0, 0x10, 0x00, 0x04, 0x2A, 0x2A, 0x1C, 0x02, 0xFE, 0x14, 0x22, 0x22, 0x1C, //	'`,a,b
    0x1C, 0x22, 0x22, 0x22, 0x14, 0x1C, 0x22, 0x22, 0x14, 0xFE, 0x1C, 0x2A, 0x2A, 0x2A, 0x18, //	'c,d,e
    0x00, 0x10, 0x7E, 0x90, 0x40, 0x30, 0x4A, 0x4A, 0x52, 0x3C, 0xFE, 0x10, 0x20, 0x20, 0x1E, //	'f,g,h
    0x00, 0x22, 0xBE, 0x02, 0x00, 0x04, 0x02, 0x02, 0xBC, 0x00, 0xFE, 0x08, 0x14, 0x22, 0x00, //	'i,j,k
    0x00, 0x82, 0xFE, 0x02, 0x00, 0x3E, 0x20, 0x1E, 0x20, 0x1E, 0x3E, 0x10, 0x20, 0x20, 0x1E, //	'l,m,n
    0x1C, 0x22, 0x22, 0x22, 0x1C, 0x3E, 0x18, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 0x18, 0x3E, //	'o,p,q
    0x3E, 0x10, 0x20, 0x20, 0x10, 0x12, 0x2A, 0x2A, 0x2A, 0x24, 0x20, 0x20, 0xFC, 0x22, 0x24, //	'r,s,t
    0x3C, 0x02, 0x02, 0x04, 0x3E, 0x38, 0x04, 0x02, 0x04, 0x38, 0x3C, 0x02, 0x0C, 0x02, 0x3C, //	'u,v,w
    0x22, 0x14, 0x08, 0x14, 0x22, 0x32, 0x0A, 0x0A, 0x0A, 0x3C, 0x22, 0x26, 0x2A, 0x32, 0x22, //	'x,y,z
    0x00, 0x10, 0x6C, 0x82, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x82, 0x6C, 0x10, 0x00, //	'{,|,}
    0x40, 0x80, 0x40, 0x20, 0x40                                                              //  '~
};