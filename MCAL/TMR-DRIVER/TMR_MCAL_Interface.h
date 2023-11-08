/*
 * TMR_MCAL_Interface.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TMR_DRIVER_TMR_MCAL_INTERFACE_H_
#define MCAL_TMR_DRIVER_TMR_MCAL_INTERFACE_H_



void TMR0_Init(void);
void TMR0_SetPreload(u8 preloadValue);
void TMR0_SetCTC(u8 CTCValue);
void TMR0_OV_SetCallBack(void (*pf)(void));
void TMR0_Comp_SetCallBack(void (*pf)(void));

void TMR0_GeneratePWM(u16 CompareMatchValue);

/* preScaler value*/
#define NO_CLOCK_SOURCE               0
#define NO_PRESCALING                 1
#define PRESCALER_8                   2
#define PRESCALER_64                  3
#define PRESCALER_256                 4
#define PRESCALER_1024                5
#define EXTRNAL_CLK_FALLING_EDGE      6
#define EXTRNAL_CLK_RISING_EDGE       7

#endif /* MCAL_TMR_DRIVER_TMR_MCAL_INTERFACE_H_ */
