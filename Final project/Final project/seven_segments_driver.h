/*
 * seven_segments_driver.h
 *
 * Created: 8/19/2023 8:06:09 PM
 *  Author: Mina Waguih
 */ 

#ifndef SEVEN_SEGMENTS_DRIVER_H
#define SEVEN_SEGMENTS_DRIVER_H


#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include "gpio.h"
#include "std_types.h"

void SevenSegmentConfig(u8 port_num, u8 type);
void Display_Seven_Segment(u8 port_num, u8 number_to_display);
void Display_Zero(u8 port_num);
void Display_One(u8 port_num);
void Display_Two(u8 port_num);
void Display_Three(u8 port_num);
void Display_Four(u8 port_num);
void Display_Five(u8 port_num);
void Display_Six(u8 port_num);
void Display_Seven(u8 port_num);
void Display_Eight(u8 port_num);
void Display_Nine(u8 port_num);
void Display_Dot(u8 port_num);
void Turn_Off_Dot(u8 port_num);
void Turn_Off_Seven_Segment(u8 port_num);
void Turn_On_Seven_Segment(u8 port_num);
void Blink_Seven_Segment(u8 port_num, u8 number_of_blinks);


#endif