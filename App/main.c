/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Lenovo
 */

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "../MCAL/DIO-DRIVER/DIO_MCAL_Interface.h"
#include "../MCAL/GIE-DRIVER/GIE_MCAL_Interface.h"
#include "../MCAL/EXTI-DRIVER/EXTI_MCAL_Interface.h"
#include "../MCAL/ADC-DRIVER/ADC_MCAL_Interface.h"
#include "../MCAL/TMR-DRIVER/TMR_MCAL_Interface.h"

#include "../HAL/LCD-DRIVER/LCD_HAL_Interface.h"
#include "../HAL/SEGMENT_DRIVER/SEG_HAL_Interface.h"
#include "../HAL/KPD_DRIVER/KPD_HAL_Interface.h"
#include "../HAL/LM_SENSOR-DIRVER/LM_HAL_Interface.h"
#include "../HAL/DC_MOTOR-DRIVER/DC_MOTOR_Interface.h"
#include "../HAL/STEPPER_MOTOR-DRIVER/STEP_HAL_Interface.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

void LedRight(void);
void LedLeft(void);
int main() {
	ADC_Init();
	LCD_Init();
	EXTI_Init();
	u16 adc_value = 0;
	while (1) {

		//pull up swtiches
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
		DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
		DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);

		//leds
		DIO_SetPortDirection(DIO_PORTC, DIO_OUTPUT);

		//Enable INT
		 EXTI_INT0ENABLE();
		 EXTI_INT1ENABLE();

		 //ISR
		 EXTI_INT0SetCallBack(&LedLeft);
		 EXTI_INT1SetCallBack(&LedRight);
		 //enable GIE
		 GIE_Enable();
		adc_value = ADC_GetResult(0);

		if (adc_value < 180) {

			DIO_SetPortValue(DIO_PORTC, DIO_PORT_HIGH);
		} else {
			DIO_SetPortValue(DIO_PORTC, DIO_PORT_LOW);
		}

	}
	return 0;
}
void LedRight(void)
{
	DIO_SetPortValue(DIO_PORTC, 0b00001111);
	_delay_ms(9000);
}
void LedLeft(void)
{
	DIO_SetPortValue(DIO_PORTC, 0b11110000);
	_delay_ms(9000);
}
