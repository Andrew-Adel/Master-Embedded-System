/*
 * platform_types.h
 *
 *  Created on: Aug 14, 2023
 *      Author: andre
 */

#ifndef _PLATFORM_TYPES_H // header protection
#define _PLATFORM_TYPES_H
#include <stdint.h>

// CPU
#define CPU_TYPE 			CPU_TYPE_32
#define CPU_BIT_ORDER		MSB_FIRST
#define CPU_BYTE_ORDER		HIGH_BYTE_FIRST

// define values of boolean
#ifndef FALSE
#define FALSE 	(boolean) 0
#endif

#ifndef TRUE
#define TRUE 	(boolean) 1
#endif

// data types
typedef unsigned char 		boolean;
typedef unsigned char 		uint8;
typedef signed char 		sint8;
typedef unsigned short 		uint16;
typedef signed short 		sint16;
typedef unsigned long 		uint32;
typedef signed long	 		sint32;
typedef unsigned long long 	uint64;
typedef signed long long 	sint64;

//real number
typedef float				float32;
typedef double				float64;

// volatile data types
typedef unsigned char 					vboolean;
typedef volatile unsigned char 			vuint8;
typedef volatile signed char 			vint8;
typedef volatile unsigned short 		vuint16;
typedef volatile signed short 			vint16;
typedef volatile unsigned long 			vuint32;
typedef volatile signed long	 		vint32;
typedef volatile unsigned long long 	vuint64;
typedef volatile signed long long 		vint64;
typedef volatile float			 		vflaot32;
typedef volatile double 				vfloat64;


#endif // end if for header protection
