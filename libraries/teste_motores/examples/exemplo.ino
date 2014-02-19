#include <teste_motores.h>
void setup()
{
	declaraPinos();
}

void loop()
{
  motorMove(0,0,0x7FF);
  motorMove(1,0,0x7FF);
  delay(10000);
}