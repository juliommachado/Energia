#include <teste_encoders_motores_adc.h>
#include <wiring_private.h>


//Pinos dos motores: [0][i] - direito; [1][i] - esquerdo.
int motorPin[2][2] = {
  {PC_6, PC_7},  
  {PB_3, PC_4}
};
//Canais de PWM dos motores: [0] - direito; [1] - esquerdo.
int motorPWM[2] = {PC_5, PD_6};

//Encoder Motor 0
int encoderPinA0 = PE_1;
int encoderPinB0 = PE_2;
volatile int encoderPos0 = 0;
volatile boolean A_set0 = false;
volatile boolean B_set0 = false;

//Encoder Motor 1
int encoderPinA1 = PD_3;
int encoderPinB1 = PD_2;
volatile int encoderPos1 = 0;
volatile boolean A_set1 = false;
volatile boolean B_set1 = false;

//Constante de conversão:


void declaraPinos(){
    //Configuração motor direito:
    pinMode(motorPin[0][0], OUTPUT);
    pinMode(motorPin[0][1], OUTPUT);
    pinMode(motorPWM[0], OUTPUT);
 
    //Configuração motor esquerdo:
    pinMode(motorPin[1][0], OUTPUT);
    pinMode(motorPin[1][1], OUTPUT);
    pinMode(motorPWM[1], OUTPUT);
	
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

int  motorMove(int motor, int dir, int pwm){
    if(motor>1||motor<0||dir>1||dir<0||pwm>0xFFF||pwm<0){
        return 1;
    }else{
        digitalWrite(motorPin[motor][0],dir);
        digitalWrite(motorPin[motor][1],1-dir);
        PWMWrite(motorPWM[motor], 0xFFF, pwm, 10000);
        return 0;
    }
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
float ultimo_valor = 11.4;
float vBat_filtrada(){
	float saida= 0.1*analogRead(PE_3)*0.0032817+0.9*ultimo_valor;
    ultimo_valor = saida;
	return saida;
}
float vBat(){
	return analogRead(PE_3)*0.0032817;
}
uint16_t voltsPWM(double vDes){
	float v_bat=vBat();
	if(vDes>v_bat) return 4095;
    return (int)(vDes/v_bat*4095);
    }






