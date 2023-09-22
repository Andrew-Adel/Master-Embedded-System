/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Andrew Adel
 */
#include "STM32_F103C6_GPIO_Driver.h"

uint16_t Get_CRLH_Position(uint16_t Pin)
{
	switch (Pin) {
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;

	default:
		return 0;
		break;
	}
}
/*============================================================================
	@ Fn				-MCAL_GPIO_Init
	@ brief				-Initialization the GPIOx PINy according to the specified parameters in the PinConfig
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-PinConfig Pointer to a GPIO_PinConfig_t structure that contain the configuration
							information for the specified GPIO PIN.
	@ retval			-None
	@ Note				-STM32F103C6 MCU has GPIO A,B,C,D,E Modules but LQFP48 package only
							has GPIO A&B, Part of C&D export as External PINs from
 */
void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	// Port Configure Register low (GPIO_CRL) Configure PINS from 0 >> 7
	// Port Configure Register High (GPIO_CRH) Configure PINS from 8 >> 15
	volatile uint32_t* configureRegister = NULL;
	uint8_t PIN_Config = 0;

	configureRegister = (PinConfig->GPIO_PIN < GPIO_PIN_8)? &GPIOx->CRL: &GPIOx->CRH;

	//Clear CNFy[1:0] MODEy[1:0]
	(*configureRegister) &= ~(0xF<< Get_CRLH_Position(PinConfig->GPIO_PIN));

	// if pin is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) ) {
		PIN_Config = ( ((PinConfig->GPIO_MODE - 4)<<2) | (PinConfig->GPIO_Output_Speed) ) & 0x0f;
	}
	// if pin is input
	else
	{
		if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog) )
		{
			//Clear CNFy[1:0] MODEy[1:0]
			PIN_Config = ( ((PinConfig->GPIO_MODE)<<2)) & 0x0f;
		}
		else if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF) ) // Consider it as Input FLoating
		{
			//Clear CNFy[1:0] MODEy[1:0]
			PIN_Config = ( (GPIO_MODE_INPUT_AF << 2) & 0x0f );
		}
		else // Pull up / Pull down
		{
			PIN_Config = ( (GPIO_MODE_INPUT_PU << 2) & 0x0f );
			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//				Table 20. Port bit Configuration Table PxODR 1
				GPIOx->ODR |= PinConfig->GPIO_PIN;
			}
			else
			{
				//				Table 20. Port bit Configuration Table PxODR 0
				GPIOx->ODR &= ~(PinConfig->GPIO_PIN);
			}
		}
	}
	(*configureRegister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PIN) );

}



/*============================================================================
	@ Fn				-MCAL_GPIO_DeInit
	@ brief				-Reset All GPIO Register
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ retval			-None
	@ Note				-None
 */
void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOx) // Important if MCU don't has Reset Controller
{
	// Manual Reseting
	//	GPIOx->CRL = 0x44444444;
	//	GPIOx->CRH = 0x44444444;
	//	GPIOx->BRR = 0x00000000;
	//	GPIOx->BSRR = 0x00000000;
	//	GPIOx->LCKR = 0x00000000;
	//	GPIOx->ODR = 0x00000000;

	// If I Have Reset Controller
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}


/*============================================================================
	@ Fn				-MCAL_GPIO_ReadPin
	@ brief				-Read Specific Pin
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-PinNumber: Read Pin Number according to @ref GPIO_PINS_Define
	@ retval			-the input pin value (2 values based on @ref GPIO_PIN_STATE)
	@ Note				-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
	if ( ( (GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{
		return GPIO_PIN_SET;
	}
	else
	{
		return GPIO_PIN_RESET;
	}
}

/*============================================================================
	@ Fn				-MCAL_GPIO_ReadPort
	@ brief				-Read Specific Port
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ retval			-the input port value
	@ Note				-None
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef* GPIOx)
{
	uint16_t portValue;
	portValue = (uint16_t)GPIOx->IDR;
	return portValue;
}

/*============================================================================
	@ Fn				-MCAL_GPIO_WritePin
	@ brief				-Write on Specific Pin
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-PinNumber: specifies Pin Number according to @ref GPIO_PINS_Define
	@ param [in]		-Value: Value to be write on pin
	@ retval			-None
	@ Note				-None
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if ( Value != GPIO_PIN_RESET )
	{
		//or: GPIOx->ODR |= PinNumber;
		GPIOx->BSRR = PinNumber;
	}
	else
	{
		//or: GPIOx->ODR &= ~PinNumber;
		GPIOx->BRR = PinNumber;
	}
}


/*============================================================================
	@ Fn				-MCAL_GPIO_WritePort
	@ brief				-Write on Specific Port
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-Value: Value to be write on port
	@ retval			-None
	@ Note				-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef* GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}
void MCAL_GPIO_Write8Bits (GPIO_TypeDef* GPIOx,unsigned char start, uint16_t Value)
{
	GPIOx->ODR &= ~(0xFF<<start);
	GPIOx->ODR |= (Value << start);
}

void MCAL_GPIO_Write4Bits (GPIO_TypeDef* GPIOx,unsigned char start, uint16_t Value)
{
	GPIOx->ODR &= ~(0xF<<start);
	GPIOx->ODR |= (Value << start);
}

/*============================================================================
	@ Fn				-MCAL_GPIO_TogglePin
	@ brief				-Toggle Specific Pin
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-PinNumber: specifies Pin Number according to @ref GPIO_PINS_Define
	@ retval			-None
	@ Note				-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= ( (uint32_t)PinNumber );
}

/*============================================================================
	@ Fn				-MCAL_GPIO_LockPin
	@ brief				-Lock Specific Pin
	@ param [in]		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
	@ param [in]		-PinNumber: specifies Pin Number according to @ref GPIO_PINS_Define
	@ retval			-OK if pin Config is Locked Or ERROR if PIN not Locked (OK and ERROR are defined @ref GPIO_RETURN_LOCK)
	@ Note				-None
 */
uint8_t MCAL_GPIO_LockPin (GPIO_TypeDef* GPIOx, uint16_t PinNumber)
{
	// freeze the 4 bits of CRL/CRH of this Pin until you reset the port

	// set LCK[16] LCKK bit
	volatile uint32_t tmp = 1<<16;
	//Set the LCKy
	tmp |= PinNumber;

	// Write 1 (on LCKK and LCKy)
	GPIOx->LCKR = tmp;
	// Write 0 (on LCKK)
	GPIOx->LCKR = PinNumber;
	// Write 1 (on LCKK and LCKy)
	GPIOx->LCKR = tmp;
	// Read 0 (of LCKK)
	tmp = GPIOx->LCKR;
	// Read 1 of LCKK
	if ( (uint32_t) (GPIOx->LCKR & (1<<16)) ) {
		return GPIO_RETURN_LOCK_Enabe;
	} else {
		return GPIO_RETURN_LOCK_Error;
	}
}
