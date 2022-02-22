/*
 * TWI_PRIVATE.h
 *
 *  Created on: 25 Nov 2021
 *      Author: Zyad_
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define TWDR    *((volatile u8*)0x23)
#define TWAR    *((volatile u8*)0x22)
#define TWSR    *((volatile u8*)0x21)
#define TWBR    *((volatile u8*)0x20)
#define TWCR    *((volatile u8*)0x56)

#endif /* TWI_PRIVATE_H_ */
