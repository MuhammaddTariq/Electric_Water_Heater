
#include"STD_TYPES.h"
#include"TWI_INTERFACE.h"
#include"EEPROM_PRIVATE.h"
#include "ADC_INTERFACE.h"
#include <util/delay.h>
#include"Heater_Interface.h"
#include"DIO_INTERFACE.h"


int main ()
{
	u8 Temps_Readings[10] = {60,0,0,0,0,0,0,0,0,0};
	u8 *i=&Temps_Readings[0];
	u8 Heating_Element=0;
	u8 Cooling_Element=0;
	u8 Current_Temp ;
	u8 PinState0, PinState1,PinState2;
	u8 AnalogValue=0;
	u8 Copy_u16DigitalValue=0;

	// setting pin 0 as enable for segment 1
	// and pin 2 as enable for segment 2
	DIO_u8SetPinDirection(PIN0,DIO_PORTA,PIN_INPUT);
	DIO_u8SetPinDirection(PIN1,DIO_PORTA,PIN_INPUT);

	// setting pins b1,b2,b3,b4 in portB as outputs for segment1/segment2
	DIO_u8SetPortDirection(DIO_PORTB,PORT_OUTPUT);
	DIO_u8SetPinValue(PIN0,DIO_PORTB,LOW);
	DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
	DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
	DIO_u8SetPinValue(PIN3,DIO_PORTB,LOW);
	// LED is set in pin4 portB
	DIO_u8SetPinValue(PIN4,DIO_PORTB,LOW);

	// set pin0 in portA as a button for increasing temperature.
	DIO_u8SetPinDirection(PIN0,DIO_PORTA,PIN_INPUT);
	// set pin1 in portA as a button for decreasing temperature
	DIO_u8SetPinDirection(PIN1,DIO_PORTA,PIN_INPUT);
	// set pin2 in portA as an ON/OFF button
	DIO_u8SetPinDirection(PIN2,DIO_PORTA,PIN_INPUT);



	ADC_voidInit();

	while(1)
	{
		// if the power button was pressed
		if(DIO_u8GetPinValue(PIN2,DIO_PORTA,&PinState0)==1)
		{
			Heater_Display(60);
		}
		ADC_voidStartConversion(1);
		Current_Temp = ADC_u16ReadDigitalValue();

		if(Current_Temp != Copy_u16DigitalValue)
		{
			AnalogValue = (Current_Temp*5000)/1024;
			Copy_u16DigitalValue = Current_Temp;


			// setting temperature
			// if the inc. temp. is pressed
			if(DIO_u8GetPinValue(PIN0,DIO_PORTA,&PinState1)==1)
			{
				while(Current_Temp != 75)
				{
					switch(Current_Temp)
					{
					case 60:
						Current_Temp = 65;
						Heater_Display(Current_Temp);
						break;

					case 65:
						Current_Temp = 70;
						Heater_Display(Current_Temp);
						break;

					case 70:
						Current_Temp = 75;
						Heater_Display(Current_Temp);
						break;

					case 75:
						break;
					}

				}
			}
			// if the dec. temp. button is pressed
			if(DIO_u8GetPinValue(PIN1,DIO_PORTA,&PinState2)==1)
			{
				while(Current_Temp != 35)
				{
					switch(Current_Temp)
					{
					case 60:
						Current_Temp = 55;
						Heater_Display(Current_Temp);
						break;

					case 55:
						Current_Temp = 50;
						Heater_Display(Current_Temp);
						break;

					case 50:
						Current_Temp = 45;
						Heater_Display(Current_Temp);
						break;

					case 45:
						Current_Temp = 40;
						Heater_Display(Current_Temp);
						break;

					case 40:
						Current_Temp = 35;
						Heater_Display(Current_Temp);
						break;

					case 35:
						break;
					}

				}
			}
			// checking after setting temperature
			if(Avg_Calc(10,i[0])<Current_Temp-5)
			{
				// temperature is lower than the set temperature by 5
				Cooling_Element = 1;
				while(1)
				{
					// blink the LED
					DIO_u8SetPinValue(PIN4,DIO_PORTB,HIGH);
					_delay_ms(1000);
				}
				eeprom_write_word((unsigned int*)&Temps_Readings[*i], AnalogValue);

			}
			if(Avg_Calc(10,i[0])>Current_Temp+5)
			{
				// temperature is Higher than the set temperature by 5
				Heating_Element = 1;
				while(1)
				{
					//LED is ON
					DIO_u8SetPinValue(PIN4,DIO_PORTB,HIGH);
				}
				eeprom_write_word((unsigned int*)&Temps_Readings[*i], AnalogValue);
			}
		}

	}
	return 0;
}
