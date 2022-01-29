#include "../LIB/STD_TYPES.h"

#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/SPI/SPI_interface.h"

uint8_t global_u8Arr[255];

void App_init(void)
{
	PORT_INIT();//PORT initialization
	UART_init();// UART initialization
	SPI_MASTinit();// SPI Slave initialization
}

void App_prog(void)
{
	/*Receive the data from the terminal*/
	UART_AsynchReceiveStr(&global_u8Arr);
	/*Send the datat sent to the other MCU*/
	SPI_TransmitStr(&global_u8Arr);
}
