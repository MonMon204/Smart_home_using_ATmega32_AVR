/*
 * Final project.c
 *
 * Created: 9/9/2023 8:31:24 AM
 * Author : team3: Mina Waguih | 
 */ 

#define F_CPU 8000000UL

#include "functions.h"


int main(void)
{
	system_init();	
	
    while (1) 
    {
		check_password();
		LCD_voidClearScreen();
		system_on();
    }
}


