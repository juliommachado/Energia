#include <teste_motores.h>
void setup()
{
	declaraPinos();
	Serial.begin(115200);
}

void loop()
{
	double leitura0 = encoderPos0*1.0/3200*60; // converte leitura para rpm
	encoderPos0 = 0;
	double leitura1 = encoderPos1*1.0/3200*60; // converte leitura para rpm
	encoderPos1 = 0;
    Serial.println("\n");
    Serial.println("velocidade: M0");
    Serial.println(leitura0);
    Serial.println("velocidade: M1");
    Serial.println(leitura1);
	delay(1000);
}