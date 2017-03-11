//Esto es un test rápido de la librería LowPower
//Nos permitirá correr el proyecto varios días con una sola carga

#include <LowPower.h>



void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);
pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9, HIGH);
LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_ON);
digitalWrite(9, LOW);
LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_ON);

}
