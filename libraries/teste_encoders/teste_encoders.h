//biblioteca de teste de wiring_analog.c

#ifndef _MYLIB_H_
#define _MYLIB_H_
#include <wiring_private.h>
#include <Energia.h>

//Encoder Motor 0
extern volatile int encoderPos0;
//Encoder Motor 1
extern volatile int encoderPos1;

extern void declaraPinos();
extern void doEncoderA0();
extern void doEncoderB0();
extern void doEncoderA1();
extern void doEncoderB1();

#endif