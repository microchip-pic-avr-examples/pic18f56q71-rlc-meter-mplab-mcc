/*
 * File:   mcp6s26.c
 * Author: M75512
 *
 * Created on September 18, 2024, 4:25 PM
 */


#include "mcp6s26.h"
#include "mcc_generated_files/system/system.h"

void MCP6S26_Write_Command(uint8_t command, uint8_t data)
{
    uint8_t command_data[2];
    command_data[0] = command;
    command_data[1] = data;
    
    if (!SPI1_Open(HOST_CONFIG)) {
		return;
	}
    
    RLC_CS_SetLow();
    
    SPI1_BufferExchange(command_data, 2);
    
    SPI1_Close();
    
    RLC_CS_SetHigh();
}

void MCP6S26_Write_Double_Command(uint8_t command, uint8_t data_client1, uint8_t data_client2)
{
    uint8_t command_data[4];
    command_data[0] = command;
    command_data[1] = data_client2;
    command_data[2] = command;
    command_data[3] = data_client1;
    
    if (!SPI1_Open(HOST_CONFIG)) {
		return;
	}
    
    RLC_CS_SetLow();
    
    SPI1_BufferExchange(command_data, 4);
    
    SPI1_Close();
    
    RLC_CS_SetHigh();
}

