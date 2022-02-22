/*
 * DIO_PROGRAM.c
 *
 *  Created on: 11 Sep 2021
 *      Author: Zyad_
 */

#include "DIO_PRIVATE.h"
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"


u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber,u8 Copy_u8PortName,u8 Copy_u8Direction)
{
	u8 Error_State = OK;

	if(Copy_u8PinNumber<8)
	{
	switch(Copy_u8PortName)
	{
	case DIO_PORTA:
		if(Copy_u8Direction == PIN_OUTPUT)
		{
			SET_BIT(DDRA,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == PIN_INPUT)
		{
			CLR_BIT(DDRA,Copy_u8PinNumber);
		}
		else
		{
			Error_State = NOK;
		}
		break;
	case DIO_PORTB:
		if(Copy_u8Direction == PIN_OUTPUT)
		{
			SET_BIT(DDRB,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == PIN_INPUT)
		{
			CLR_BIT(DDRB,Copy_u8PinNumber);
		}
		else
		{
			Error_State = NOK;
		}
		break;
	case DIO_PORTC:
		if(Copy_u8Direction == PIN_OUTPUT)
		{
			SET_BIT(DDRC,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == PIN_INPUT)
		{
			CLR_BIT(DDRC,Copy_u8PinNumber);
		}
		else
		{
			Error_State = NOK;
		}
		break;
	case DIO_PORTD:
		if(Copy_u8Direction == PIN_OUTPUT)
		{
			SET_BIT(DDRD,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction == PIN_INPUT)
		{
			CLR_BIT(DDRD,Copy_u8PinNumber);
		}
		else
		{
			Error_State = NOK;
		}
		break;
	default:
		Error_State = NOK;
		break;
	}
}
	else
	{
		Error_State = NOK;
	}
	return Error_State;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortName,u8 Copy_u8Value)
{
	u8 Error_State = OK;

		if(Copy_u8PinNumber<8)
		{
		switch(Copy_u8PortName)
		{
		case DIO_PORTA:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTB:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNumber);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTB,Copy_u8PinNumber);
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTC:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTC,Copy_u8PinNumber);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTC,Copy_u8PinNumber);
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTD:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(PORTD,Copy_u8PinNumber);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTD,Copy_u8PinNumber);
			}
			else
			{
				Error_State = NOK;
			}
			break;
		default:
			Error_State = NOK;
			break;
		}
	}
		else
		{
			Error_State = NOK;
		}
		return Error_State;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortName,u8 Copy_u8Direction)
{
	u8 Error_State = OK;

	switch(Copy_u8PortName)
		{
		case DIO_PORTA:
			if(Copy_u8Direction == PORT_OUTPUT)
			{
				DDRA = PORT_OUTPUT;
			}
			else if(Copy_u8Direction == PORT_INPUT)
			{
				DDRA = PORT_INPUT;
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTB:
			if(Copy_u8Direction == PORT_OUTPUT)
			{
				DDRB = PORT_OUTPUT;
			}
			else if(Copy_u8Direction == PORT_INPUT)
			{
				DDRB = PORT_INPUT;
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTC:
			if(Copy_u8Direction == PORT_OUTPUT)
			{
				DDRC = PORT_OUTPUT;
			}
			else if(Copy_u8Direction == PORT_INPUT)
			{
				DDRC = PORT_INPUT;
			}
			else
			{
				Error_State = NOK;
			}
			break;
		case DIO_PORTD:
			if(Copy_u8Direction == PORT_OUTPUT)
			{
				DDRD = PORT_OUTPUT;
			}
			else if(Copy_u8Direction == PORT_INPUT)
			{
				DDRD = PORT_INPUT;
			}
			else
			{
				Error_State = NOK;
			}
			break;
		default:
			Error_State = NOK;
			break;
		}

		return Error_State;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortName,u8 Copy_u8Value)
{
	    u8 Error_State = OK;

	    if(Copy_u8Value<=255)
	    {
	    	switch(Copy_u8PortName)
	    	{
	    	case DIO_PORTA:
	    		PORTA=Copy_u8Value;
	    		break;
	    	case DIO_PORTB:
	    		PORTB=Copy_u8Value;
	    		break;
	    	case DIO_PORTC:
	    		PORTC=Copy_u8Value;
	    		break;
	    	case DIO_PORTD:
	    		PORTD=Copy_u8Value;
	    		break;
	    	default:
	    		Error_State=NOK;
	    		break;
	    	}
	    }
		else
		{
			Error_State = NOK;
		}
			return Error_State;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortName,u8* u8PtrToValue)
{

	    u8 Error_State = OK;

		if(Copy_u8PinNumber<8)
		{
		switch(Copy_u8PortName)
		{
		case DIO_PORTA:
			   *u8PtrToValue  =  GET_BIT(PINA,Copy_u8PinNumber);
			break;
		case DIO_PORTB:
			    *u8PtrToValue = GET_BIT(PINB,Copy_u8PinNumber);
			break;
		case DIO_PORTC:
			    *u8PtrToValue = GET_BIT(PINC,Copy_u8PinNumber);
			break;
		case DIO_PORTD:
			    *u8PtrToValue = GET_BIT(PIND,Copy_u8PinNumber);
			break;
		default:
			Error_State = NOK;
			break;
		}
	}
		else
		{
			Error_State = NOK;
		}

		return Error_State;
}

void DIO_u8Set4MSB_BitsValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue)
{
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		PORTA&=0x0F;
		Copy_u8PortValue&=0xF0;
		PORTA|=Copy_u8PortValue;
		break;
	case DIO_PORTB:
		PORTB&=0x0F;
		Copy_u8PortValue&=0xF0;
		PORTB|=Copy_u8PortValue;
		break;
	case DIO_PORTC:
		PORTC&=0x0F;
		Copy_u8PortValue&=0xF0;
		PORTC|=Copy_u8PortValue;
		break;
	case DIO_PORTD:
		PORTD&=0x0F;
		Copy_u8PortValue&=0xF0;
		PORTD|=Copy_u8PortValue;
		break;
	}
}




