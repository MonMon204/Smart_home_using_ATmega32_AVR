/*
 * motor_driver.c
 *
 * Created: 9/11/2023 12:42:58 PM
 *  Author: Mina Waguih
 */ 


#include "motor_driver.h"
#include <util/delay.h>


void motor_init(void)
{
	GPIO_setupPinDirection(MOTOR_IN_PORT,MOTOR_IN_1,OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN_PORT,MOTOR_IN_2,OUTPUT);
	
	PWM_init(MOTOR_EN);
	
}


void motor_start(void)
{
	PWM_SetDutyCycle(100, MOTOR_EN);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_1,1);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_2,0);
	
}

void motor_stop(void)
{
	PWM_SetDutyCycle(0, MOTOR_EN);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_1,0);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_2,0);
	
}

void motor_set_speed(u8 speed)
{
	PWM_SetDutyCycle(speed,MOTOR_EN);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_1,1);
	GPIO_writePin(MOTOR_IN_PORT,MOTOR_IN_2,0);
}
