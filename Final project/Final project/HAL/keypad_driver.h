/*
 * keypad_driver.h
 *
 * Created: 8/28/2023 5:05:03 PM
 *  Author: Mina Waguih
 */ 

#ifndef KEYPAD_DRIVER_H
#define KEYPAD_DRIVER_H


#include <avr/io.h>
#include "../LIB/common_macros.h"
#include "../MCAL/gpio.h"
#include "../LIB/std_types.h"


#define KEYPAD_NUM_COLS             4
#define KEYPAD_NUM_ROWS             4

#define KEYPAD_ROW_PORT             PORTC_ID
#define KEYPAD_R0_PIN               PIN0_ID
#define KEYPAD_R1_PIN               PIN1_ID
#define KEYPAD_R2_PIN               PIN2_ID
#define KEYPAD_R3_PIN               PIN3_ID

#define KEYPAD_COL_PORT             PORTC_ID
#define KEYPAD_C0_PIN               PIN4_ID
#define KEYPAD_C1_PIN               PIN5_ID
#define KEYPAD_C2_PIN               PIN6_ID
#define KEYPAD_C3_PIN               PIN7_ID


#define KEYPAD_VALUES    {{'7','8','9','/'},\
						  {'4','5','6','*'},\
						  {'1','2','3','-'},\
						  {'c','0','=','+'}}					 


#define KEYPAD_BUTTON_PRESSED       LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED      LOGIC_HIGH


// function prototypes

void KEYPAD_voidInit(void);

u8 KEYPAD_u8GetPressedKey(void);



#endif
