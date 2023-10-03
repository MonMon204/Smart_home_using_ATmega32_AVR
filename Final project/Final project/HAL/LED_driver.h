/*
 * LED_driver.h
 *
 * Created: 9/10/2023 3:51:10 PM
 *  Author: Mina Waguih
 */ 

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"
#include "../MCAL/gpio.h"


void LED_ON(u8 port_num, u8 pin_num);

void LED_OFF(u8 port_num, u8 pin_num);


#endif


