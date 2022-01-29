#include "../LIB/STD_TYPES.h"

#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/UART/UART_interface.h"

uint8_t global_u8Read[255];//A global array which holds the string

void App_init(void)
{
	PORT_INIT();//Port initialization
	UART_init();// UART initialization
	SPI_SLVinit();// SPI initialization
}

void App_prog(void)
{
	/*Receive data and save it into the array*/
	SPI_ReceiveStr(&global_u8Read);
	/*Send the data to the terminal*/
	UART_AsynchSendStr(&global_u8Read);
	/*New line*/
	UART_AsynchSendStr("\r\n");
}
