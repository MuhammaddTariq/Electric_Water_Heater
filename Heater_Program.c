#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include<util/delay.h>


void Shift(u8 Size_Arr ,u8 *Arr)
{
	u8 x;
	u8 *temp;
	temp=&Arr[Size_Arr-1];
	for(x=Size_Arr-1;x>0;x--)
	{
		Arr[x]=Arr[x-1];
	}
	Arr[0]=*temp;
}

u8 Avg_Calc(u8 Size_Arr ,u8 *Arr)
{
	u8 i;
	u8 sum;
	u8 avg;
	for (i = 0; i < Size_Arr; ++i)
	{
		sum += Arr[i];
		_delay_ms(100);
	}
	avg = sum/Size_Arr;
	return avg;
}

void Heater_Display(u8 Current_Temp)
{
	u8 x = Current_Temp;
	u8 y = x/10;
	u8 z = x%10;

	while(1)
	{
		//enable segment 1
		DIO_u8SetPinValue(PIN0,DIO_PORTA,HIGH);
		DIO_u8SetPinValue(PIN1,DIO_PORTA,LOW);
		// display segment 1 = z
		DIO_u8SetPortValue(DIO_PORTB,z);
		_delay_ms(2);
		// enable segment 2
		DIO_u8SetPinValue(PIN0,DIO_PORTA,LOW);
		DIO_u8SetPinValue(PIN1,DIO_PORTA,HIGH);
		// display segment 2 = y
		DIO_u8SetPortValue(DIO_PORTB,y);
		_delay_ms(2);
	}
}






