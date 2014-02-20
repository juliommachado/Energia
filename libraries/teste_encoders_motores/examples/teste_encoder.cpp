#include <teste_encoders_motores.h>
void setup()
{
	declaraPinos();
	Serial.begin(115200);
}

void loop()
{
    Serial.println("velocidade: M0");
    Serial.println(encoderPos0);
    Serial.println("velocidade: M1");
    Serial.println(encoderPos1);
	delay(1000);
}