/*
 * keypad_driver.c
 *
 * Created: 8/28/2023 5:04:49 PM
 *  Author: Mina Waguih
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "keypad_driver.h"
#include "../LIB/common_macros.h"
#include "../MCAL/gpio.h"
#include "../LIB/std_types.h"


void KEYPAD_voidInit(void)
{
	GPIO_setupPortDirection(KEYPAD_ROW_PORT,0x00);
	GPIO_writePort(KEYPAD_ROW_PORT,0x0F);     //to use the pull up
	
	GPIO_setupPortDirection(KEYPAD_COL_PORT,0xF0);
	GPIO_writePort(KEYPAD_COL_PORT,0xFF);      //0x0F doesn't matter
}


u8 KEYPAD_u8GetPressedKey(void)
{
	u8 u8RowLocal = 0;
	u8 u8ColLocal = 0;
	
	u8 KPD_u8RowPinArr[KEYPAD_NUM_ROWS] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 KPD_u8ColPinArr[KEYPAD_NUM_COLS] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	
	
	for (u8ColLocal=0; u8ColLocal<KEYPAD_NUM_COLS; u8ColLocal++)
	{
		GPIO_writePin(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],LOGIC_LOW);
		for (u8RowLocal=0; u8RowLocal<KEYPAD_NUM_ROWS; u8RowLocal++)
		{
			u8 u8Value = GPIO_readPin(KEYPAD_ROW_PORT,KPD_u8RowPinArr[u8RowLocal]);
			
			if (u8Value == KEYPAD_BUTTON_PRESSED)
			{
				_delay_ms(30);       //for debouncing
				if (u8Value == KEYPAD_BUTTON_PRESSED)
				{
					while (u8Value == KEYPAD_BUTTON_PRESSED)
					{
						u8Value = GPIO_readPin(KEYPAD_ROW_PORT,KPD_u8RowPinArr[u8RowLocal]);
					}
					u8 KPD_u8Value[KEYPAD_NUM_ROWS][KEYPAD_NUM_COLS] = KEYPAD_VALUES;
					return KPD_u8Value[u8RowLocal][u8ColLocal];
				}
			} 
			else
			{
			}
		}
		GPIO_writePin(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],LOGIC_HIGH);
	}
	
	return KEYPAD_BUTTON_RELEASED;
		
}
