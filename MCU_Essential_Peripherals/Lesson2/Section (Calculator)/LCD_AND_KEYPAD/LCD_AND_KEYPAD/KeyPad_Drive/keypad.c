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

unsigned char Key_padCol[] = {C0, C1, C2, C3};
unsigned char Key_padRow[] = {R0, R1, R2, R3}; 

void Keypad_init()
{
	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));	
	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_PORT = 0xFF;
}
char Keypad_getkey()
{
	int i,j;
	for (i=0;i<4;i++)
	{
		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		
		for (j=0;j<4;j++)
		{
			if ( !(keypadPIN & (1<<Key_padRow[j])) )
			{
				return KeysValues[j][i];
			}
		}
	}
	return 'N';
}
