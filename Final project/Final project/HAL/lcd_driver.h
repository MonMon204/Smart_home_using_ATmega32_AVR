/*
 * lcd_driver.h
 *
 * Created: 8/28/2023 3:14:29 PM
 *  Author: Mina Waguih
 */ 

#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H

#include <avr/io.h>
#include "lcd_driver.h"
#include "../MCAL/gpio.h"
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"


#define LCD_CTRL_PORT        PORTB_ID
#define LCD_DATA_PORT        PORTD_ID

#define LCD_RS_PIN           PIN6_ID
#define LCD_RW_PIN           PIN5_ID
#define LCD_E_PIN            PIN4_ID


// LCD commands
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


// Function prototypes
void LCD_voidInit(void);

void LCD_voidSendCommand(u8 u8Command);

void LCD_voidSendData(u8 u8Data);

void LCD_voidSendString(const u8 *Str);

void LCD_moveCursor(u8 row,u8 col);

void LCD_voidIntgerToString(u32 data);

void LCD_voidClearScreen(void);



#endif
