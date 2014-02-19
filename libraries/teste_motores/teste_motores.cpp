#include <teste_motores.h>
#include <wiring_private.h>
//Pinos dos motores: [0][i] - direito; [1][i] - esquerdo.
int motorPin[2][2] = {
  {PC_6, PC_7},  
  {PB_3, PC_4}
};
//Canais de PWM dos motores: [0] - direito; [1] - esquerdo.
int motorPWM[2] = {PC_5, PD_6};

void declaraPinos(){
    //Configuração motor direito:
    pinMode(motorPin[0][0], OUTPUT);
    pinMode(motorPin[0][1], OUTPUT);
    pinMode(motorPWM[0], OUTPUT);
 
    //Configuração motor esquerdo:
    pinMode(motorPin[1][0], OUTPUT);
    pinMode(motorPin[1][1], OUTPUT);
    pinMode(motorPWM[1], OUTPUT);

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
