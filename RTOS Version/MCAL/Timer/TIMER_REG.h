/*
 * TIMER_REG.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_

/****************************/
/*Timer/Counter 0 Registers */
/****************************/
#define TCCR0_REG *((volatile u8*)0x53)
#define TCCR0_CS00   0   //clock select timer 0
#define TCCR0_CS01   1   //clock select timer 0
#define TCCR0_CS02   2   //clock select timer 0
#define TCCR0_WGM01  3   //waveform selection timer 0
#define TCCR0_COM00  4   //waveform selection timer 0
#define TCCR0_COM01  5   //waveform selection timer 0
#define TCCR0_WGM00  6   //waveform selection timer 0

#define OCR0_REG *((volatile u8*)0x5C) //overflow timer 0 register
#define TCNT0_REG *((volatile u8*)0x52)   //timer/counter 0

#define TIMSK_REG *((volatile u8*)0x59)
#define TIMSK_TOIE0 0 //timer 0 overflow interrupt enable
#define TIMSK_OCIE0 1 //timer 0 output compare match interrupt enable






/****************************/
/*Timer/Counter 1 Registers */
/****************************/
#define TCCR1A_REG      *((volatile u8*)0x4F)   //timer/counter 1A
#define TCCR1A_WGM10    0   //waveform selection timer 1
#define TCCR1A_WGM11    1   //waveform selection timer 1
#define TCCR1A_COM1B0   4   //output mode for OCR1B
#define TCCR1A_COM1B1   5   //output mode for OCR1B
#define TCCR1A_COM1A0   6   //output mode for OCR1A
#define TCCR1A_COM1A1   7   //output mode for OCR1A

#define TCCR1B_REG      *((volatile u8*)0x4E)   //timer/counter 1B
#define TCCR1B_CS10     0   //prescaler select
#define TCCR1B_CS11     1   //prescaler select
#define TCCR1B_CS12     2   //prescaler select
#define TCCR1B_WGM12    3   //waveform selection timer 1
#define TCCR1B_WGM13    4   //waveform selection timer 1

#define TCNT1L_REG      *((volatile u16*)0x4C)  //Timer 1 (16-Bit Register)
#define OCR1AL_REG      *((volatile u16*)0x4A)  //Output compare match A (16-Bit Register)
#define OCR1BL_REG      *((volatile u16*)0x48)  //Output compare match B (16-Bit Register)
#define ICR1L_REG       *((volatile u16*)0x46)  //Input capture register (16-Bit Register)


//TIMSK_REG *((volatile u8*)0x59)
#define TIMSK_TOIE1  2 //timer 1 overflow interrupt enable
#define TIMSK_OCIE1B 3 //timer 1 output compare match B interrupt enable
#define TIMSK_OCIE1A 4 //timer 1 output compare match A interrupt enable
#define TIMSK_TICIE  5 //timer 1 timer/Counter1 Input Capture Interrupt Enable






/****************************/
/*Timer/Counter 2 Registers */
/****************************/
#define TCCR2_REG *((volatile u8*)0x45)
#define TCCR2_CS20   0   //clock select timer 2
#define TCCR2_CS21   1   //clock select timer 2
#define TCCR2_CS22   2   //clock select timer 2
#define TCCR2_WGM21  3   //waveform selection timer 2
#define TCCR2_COM20  4   //waveform selection timer 2
#define TCCR2_COM21  5   //waveform selection timer 2
#define TCCR2_WGM20  6   //waveform selection timer 2

#define TCNT2_REG *((volatile u8*)0x44)   //timer/counter 2
#define OCR2_REG *((volatile u8*)0x43) //overflow timer 2 register

#define TIMSK_REG *((volatile u8*)0x59)
#define TIMSK_TOIE2 6 //timer 0 overflow interrupt enable
#define TIMSK_OCIE2 7 //timer 0 output compare match interrupt enable

#endif /* MCAL_TIMER_TIMER_REG_H_ */
