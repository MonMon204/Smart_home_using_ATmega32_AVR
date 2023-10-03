/*
 * functions.c
 *
 * Created: 9/11/2023 10:57:09 AM
 *  Author: Mina Waguih
 */ 

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include "./HAL/keypad_driver.h"
#include "./HAL/lcd_driver.h"
#include "./MCAL/adc.h"
#include "./HAL/LM35_driver.h"
#include "functions.h"


u8 password[] = "1234";
u8 entered_password[8];
u8 running = 0;
u8 password_trials = 0;


void system_init(void)
{
	LCD_voidInit();
	KEYPAD_voidInit();
	ADC_init();
	motor_init();
}


void check_password(void)
{
	LCD_voidClearScreen();
	LCD_voidSendString("Please Enter");
	LCD_moveCursor(1,0);
	LCD_voidSendString("Password:");
	while(running == 0)
	{
		u8 i = 0;
		while (1)
		{
			u8 c = KEYPAD_u8GetPressedKey();
			if (c == 'c')
			{
				break;
			}
			else if (c != KEYPAD_BUTTON_RELEASED)
			{
				entered_password[i++] = c;
				LCD_voidSendData('*');
			}
		}
		if (check_two_string_equal(entered_password,password) == 1)
		{
			LCD_voidClearScreen();
			LCD_voidSendString("Welcome Ahmed !!");
			_delay_ms(2000);
			LCD_voidClearScreen();
			running = 1;
			return;
		}
		else
		{
			password_trials++;
			empty_string(entered_password, 8);
			LCD_voidClearScreen();
			LCD_voidSendString("Wrong Password");
			LCD_moveCursor(1,0);
			LCD_voidSendString("Please Try again");
			_delay_ms(1000);
			if (password_trials == 3)
			{
				wait_two_mins();
			}
			running = 0;
			check_password();
		}
	}
}


void empty_string(u8* str, u8 str_len)
{
	for (u8 i=0; i<str_len; i++)
	{
		str[i] = '\0';
	}
}

u8 check_two_string_equal(u8* str1, u8* str2)      //return 1 if equal and 0 if not 
{
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	} 
	else
	{
		for (u8 i=0; i<strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				return 0;
			}
		}
		return 1;
	}
}



void wait_two_mins(void){
	password_trials = 0;
	u8 sec = 120;
	u8 min = sec/60;
	LCD_voidClearScreen();
	LCD_voidSendString("System Off for:");
	LCD_moveCursor(1,2);
	LCD_voidSendData(':');
	while(sec != 0)
	{
		u8 min = sec/60;
		LCD_moveCursor(1,0);
		LCD_voidIntgerToString(0);
		LCD_voidIntgerToString(min);
		LCD_voidSendData(':');
		if ((sec - min*60)/10>0)
		{
			LCD_voidIntgerToString(sec - min*60);
		}
		else
		{
			LCD_voidIntgerToString(0);
			LCD_voidIntgerToString(sec - min*60);
		}
		_delay_ms(1000);
		sec--;
	}
	
}

void led_on_off(void)
{
	u8 c = KEYPAD_u8GetPressedKey();
	if (c == '1')
	{
		LED_ON(PORTB_ID,PIN7_ID);
	}
	else if(c == '2')
	{
		LED_OFF(PORTB_ID,PIN7_ID);
	}
}


void system_on(void)
{
	LCD_voidClearScreen();
	LCD_voidSendString("System ON");
	_delay_ms(1000);
	LCD_voidClearScreen();
	LCD_voidSendString("1- Leds ON");
	LCD_moveCursor(1,0);
	LCD_voidSendString("2- Leds OFF");
	while(running == 1)
	{
		led_on_off();
		u32 temperature = (u32)Read_LM35_f32();
		if (temperature>=30)
		{
			motor_start();
		}
		else if (temperature>25 & temperature<30)
		{
			motor_set_speed(50);
		}
		else if (temperature<=25)
		{
			motor_stop();
		}
	}
}