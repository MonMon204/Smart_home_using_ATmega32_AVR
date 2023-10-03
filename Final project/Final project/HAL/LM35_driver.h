/*
 * LM35_driver.h
 *
 * Created: 9/10/2023 11:26:14 PM
 *  Author: Mina Waguih
 */ 

#ifndef LM35_DRIVER_H
#define LM35_DRIVER_H

#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"

#define ADC_NUM        0 

f32 Read_LM35_f32(void);

#endif