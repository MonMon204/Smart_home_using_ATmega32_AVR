/*
 * functions.h
 *
 * Created: 9/11/2023 10:57:39 AM
 *  Author: Mina Waguih
 */ 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include "./HAL/keypad_driver.h"
#include "./HAL/lcd_driver.h"
#include "./MCAL/adc.h"
#include "./HAL/LM35_driver.h"


void system_init(void);


void check_password(void);

void empty_string(u8* str, u8 str_len);

u8 check_two_string_equal(u8* str1, u8* str2);

void wait_two_mins(void);

void led_on_off(void);

void system_on(void);





#endif
