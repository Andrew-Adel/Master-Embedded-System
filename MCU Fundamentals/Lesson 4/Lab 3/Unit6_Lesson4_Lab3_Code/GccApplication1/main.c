/*
 * GccApplication1.c
 *
 * Created: 9/6/2023 6:51:29 PM
 * Author : Andrew
 */ 

#define F_CPU 80000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>


typedef volatile uint32_t vuint32_t;

// ================ PORTD ================

#define IO_BASE 	0x20

#define IO_bitD		(vuint32_t *)(IO_BASE + 0x10)
#define IO_DDRD		(vuint32_t *)(IO_BASE + 0x11)
#define IO_PORTD	(vuint32_t *)(IO_BASE + 0x12)

#define IO_MCUCR	(vuint32_t *)(IO_BASE + 0x35)
#define IO_MCUCSR	(vuint32_t *)(IO_BASE + 0x34)
#define IO_GICR		(vuint32_t *)(IO_BASE + 0x3B)
#define IO_GIFR		(vuint32_t *)(IO_BASE + 0x3A)

#define IO_SREG		(vuint32_t *)(IO_BASE + 0x3F)

typedef struct {
	uint8_t bit0 	: 1;
	uint8_t bit1 	: 1;
	uint8_t bit2 	: 1;
	uint8_t bit3 	: 1;
	uint8_t bit4 	: 1;
	uint8_t bit5 	: 1;
	uint8_t bit6 	: 1;
	uint8_t bit7 	: 1;
}SPORT_t;

union U_IO {
	SPORT_t S_PORT;
	uint8_t PORT;
};

// ================== Registers ==================
volatile union U_IO* IO_DDRD_R = (union U_IO*)IO_DDRD;
volatile union U_IO* IO_MCUCR_R = (union U_IO*)IO_MCUCR;
volatile union U_IO* IO_MCUCSR_R = (union U_IO*)IO_MCUCSR;
volatile union U_IO* IO_GICR_R = (union U_IO*)IO_GICR;
volatile union U_IO* IO_SREG_R = (union U_IO*)IO_SREG;
volatile union U_IO* IO_GIFR_R = (union U_IO*)IO_GIFR;
volatile union U_IO* IO_PORTD_R = (union U_IO*)IO_PORTD;

void INTERRUPT_Init()
{
	// ================== direction ==================

	IO_DDRD_R->S_PORT.bit2 = 0;
	IO_DDRD_R->S_PORT.bit3 = 0;
	IO_DDRD_R->S_PORT.bit5 = 1;
	IO_DDRD_R->S_PORT.bit6 = 1;
	IO_DDRD_R->S_PORT.bit7 = 1;

	// ================== sensitivity of INT ==================

	//	INT0: Any logical change
	IO_MCUCR_R->S_PORT.bit0 = 1;
	IO_MCUCR_R->S_PORT.bit1 = 0;

	// 	INT1: rising edge
	IO_MCUCR_R->S_PORT.bit2 = 1;
	IO_MCUCR_R->S_PORT.bit3 = 1;

	// INT2: falling edge
	IO_MCUCSR_R->S_PORT.bit6 = 0;

	// ================== enable interrupts ==================

	IO_GICR_R->S_PORT.bit5 = 1;
	IO_GICR_R->S_PORT.bit6 = 1;
	IO_GICR_R->S_PORT.bit7 = 1;
	// enable global interrupt
	IO_SREG_R->S_PORT.bit7 = 1;

}

int main()
{
	INTERRUPT_Init();
	while(1){
		IO_PORTD_R->S_PORT.bit5 = 0;
		IO_PORTD_R->S_PORT.bit6 = 0;
		IO_PORTD_R->S_PORT.bit7 = 0;
	}
}

ISR(INT0_vect){
	IO_PORTD_R->S_PORT.bit5 = 1;
	_delay_ms(10);
}

ISR(INT1_vect){
	IO_PORTD_R->S_PORT.bit6 = 1;
	_delay_ms(10);
}

ISR(INT2_vect){
	IO_PORTD_R->S_PORT.bit7 = 1;
	_delay_ms(10);
}
	