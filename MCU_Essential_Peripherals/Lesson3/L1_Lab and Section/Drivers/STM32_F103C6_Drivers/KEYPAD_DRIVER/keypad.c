/*
 * keypad.c
 *
 * Created: 9/14/2023 2:29:29 AM
 *  Author: andre
 */

#include "keypad.h"

char KeysValues[4][4] =
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'o','0','=','+'}
};

uint16_t Key_padCol[] = {C0, C1, C2, C3};
uint16_t Key_padRow[] = {R0, R1, R2, R3};
void KP_delay(int x)
{
	int i,j;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < 1000; ++j);
	}
}
GPIO_PinConfig_t PinConfig;
void KEYPAD_8PINS_Config(uint32_t MODE, uint32_t SPEED)
{
//	PinConfig.GPIO_PIN = R0;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
////	PinConfig.GPIO_Output_Speed = SPEED;
//	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = R1;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
////	PinConfig.GPIO_Output_Speed = SPEED;
//	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = R2;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
////	PinConfig.GPIO_Output_Speed = SPEED;
//	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);
//
//	PinConfig.GPIO_PIN = R3;
//	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
////	PinConfig.GPIO_Output_Speed = SPEED;
//	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);
	PinConfig.GPIO_PIN = R0;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = R1;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = R2;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = R3;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = C0;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = C1;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = C2;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PIN = C3;
	PinConfig.GPIO_MODE = MODE;
	PinConfig.GPIO_Output_Speed = SPEED;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);
}

void Keypad_init()
{
//	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
//	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_8PINS_Config(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_10M);
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0x1FF);
//	KEYPAD_PORT = 0xFF;

}
char Keypad_getkey()
{
	int i=0,j=0;
//	Keypad_init();
	for (i=0;i<4;i++)
	{
//		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
//		KEYPAD_PORT &= ~(1<<Key_padCol[i]);

		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);

		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);

		for (j=0;j<4;j++)
		{
			KP_delay(5);
			if ( MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == GPIO_PIN_RESET )
			{
				while( MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == GPIO_PIN_RESET );
				return KeysValues[j][i];

			}
		}
	}
	return 'N';
}
