#include <teste_encoders_motores_adc.h>
void setup()
{
	declaraPinos();
	Serial.begin(115200);
}

void loop()
{
	int teste = analogRead(PE_3);
    Serial.println(teste);
	delay(1000);
}