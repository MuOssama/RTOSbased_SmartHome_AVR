/*
 * INTRRUPT.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Mustapha
 */
#include "EXT_INTERRUPT_REG.h"
#include "EXT_INTERRUPT_CONFIG.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "EXT_INTERRUPT_INTERFACE.h"

INT0_init() {

	//Sense Control for INT0
#if INT0_Sense_Control == Rising_Edge
	SET_BIT(MCUCR_REG, ISC00);
	SET_BIT(MCUCR_REG, ISC01);
#endif

#if INT0_Sense_Control == Falling_Edge
	CLR_BIT(MCUCR_REG,ISC00);
	SET_BIT(MCUCR_REG,ISC01);
#endif

#if INT0_Sense_Control == On_Change
	SET_BIT(MCUCR_REG,ISC00);
	CLR_BIT(MCUCR_REG,ISC01);
#endif

#if INT0_Sense_Control == Low_Level
	CLR_BIT(MCUCR_REG,ISC00);
	CLR_BIT(MCUCR_REG,ISC01);
#endif

	//Specific Interrupt Enable

	SET_BIT(GICR_REG, GICR_INT0);

}

INT1_init() {

	//Sense Control for INT1
#if INT0_Sense_Control == Rising_Edge
	SET_BIT(MCUCR_REG, ISC10);
	SET_BIT(MCUCR_REG, ISC11);
#endif

#if INT0_Sense_Control == Falling_Edge
	CLR_BIT(MCUCR_REG,ISC10);
	SET_BIT(MCUCR_REG,ISC11);
#endif

#if INT0_Sense_Control == On_Change
	SET_BIT(MCUCR_REG,ISC10);
	CLR_BIT(MCUCR_REG,ISC11);
#endif

#if INT0_Sense_Control == Low_Level
	CLR_BIT(MCUCR_REG,ISC10);
	CLR_BIT(MCUCR_REG,ISC11);
#endif


	//Specific Interrupt Enable

	SET_BIT(GICR_REG, GICR_INT1);

}

INT2_init() {

	//Sense Control for INT0
#if INT0_Sense_Control == Rising_Edge
	SET_BIT(MCUCSR_REG, ISC2);
#endif

#if INT0_Sense_Control == Falling_Edge
	CLR_BIT(MCUCSR_REG,ISC2);
#endif




	//Specific Interrupt Enable

	SET_BIT(GICR_REG, GICR_INT2);

}

