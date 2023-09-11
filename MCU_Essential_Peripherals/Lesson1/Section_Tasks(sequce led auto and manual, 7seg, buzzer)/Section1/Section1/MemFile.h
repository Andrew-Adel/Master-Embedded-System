/*
 * MemFile.h
 *
 * Created: 9/11/2023 3:28:04 PM
 *  Author: andrew
 */ 


#ifndef MEMFILE_H_
#define MEMFILE_H_

typedef volatile unsigned char vuint8;

// ===================== PORTA MACROS =====================
#define PORT_BASE	0x20

#define PORTA_DR	(vuint8 *)(PORT_BASE + 0x1B)
#define PORTA_DDRD	(vuint8 *)(PORT_BASE + 0x1A)
#define PORTA_PIN	(vuint8 *)(PORT_BASE + 0x19)

#define PORTB_DR	(vuint8 *)(PORT_BASE + 0x18)
#define PORTB_DDRD	(vuint8 *)(PORT_BASE + 0x17)
#define PORTB_PIN	(vuint8 *)(PORT_BASE + 0x16)

#define PORTC_DR	(vuint8 *)(PORT_BASE + 0x15)
#define PORTC_DDRD	(vuint8 *)(PORT_BASE + 0x14)
#define PORTC_PIN	(vuint8 *)(PORT_BASE + 0x13)

#define PORTD_DR	(vuint8 *)(PORT_BASE + 0x12)
#define PORTD_DDRD	(vuint8 *)(PORT_BASE + 0x11)
#define PORTD_PIN	(vuint8 *)(PORT_BASE + 0x10)

typedef struct {
	vuint8 pin0:1;
	vuint8 pin1:1;
	vuint8 pin2:1;
	vuint8 pin3:1;
	vuint8 pin4:1;
	vuint8 pin5:1;
	vuint8 pin6:1;
	vuint8 pin7:1;
} SPortPins;

typedef union {
	SPortPins pins;
	vuint8 port;
}UPort;

UPort* PA_DR = (UPort*)PORTA_DR;
UPort* PA_DDRD = (UPort*)PORTA_DDRD;
UPort* PA_PIN = (UPort*)PORTA_PIN;

UPort* PB_DR = (UPort*)PORTB_DR;
UPort* PB_DDRD = (UPort*)PORTB_DDRD;
UPort* PB_PIN = (UPort*)PORTB_PIN;

UPort* PC_DR = (UPort*)PORTC_DR;
UPort* PC_DDRD = (UPort*)PORTC_DDRD;
UPort* PC_PIN = (UPort*)PORTC_PIN;

UPort* PD_DR = (UPort*)PORTD_DR;
UPort* PD_DDRD = (UPort*)PORTD_DDRD;
UPort* PD_PIN = (UPort*)PORTD_PIN;



#endif /* MEMFILE_H_ */