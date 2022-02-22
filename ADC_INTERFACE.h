/*
 * ADC_INTERFACE.h
 *
 *  Created on: 1 Oct 2021
 *      Author: Zyad_
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
void ADC_voidInit_Interrupt(void);
void ADC_voidStartConversion(u8 Copy_u8Channel);
void ADC_voidStartConversion_Interrupt(u8 Copy_u8Channel);
u16 ADC_u16ReadDigitalValue(void);

#endif /* ADC_INTERFACE_H_ */
