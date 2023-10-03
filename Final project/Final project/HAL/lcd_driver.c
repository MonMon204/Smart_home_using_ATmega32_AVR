/*
 * lcd_driver.c
 *
 * Created: 8/28/2023 3:14:08 PM
 *  Author: Mina Waguih
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd_driver.h"
#include "../MCAL/gpio.h"
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"


u8* itoa(s32 num, u8* str, s32 base) {
	s32 i = 0;
	s32 isNegative = 0;

	// Handle 0 explicitly
	if (num == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// Handle negative numbers
	if (num < 0 && base == 10) {
		isNegative = 1;
		num = -num;
	}

	// Convert the number to string in reverse order
	while (num != 0) {
		s32 rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}

	// If the number is negative, append '-'
	if (isNegative)
	str[i++] = '-';

	// Append the null terminator
	str[i] = '\0';

	// Reverse the string
	s32 start = 0;
	s32 end = i - 1;
	while (start < end) {
		s8 temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return str;
}


void LCD_voidInit()
{
	_delay_ms(32);
	LCD_voidSendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);   //0b00111000    0x38
	LCD_voidSendCommand(LCD_CURSOR_OFF);                  //0b00001100    0x0C
	LCD_voidSendCommand(LCD_CLEAR_COMMAND);               //0b00000001    0x01
}


void LCD_voidSendCommand(u8 u8Command)
{
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_RS_PIN,LOGIC_LOW);
	
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_RW_PIN,LOGIC_LOW);
	
	GPIO_setupPortDirection(LCD_DATA_PORT,0xFF);
	GPIO_writePort(LCD_DATA_PORT,u8Command);
	
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_E_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_LOW);
	
}


void LCD_voidSendData(u8 u8Data)
{
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_RS_PIN,LOGIC_HIGH);
	
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_RW_PIN,LOGIC_LOW);
	
	GPIO_setupPortDirection(LCD_DATA_PORT,0xFF);
	GPIO_writePort(LCD_DATA_PORT,u8Data);
	
	GPIO_setupPinDirection(LCD_CTRL_PORT,LCD_E_PIN,OUTPUT);
	GPIO_writePin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_HIGH);
	_delay_ms(2);
	GPIO_writePin(LCD_CTRL_PORT,LCD_E_PIN,LOGIC_LOW);
}


void LCD_voidSendString(const u8 *Str)
{
	u8 i=0;
	while(Str[i] != '\0')
	{
		LCD_voidSendData(Str[i]);
		i++;
	}
}


void LCD_moveCursor(u8 row,u8 col)
{
	u8 address=LCD_SET_CURSOR_LOCATION;
	switch(row)
	{
		case 0: address+=col; break;
		case 1: address+=col+0x40; break;
	}
	LCD_voidSendCommand(address);
}


void LCD_voidIntgerToString(u32 data)
{
	u8 buff[16];
	itoa(data,buff,10);
	LCD_voidSendString(buff);
}


void LCD_voidClearScreen()
{
	LCD_voidSendCommand(LCD_CLEAR_COMMAND);
}




