/*
 * ADC_PROGRAM.c
 *
 *  Created on: 1 Oct 2021
 *      Author: Zyad_
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"

void ADC_voidInit(void)
{
	/* select Reference volt*/
#if ADC_REFERENCE_VOLT==ADC_AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_REFERENCE_VOLT==ADC_INTERNAL_2.56v
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
	#error "Invalid ADC_REFERENCE_VOLT Options"
#endif

	/* select Adjust Option*/
#if ADC_LEFT_RIGHT_ADJUST==ADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif ADC_LEFT_RIGHT_ADJUST==ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
	#error "Invalid ADC_LEFT_RIGHT Options"
#endif

	/* select 128 prescaler*/
	ADCSRA&=0xF8;
	ADCSRA|=0x07;

	/* enable ADC*/
	SET_BIT(ADCSRA,7);
}
void ADC_voidInit_Interrupt()
{
	/* select Reference volt*/
#if ADC_REFERENCE_VOLT==ADC_AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_REFERENCE_VOLT==ADC_INTERNAL_2.56v
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
	#error "Invalid ADC_REFERENCE_VOLT Options"
#endif

	/* select Adjust Option*/
#if ADC_LEFT_RIGHT_ADJUST==ADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif ADC_LEFT_RIGHT_ADJUST==ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
	#error "Invalid ADC_LEFT_RIGHT Options"
#endif

	/* select 128 prescaler*/
	ADCSRA&=0xF8;
	ADCSRA|=0x07;

	/* enable ADC*/
	SET_BIT(ADCSRA,7);

	/*ADC Interrupt enable*/
	SET_BIT(ADCSRA,3);
}

void ADC_voidStartConversion(u8 Copy_u8Channel)
{
	ADMUX&=0xE0;
	ADMUX|=Copy_u8Channel;

	/* start conversion */
	SET_BIT(ADCSRA,6);

	/*wait till ADC_flag be high*/
	while(GET_BIT(ADCSRA,4)==0);
}
void ADC_voidStartConversion_Interrupt(u8 Copy_u8Channel)
{
	ADMUX&=0xE0;
	ADMUX|=Copy_u8Channel;

	/* start conversion */
	SET_BIT(ADCSRA,6);
}
u16 ADC_u16ReadDigitalValue(void)
{
	return ADC;
}
