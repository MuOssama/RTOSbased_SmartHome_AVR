/*
 * ADC.c
 *
 *  Created on: Jun 26, 2022
 *      Author: Mustapha
 */
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATh.h"
#include "../ADC/ADC_INTERFACE.h"
#include "../ADC/ADC_REG.h"

void ADC_init(){
	//ADC Voltage Reference Selection to AVCC
	SET_BIT(ADMUX_REG,ADMUX_REFS0);
	CLR_BIT(ADMUX_REG,ADMUX_REFS1);

    //ADC Right Adjust
	CLR_BIT(ADMUX_REG,ADMUX_ADLAR);

	//ADC Prescaler Clock Selection to 128 (the slowest speed)
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS0);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS1);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS2);

    //ADC Enable
	SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}

u16 ADC_Read_Sych(u8 channel){
	u32 time = 100000;
	u32 cnt = 0;
	//Channel Select
	ADMUX_REG &= 0b11100000;
	ADMUX_REG |= channel;

	//Start Conversion
	SET_BIT(ADCSRA_REG,ADCSRA_ADSC);

	while((GET_BIT(ADCSRA_REG,ADCSRA_ADIF)==0 )|| cnt != time){
		cnt++;
	}

	//Clear ADC Flag for the next conversion because No INTERRUPT is used
	SET_BIT(ADCSRA_REG,ADCSRA_ADIF);

	//Return the reading
    return ADCL_REG;


}

