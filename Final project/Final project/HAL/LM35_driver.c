/*
 * LM35_driver.c
 *
 * Created: 9/10/2023 11:25:59 PM
 *  Author: Mina Waguih
 */ 

#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"
#include "../MCAL/adc.h"
#include "LM35_driver.h"

f32 Read_LM35_f32(void)
{
	f32 temp = ADC_readChannel(0) * 5.0 / 1023.0;
	return temp*100;
}
