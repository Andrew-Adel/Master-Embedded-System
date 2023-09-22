/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: Sep 17, 2023
 *      Author: andre
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//------------------------------------------
//Includes
//------------------------------------------

#include "stm32f103x6.h"

//------------------------------------------
//Configuration Structure
//------------------------------------------

typedef struct
{
	uint16_t 	GPIO_PIN;
	uint8_t		GPIO_MODE;
	uint8_t		GPIO_Output_Speed;

}GPIO_PinConfig_t;

//------------------------------------------
//MACRO Configuration Reference
//------------------------------------------

// ============== @ref GPIO_PINS_Define ==============

#define GPIO_PIN_0				((uint16_t)0x0001)
#define GPIO_PIN_1				((uint16_t)0x0002)
#define GPIO_PIN_2				((uint16_t)0x0004)
#define GPIO_PIN_3				((uint16_t)0x0008)
#define GPIO_PIN_4				((uint16_t)0x0010)
#define GPIO_PIN_5				((uint16_t)0x0020)
#define GPIO_PIN_6				((uint16_t)0x0040)
#define GPIO_PIN_7				((uint16_t)0x0080)
#define GPIO_PIN_8				((uint16_t)0x0100)
#define GPIO_PIN_9				((uint16_t)0x0200)
#define GPIO_PIN_10				((uint16_t)0x0400)
#define GPIO_PIN_11				((uint16_t)0x0800)
#define GPIO_PIN_12				((uint16_t)0x1000)
#define GPIO_PIN_13				((uint16_t)0x2000)
#define GPIO_PIN_14				((uint16_t)0x4000)
#define GPIO_PIN_15				((uint16_t)0x8000)
#define GPIO_PIN_ALL			((uint16_t)0xFFFF)

#define GPIO_PIN_MASK			0x0000FFFFu

// ==============  @ref GPIO_MODE_define ==============

//0: Analog mode
//1: Floating Input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General Purpose output Push-Pull
//5: General Purpose Open-Drain
//6: Alternative Function output Push-Pull
//7: Alternative Function output Open-Drain
//8: Alternative Function Input (Floating Input)

#define GPIO_MODE_Analog					0x00000000u
#define GPIO_MODE_INPUT_FLO					0x00000001u
#define GPIO_MODE_INPUT_PU					0x00000002u
#define GPIO_MODE_INPUT_PD					0x00000003u
#define GPIO_MODE_OUTPUT_PP					0x00000004u
#define GPIO_MODE_OUTPUT_OD					0x00000005u
#define GPIO_MODE_OUTPUT_AF_PP				0x00000006u
#define GPIO_MODE_OUTPUT_AF_OD				0x00000007u
#define GPIO_MODE_INPUT_AF					0x00000008u

// ============== @ref GPIO_Output_Speed_Define ==============

#define GPIO_SPEED_10M						0x00000001u
#define GPIO_SPEED_20M						0x00000002u
#define GPIO_SPEED_50M						0x00000003u

// ============== @ref GPIO_PIN_STATE ==============

#define GPIO_PIN_SET						1
#define GPIO_PIN_RESET						0

// ============== @ref GPIO_RETURN_LOCK ==============

#define GPIO_RETURN_LOCK_Enabe				1
#define GPIO_RETURN_LOCK_Error				0

//================================================================================
//							APIs Supported by "MCAL GPIO DRIVER"
//================================================================================

void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef* GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin (GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort (GPIO_TypeDef* GPIOx, uint16_t Value);
void MCAL_GPIO_Write8Bits (GPIO_TypeDef* GPIOx,unsigned char start, uint16_t Value);
void MCAL_GPIO_Write4Bits (GPIO_TypeDef* GPIOx,unsigned char start, uint16_t Value);

void MCAL_GPIO_TogglePin (GPIO_TypeDef* GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx, uint16_t PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
