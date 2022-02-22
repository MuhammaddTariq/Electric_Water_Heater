/*
 * TWI_PROGRAM.c
 *
 *  Created on: 25 Nov 2021
 *      Author: Zyad_
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TWI_Private.h"

void TWI_voidInitMaster(u8 Copy_u8Address )
{
	/*Enable to ACK*/
	SET_BIT(TWCR,6);
	/*Select prescaler-->1*/
	CLR_BIT(TWSR,1);
	CLR_BIT(TWSR,0);
	TWBR=12;
	/*Set Master Address*/
	TWAR=Copy_u8Address<<1;
	/*TWI Enable*/
	SET_BIT(TWCR,2);
}
void TWI_voidInitSlave(u8 Copy_u8Address )
{
	/*Enable to ACK*/
	SET_BIT(TWCR,6);
	/*Set own Address*/
	TWAR=Copy_u8Address<<1;
	/*TWI Enable*/
	SET_BIT(TWCR,2);
}
u8 TWI_u8StartCondition(void)
{
	u8 ErrorState=OK;
	/*Set Start Condition Bit*/
	SET_BIT(TWCR,5);
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);

	/*check the operation status*/
	if(TWSR==0x08)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	u8 ErrorState=OK;
	/*Send 7bits Slave Address With Write*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Set the write mode*/
	CLR_BIT(TWDR,0);
	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,5);
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);

	/*check the operation status*/
	if(TWSR==0x18)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	u8 ErrorState=OK;
	/*Send 7bits Slave Address With Write*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Set the Read mode*/
	SET_BIT(TWDR,0);
	/*Clear Start Condition Bit*/
	CLR_BIT(TWCR,5);
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);

	/*check the operation status*/
	if(TWSR==0x40)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8MasterSendDataByte(u8 Copy_u8Data)
{
	u8 ErrorState=OK;
	/*Send 8bits Data*/
	TWDR=Copy_u8Data;
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);

	/*check the operation status*/
	if(TWSR==0x28)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8MasterReadDataByte(u8* Copy_Pu8Data)
{
	u8 ErrorState=OK;
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);
	/*check the operation status*/
	if(TWSR==0x50)
	{
		*Copy_Pu8Data=TWDR;
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8RepeatedStart(void)
{
	u8 ErrorState=OK;
	/*Set Start Condition Bit*/
	SET_BIT(TWCR,5);
	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
	/*wait on flag until the operation is finished */
	while(GET_BIT(TWCR,7)==0);

	/*check the operation status*/
	if(TWSR==0x10)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
void TWI_voidStopCondtion(void)
{
	/*SET Stop Condition Bit*/
	SET_BIT(TWCR,4);

	/*Clear TWINT Flag*/
	SET_BIT(TWCR,7);
}
