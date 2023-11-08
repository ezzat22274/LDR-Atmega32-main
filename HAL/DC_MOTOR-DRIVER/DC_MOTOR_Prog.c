/*
 * DC_MOTOR_Prog.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Lenovo
 */

#include "../../LIB/STD_TYPES.h"
#include "DC_MOTOR_Interface.h"
#include "../../MCAL/TMR-DRIVER/TMR_MCAL_Interface.h"

void DC_MOTOR_StartMotor(u8 DutyCycle)
{
	if(DutyCycle == 0)
	{
		TMR0_Init();
		TMR0_GeneratePWM(0);
		return;
	}
	u16 value = 0;
	u8  temp;
	temp = 100 / DutyCycle;
	value = 255 / temp;
	TMR0_Init();
	TMR0_GeneratePWM(value);
}
void DC_MOTOR_StopMotor(void)
{
	TMR0_GeneratePWM(0);
}
