/*
 * TMR_MCAL_Prog.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Lenovo
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <avr/interrupt.h>
#include "TMR_MCAL_Config.h"
#include "TMR_MCAL_Interface.h"
#include "TMR_MCAL_Private.h"


static void (*TMR0_Ov_SetCallBackPf)(void) = STD_TYPES_NULL;
static void (*TMR0_Comp_SetCallBackPf)(void) = STD_TYPES_NULL;

void TMR0_Init(void)
{
	switch(TMR0_Mode)
	{
	case TMR0_Normal_Mode :

		SET_BIT(TIMSK_REG,TIMSK_TOIE0_PIN);

		CLR_BIT(TCCR0_REG,TCCR0_WGM00_PIN);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01_PIN);

		TCNT0_REG = TMR0_PRELOADVALUE;
		break;

	case TMR0_CTC_Mode :
		CLR_BIT(TCCR0_REG,TCCR0_WGM00_PIN);
		SET_BIT(TCCR0_REG,TCCR0_WGM01_PIN);

		OCR0_REG = TMR0_CTCVALUE_CTC;

		SET_BIT(TIMSK_REG, TIMSK_OCIE0_PIN);
		switch(TMR0_CTC_OC0_Mode)
		{
		case CTC_OC0_Normal :
			CLR_BIT(TCCR0_REG,TCCR0_COM00_PIN);
			CLR_BIT(TCCR0_REG,TCCR0_COM01_PIN);
			break;
		case CTC_OC0_Toggle :
			SET_BIT(TCCR0_REG,TCCR0_COM00_PIN);
			CLR_BIT(TCCR0_REG,TCCR0_COM01_PIN);
			break;
		case CTC_OC0_Non_Inverted :
			CLR_BIT(TCCR0_REG,TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG,TCCR0_COM01_PIN);
			break;
		case CTC_OC0_Inverted :
			SET_BIT(TCCR0_REG,TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG,TCCR0_COM01_PIN);
			break;
		}
		break;


	case  TMR0_Phase_PWM_Mode :

		SET_BIT(TCCR0_REG,TCCR0_WGM00_PIN);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01_PIN);

		switch(TMR0_Phase_Correct_PWM_OC0_Mode)
		{

		case PHASE_CORRECT_PWM_Normal :
			CLR_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			CLR_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;

		case PHASE_CORRECT_PWM_Non_Inverted :
			CLR_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;

		case PHASE_CORRECT_PWM_Inverted:
			SET_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;
		}
		OCR0_REG = TMR0_CTCVALUE_PHASE;
		break;


	case TMR0_Fast_PWM_Mode :
		SET_BIT(TCCR0_REG,TCCR0_WGM00_PIN);
		SET_BIT(TCCR0_REG,TCCR0_WGM01_PIN);
		switch(TMR0_FAST_PWM_OC0_Mode)
		{
		case FAST_PWM_Normal :
			CLR_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			CLR_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;
		case FAST_PWM_Non_Inverted:
			CLR_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;
		case FAST_PWM_Inverted:
			SET_BIT(TCCR0_REG, TCCR0_COM00_PIN);
			SET_BIT(TCCR0_REG, TCCR0_COM01_PIN);
			break;
		}
		OCR0_REG = TMR0_CTCVALUE_FAST;
		break;
	}
	TCCR0_REG = 0b11111000;
	TCCR0 |= TMR0_PreScalar_Value;
}
void TMR0_SetPreload(u8 preloadValue)
{
	TCNT0_REG = preloadValue;
}
void TMR0_SetCTC(u8 CTCValue)
{
	OCR0_REG = CTCValue;
}
void TMR0_GeneratePWM(u16 CompareMatchValue)
{
	OCR0 = CompareMatchValue;
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= TMR0_PreScalar_Value;
}
void TMR0_OV_SetCallBack(void (*pf)(void))
{
	TMR0_Ov_SetCallBackPf =pf;
}
void TMR0_Comp_SetCallBack(void (*pf)(void))
{
	TMR0_Comp_SetCallBackPf = pf;
}
/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
	TMR0_Ov_SetCallBackPf();
}
/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
		TMR0_Comp_SetCallBackPf();
}
