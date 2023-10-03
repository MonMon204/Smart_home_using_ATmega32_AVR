/*
 * LED_driver.c
 *
 * Created: 9/10/2023 3:50:18 PM
 *  Author: Mina Waguih
 */ 

#include "LED_driver.h"
#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"
#include "../MCAL/gpio.h"


void LED_ON(u8 port_num, u8 pin_num)
{
	GPIO_setupPinDirection(port_num, pin_num, OUTPUT);
	GPIO_writePin(port_num, pin_num, 1);
}


void LED_OFF(u8 port_num, u8 pin_num)
{
	GPIO_setupPinDirection(port_num, pin_num, OUTPUT);
	GPIO_writePin(port_num, pin_num, 0);
}
