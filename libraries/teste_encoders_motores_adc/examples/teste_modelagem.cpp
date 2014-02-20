#include <teste_encoders_motores_adc.h>
void setup()
{
	declaraPinos();
	Serial.begin(115200);
}
int val=0;
uint16_t dataBuffer0[250];
uint16_t dataBuffer1[250];

void loop() {
    Serial.flush();
    while(digitalRead(PUSH2)==HIGH);
    encoderPos0 = 0;
    encoderPos1 = 0;    
	for(int j = 2; j<10; j+=2){
		motorMove(0,0,voltsPWM(j));
		motorMove(1,0,voltsPWM(j));
		for(int i = 0;i<50;i++){
			delayMicroseconds(10000);
			dataBuffer0[i+25*(j-2)] = encoderPos0;
			dataBuffer1[i+25*(j-2)] = encoderPos1;
			encoderPos0 = 0;
			encoderPos1 = 0;    
            }
	}
	//Desliga Motores
	motorMove(0,0,0);
	motorMove(1,0,0);
    
	//Espera para coleta de dados:	
	while(digitalRead(PUSH2)==HIGH);
	for(int w = 0; w<2; w++){
        Serial.println("ler valores motor 0?");
        while(Serial.available()<=0);
        if(Serial.read()=='s'){
            for(int i = 0; i<250; i++){
                Serial.println(dataBuffer0[i]);
                delay(100);
                }
            }
        Serial.flush();
        
        Serial.println("ler valores motor 1?");
        while(Serial.available()<=0);
        if(Serial.read()=='s'){
            for(int i = 0; i<250; i++){
                Serial.println(dataBuffer1[i]);
                delay(100);
            }
        }
        Serial.flush();
    }
    Serial.flush();
}
