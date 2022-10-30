/*
 * TIMER.PROGRAM.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Mustapha
 */
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include"TIMER_INTERFACE.h"
#include"TIMER_REG.h"

void Timer0_init(){
	/*Fast PWM TIMER MODE*/
   SET_BIT(TCCR0_REG,TCCR0_WGM00);
   SET_BIT(TCCR0_REG,TCCR0_WGM01);

   /*Non inverting PWM */
   CLR_BIT(TCCR0_REG,TCCR0_COM00);
   SET_BIT(TCCR0_REG,TCCR0_COM01);

   /*Prescaler Clock Select*/
   CLR_BIT(TCCR0_REG,TCCR0_CS00);
   SET_BIT(TCCR0_REG,TCCR0_CS01);
   CLR_BIT(TCCR0_REG,TCCR0_CS02);


}

void Timer1_init(){
	/*Fast PWM Mode ICR1*/
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);


    /*interrupt enable*/
	//SET_BIT(TIMSK_REG,TIMSK_TOIE1);
	//SET_BIT(TIMSK_REG,TIMSK_OCIE1A);

	/*Mode Fast PWM on OCR1A NON-inverting */
	CLR_BIT(TCCR1A_REG,TCCR1A_COM1A0);
	SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
    ICR1L_REG = 20000;
	/*Prescaler = 8*/
	CLR_BIT(TCCR1B_REG,TCCR1B_CS10);
	SET_BIT(TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TCCR1B_REG,TCCR1B_CS12);





	}
	
void Timer2_init(){
   /*Fast PWM TIMER MODE*/
   SET_BIT(TCCR2_REG,TCCR2_WGM20);
   SET_BIT(TCCR2_REG,TCCR2_WGM21);

   /*PWM Timer Mode*/
   // SET_BIT(TIMSK_REG,TIMSK_TOIE0);
   //SET_BIT(TIMSK_REG,TIMSK_OCIE0);

   /*PWM */
   CLR_BIT(TCCR2_REG,TCCR2_COM20);
   SET_BIT(TCCR2_REG,TCCR2_COM21);

   /*Timer set*/
   /*
   TCNT0_REG = 128;
   */
   /*compare match output register*/
   //OCR0_REG = 0;


   /*Prescaler Clock Select*/
   CLR_BIT(TCCR2_REG,TCCR2_CS20);
   SET_BIT(TCCR2_REG,TCCR2_CS21);
   CLR_BIT(TCCR2_REG,TCCR2_CS22);


}
void SET_TCNT0(u8 value){
	TCNT0_REG = value;
}
void SET_OCR0(u8 value){
	OCR0_REG = value;
}
void SET_TCNT2(u8 value){
	TCNT2_REG = value;
}
void SET_OCR2(u8 value){
	OCR2_REG = value;
}
void SET_TCNT1(u16 value){
	TCNT1L_REG = value;
}
void SET_OCR1A(u16 value){
	OCR1AL_REG = value;
}
void SET_OCR1B(u16 value){
	OCR1BL_REG = value;
}

