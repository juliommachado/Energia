#include <teste_encoders.h>
#include <wiring_private.h>


//Encoder Motor 0
int encoderPinB1 = PD_2;
int encoderPinA1 = PD_3;
volatile int encoderPos0 = 0;
volatile boolean A_set0 = false;
volatile boolean B_set0 = false;

//Encoder Motor 1
int encoderPinA0 = PE_1;
int encoderPinB0 = PE_2;
volatile int encoderPos1 = 0;
volatile boolean A_set1 = false;
volatile boolean B_set1 = false;

void declaraPinos(){
    //Encoder Direito
    pinMode(encoderPinA0, INPUT_PULLUP); //channel 1
	pinMode(encoderPinB0, INPUT_PULLUP); //channel 2
	attachInterrupt(encoderPinA0, doEncoderA0, CHANGE);
    attachInterrupt(encoderPinB0, doEncoderB0, CHANGE);

	//Encoder Esquerdo
	pinMode(encoderPinA1, INPUT_PULLUP); //channel 1
	pinMode(encoderPinB1, INPUT_PULLUP); //channel 2
	attachInterrupt(encoderPinA1, doEncoderA1, CHANGE);
    attachInterrupt(encoderPinB1, doEncoderB1, CHANGE);

    //Configuração de botões:
    pinMode(PUSH1, INPUT_PULLUP);
    pinMode(PUSH2, INPUT_PULLUP);
}

void doEncoderA0(){
  // Test transition
  A_set0 = digitalRead(encoderPinA0) == HIGH;
  // and adjust counter + if A leads B
  encoderPos0 += (A_set0 != B_set0) ? +1 : -1;
}

// Interrupt on B changing state
void doEncoderB0(){
  // Test transition
  B_set0 = digitalRead(encoderPinB0) == HIGH;
  // and adjust counter + if B follows A
  encoderPos0 += (A_set0 == B_set0) ? +1 : -1;
}


void doEncoderA1(){
  // Test transition
  A_set1 = digitalRead(encoderPinA1) == HIGH;
  // and adjust counter + if A leads B
  encoderPos1 += (A_set1 != B_set1) ? +1 : -1;
}

// Interrupt on B changing state
void doEncoderB1(){
  // Test transition
  B_set1 = digitalRead(encoderPinB1) == HIGH;
  // and adjust counter + if B follows A
  encoderPos1 += (A_set1 == B_set1) ? +1 : -1;
}
