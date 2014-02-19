//biblioteca de teste de wiring_analog.c

#ifndef _MYLIB_H_
#define _MYLIB_H_
#include <wiring_private.h>
#include <Energia.h>
extern int motorPin[2][2];
extern int motorPWM[2];

extern int  motorMove(int motor, int dir, int pwm);
extern void declaraPinos();
#endif