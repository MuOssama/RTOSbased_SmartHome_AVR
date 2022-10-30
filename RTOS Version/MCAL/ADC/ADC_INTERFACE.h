/*
 * ADC.h
 *
 *  Created on: Jun 26, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

void ADC_init();
u16 ADC_Read_Sych(u8 channel);
u16 ADC_Read_ASych();




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
