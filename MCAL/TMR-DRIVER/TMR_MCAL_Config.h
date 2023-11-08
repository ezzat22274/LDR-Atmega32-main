/*
 * TMR_MCAL_Config.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TMR_DRIVER_TMR_MCAL_CONFIG_H_
#define MCAL_TMR_DRIVER_TMR_MCAL_CONFIG_H_

/*
 * Modes
 *		 TMR0_Normal_Mode
 * 		 TMR0_CTC_Mode
 * 		 TMR0_Phase_PWM_Mode
 *		 TMR0_Fast_PWM_Mode
 */
#define TMR0_Mode TMR0_Fast_PWM_Mode
/*
 * CTC OC0 Mode
 * 				CTC_OC0_Normal
 * 				CTC_OC0_Toggle
 * 				CTC_OC0_Non_Inverted
 * 				CTC_OC0_Inverted
 */
#define TMR0_CTC_OC0_Mode CTC_OC0_Normal
/*
 * FAST PWM OC0 Mode
 * 					FAST_PWM_Normal
 * 					FAST_PWM_Non_Inverted
 * 					FAST_PWM_Inverted
 */
#define TMR0_FAST_PWM_OC0_Mode	FAST_PWM_Normal
/*
 *  Phase Correct OC0 Mode
 * 					PHASE_CORRECT_PWM_Normal
 * 					PHASE_CORRECT_PWM_Non_Inverted
 * 					PHASE_CORRECT_PWM_Inverted
 */
#define TMR0_Phase_Correct_PWM_OC0_Mode	PHASE_CORRECT_PWM_Non_Inverted
/*choose the preScaler
 * 1-NO_CLOCK_SOURCE
   2-NO_PRESCALING
   3-PRESCALER_8
   4-PRESCALER_64
   5-PRESCALER_256
   6-PRESCALER_1024
   7-EXTRNAL_CLK_FALLING_EDGE
   8-EXTRNAL_CLK_RISING_EDGE */

#define TMR0_PreScalar_Value            PRESCALER_64

#define TMR0_PRELOADVALUE 		192
#define TMR0_CTCVALUE_PHASE		250
#define TMR0_CTCVALUE_CTC		125
#define TMR0_CTCVALUE_FAST		0

#endif /* MCAL_TMR_DRIVER_TMR_MCAL_CONFIG_H_ */
