/*
 File: common_macros.h
 Author: Mina Waguih
 Created on: 19 august, 2023
 Description: it is a header file for all the common macros used in the AVR
*/

#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H


#define NULL ((void *)0)


//Set a certain bit in any register
#define SET_BIT(reg,bit) (reg|=(1<<bit))      

//Clear a certain bit in any register
#define CLEAR_BIT(reg,bit) (reg&=(~(1<<bit)))

//Toggle a certain bit in any register
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))

//Read a certain bit in any register
#define READ_BIT(reg,bit) ((reg>>bit)&1)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

#endif