/*
 * ADC_REG.h
 *
 *  Created on: Jun 26, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#define ADMUX_REG    *((volatile u8*)0x27)
#define ADMUX_ADLAR  5   //Left or right Adjust Result
#define ADMUX_REFS0  6   //Reference Voltage Selection
#define ADMUX_REFS1  7   //Reference Voltage Selection


#define ADCSRA_REG   *((volatile u8*)0x26)
#define ADCSRA_ADPS0 0   //Prescaler select
#define ADCSRA_ADPS1 1   //Prescaler select
#define ADCSRA_ADPS2 2   //Prescaler select
#define ADCSRA_ADIE  3   //ADC Interrupt Enable
#define ADCSRA_ADIF  4   //ADC Interrupt flag
#define ADCSRA_ADSC  6   //ADC Start Conversion
#define ADCSRA_ADEN  7   //ADC Enable


#define ADCL_REG      *((volatile u16*)0x24)
#define ADCH_REG      *((volatile u8*)0x25)




#endif /* MCAL_ADC_ADC_REG_H_ */
