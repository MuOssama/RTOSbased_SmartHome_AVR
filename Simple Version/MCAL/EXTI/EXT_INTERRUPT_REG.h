/*
 * INTERRUPT_REG.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_EXTI_EXT_INTERRUPT_REG_H_
#define MCAL_EXTI_EXT_INTERRUPT_REG_H_

// Specific Interrupt Enable
#define GICR_REG *((volatile u8*)0x5B)
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

// (MCUCR) Sense Control for INT0 and INT1
#define MCUCR_REG *((volatile u8*)0x55)
#define ISC00 0
#define ISC01 1

#define ISC10 2
#define ISC11 3

// (MCUCSR) Sense Control for INT0 and INT1
#define MCUCSR_REG  *((volatile u8*)0x54)
#define ISC2 6



// External Interrupt flag
#define GIFR_REG *((volatile u8*)5A)




#endif /* MCAL_EXTI_EXT_INTERRUPT_REG_H_ */
