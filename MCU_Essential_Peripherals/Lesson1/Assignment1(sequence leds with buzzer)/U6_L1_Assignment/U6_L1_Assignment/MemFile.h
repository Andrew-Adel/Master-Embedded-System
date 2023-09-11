/*
 * MemFile.h
 *
 * Created: 9/11/2023 10:17:51 AM
 *  Author: andre
 */ 


#ifndef MEMFILE_H_
#define MEMFILE_H_

typedef volatile unsigned char vuint8;
// ===================== PORTD MACROS =====================
#define PORTD_BASE	0x20
#define PORTD_DR	(vuint8 *)(PORTD_BASE + 0x12)
#define PORTD_DDRD	(vuint8 *)(PORTD_BASE + 0x11)
#define PORTD_PIN	(vuint8 *)(PORTD_BASE + 0x10)

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

UPort* PD_DR = (UPort*)PORTD_DR;
UPort* PD_DDRD = (UPort*)PORTD_DDRD;
UPort* PD_PIN = (UPort*)PORTD_PIN;




#endif /* MEMFILE_H_ */