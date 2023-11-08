/*
 * TMR_MCAL_Private.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TMR_DRIVER_TMR_MCAL_PRIVATE_H_
#define MCAL_TMR_DRIVER_TMR_MCAL_PRIVATE_H_

#define TCCR0_REG	*((volatile u8*)(0x53))
#define TCNT0_REG	*((volatile u8*)(0x52))
#define OCR0_REG	*((volatile u8*)(0x5C))
#define TIMSK_REG	*((volatile u8*)(0x59))
#define TIFR_REG	*((volatile u8*)(0x58)


#define TCCR0_FOCO_PIN	7
#define TCCR0_WGM00_PIN	6
#define TCCR0_COM01_PIN	5
#define TCCR0_COM00_PIN	4
#define TCCR0_WGM01_PIN	3
#define TCCR0_CS02_PIN	2
#define TCCR0_CS01_PIN	1
#define TCCR0_CS00_PIN	0

#define TIMSK_TOIE0_PIN	0
#define TIMSK_OCIE0_PIN	1

#define TIFR_TOVO_PIN	0
#define TIFR_OCF0_PIN	0

//Timer 0 Mode
#define TMR0_Normal_Mode		0b00000000
#define TMR0_CTC_Mode			0b00001000
#define TMR0_Phase_PWM_Mode		0b01000000
#define TMR0_Fast_PWM_Mode		0b01001000

//CTC OC0 Mode
#define CTC_OC0_Normal			0b00000000
#define CTC_OC0_Toggle			0b00010000
#define CTC_OC0_Non_Inverted	0b00100000
#define CTC_OC0_Inverted		0b00110000

//Fast PWM OC0 Mode
#define FAST_PWM_Normal			0b00000000
#define FAST_PWM_Non_Inverted	0b00100000
#define FAST_PWM_Inverted		0b00110000

//Phase Correct PWM
#define PHASE_CORRECT_PWM_Normal			0b00000000
#define PHASE_CORRECT_PWM_Non_Inverted	0b00100000
#define PHASE_CORRECT_PWM_Inverted		0b00110000



#endif /* MCAL_TMR_DRIVER_TMR_MCAL_PRIVATE_H_ */
