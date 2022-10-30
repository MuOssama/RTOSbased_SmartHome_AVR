/*
 * GIE.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Mustapha
 */
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include "GIE_INTERFACE.h"
#include"GIE_REG.h"


void Globle_Intrrupt_Enable(){
    SET_BIT(SREG_REG,7);

}

void Globle_Intrrupt_Disable(){
    CLR_BIT(SREG_REG,7);

}
