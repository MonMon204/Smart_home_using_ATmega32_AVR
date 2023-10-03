 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Mina Waguih
 *
 *******************************************************************************/

#include "gpio.h"
#include "../LIB/common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use the IO Ports Registers */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(u8 port_num, u8 pin_num, u8 direction)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			if(direction == 1)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
		case 'B':
		case 'b':
			if(direction == 1)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
		case 'C':
		case 'c':
			if(direction == 1)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
		case 'D':
		case 'd':
			if(direction == 1)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(u8 port_num, u8 pin_num, u8 value)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			if(value == 1)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
		case 'B':
		case 'b':
			if(value == 1)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
		case 'C':
		case 'c':
			if(value == 1)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
		case 'D':
		case 'd':
			if(value == 1)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
u8 GPIO_readPin(u8 port_num, u8 pin_num)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	
	u8 pin_value = 0;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			pin_value = READ_BIT(PINA,pin_num);
			break;
			
		case PORTB_ID:
		case 'B':
		case 'b':
			pin_value = READ_BIT(PINB,pin_num);
			break;
			
		case PORTC_ID:
		case 'C':
		case 'c':
			pin_value = READ_BIT(PINC,pin_num);
			break;
			
		case PORTD_ID:
		case 'D':
		case 'd':
			pin_value = READ_BIT(PIND,pin_num);
			break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(u8 port_num,u8 direction)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			DDRA = direction;
			break;
		case PORTB_ID:
		case 'B':
		case 'b':
			DDRB = direction;
			break;
		case PORTC_ID:
		case 'C':
		case 'c':
			DDRC = direction;
			break;
		case PORTD_ID:
		case 'D':
		case 'd':
			DDRD = direction;
			break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(u8 port_num, u8 value)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			PORTA = value;
			break;
		case PORTB_ID:
		case 'B':
		case 'b':
			PORTB = value;
			break;
		case PORTC_ID:
		case 'C':
		case 'c':
			PORTC = value;
			break;
		case PORTD_ID:
		case 'D':
		case 'd':
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
u8 GPIO_readPort(u8 port_num)
{
	switch(port_num)
	{
		case 'A':
		case 'a':
			port_num = PORTA_ID;
			break;
		case 'B':
		case 'b':
			port_num = PORTB_ID;
			break;
		case 'C':
		case 'c':
			port_num = PORTC_ID;
			break;
		case 'D':
		case 'd':
			port_num = PORTD_ID;
			break;
	}
	u8 value = 0;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
		case 'A':
		case 'a':
			value = PINA;
			break;
		case PORTB_ID:
		case 'B':
		case 'b':
			value = PINB;
			break;
		case PORTC_ID:
		case 'C':
		case 'c':
			value = PINC;
			break;
		case PORTD_ID:
		case 'D':
		case 'd':
			value = PIND;
			break;
		}
	}

	return value;
}
