/*
 * motor_driver.h
 *
 * Created: 9/11/2023 12:43:15 PM
 *  Author: Mina Waguih
 */ 

#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"
#include "../MCAL/gpio.h"
#include "../MCAL/pwm.h"


#define MOTOR_IN_PORT   PORTA_ID
#define MOTOR_IN_1      PIN5_ID
#define MOTOR_IN_2      PIN6_ID
#define MOTOR_EN        TIMER_0


void motor_init(void);

void motor_start(void);

void motor_stop(void);

void motor_set_speed(u8 speed);



#endif
