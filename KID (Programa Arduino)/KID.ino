#include <doxygen.h>
#include <ESP8266.h>
#include <EEPROM.h>
#include <Blynk.h>
#include <LowPower.h> //TODO: Implementar modificando los registros, ahorrar ram

#define EEPROMStart 0
#define WifiLength 32
#define PassLength 64

//#define BLYNK_DEBUG
//#define BLYNK_PRINT Serial
#define ESPSerial Serial

char token[] = "XXXXXXXXXXXXXXXXX";
char SSID[WifiLength];
char PASS[WifiLength];
/*
Segun LOPD tenemos que garantizar la privacidad de la info (somos lvl bajo)
   La LSSI nos recomienda hacer backups regulares
*/

int      ip[] = {192,168,1,3};
boolean  state = true;              //En el insti?
boolean  warning = false;           //En bulling?
String   credenciales[] = {"Curso","Clase","Nivel"};
unsigned long Tinicio = 0;

void setup (){
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(BTNW, INPUT);
  pinMode(BZZ, OUTPUT);
  pinMode(COND, INPUT); 
  pinMode(CONFIGPIN, INPUT_PULLUP);

  //Test LED:
  ColorLed(255, 0, 0);
  delay(300);
  ColorLed(0, 255, 0);
  delay(300);
  ColorLed(0, 0, 255);  
  delay(300);
  ColorLed(0, 64, 0);  

  //Test Buzzer
  tone(BZZ, 1000, 200);
  
  //Montamos el Serial
  Serial.begin(9600);
  while(!Serial);  
  Serial.println(F("Arrancando"));  //Probamos el Serial
  
  //Comprobamos si estamos en modo configuración
  if (digitalRead(CONFIGPIN)==LOW){
    configMode();
  }else{ //Si no lo estamos usamos la config definida en la EEPROM
    
    char a= '0';
    for(int i = 0; a!='\0'; i++){
      a = EEPROM.read(i);
      PASS[i]= a;
      }
      
    a = '0';
    for(int i = 0; a!='\0'; i++){
      a = EEPROM.read(i+WifiLength);
      PASS[i]= a;
      }
    
    }
  
  while(digitalRead(COND)!=LOW);
  Tinicio = millis();
  attachInterrupt(digitalPinToInterrupt(COND),Suelto,FALLING);
  Serial.println(F("La pulsera está atada"));

   
  Serial.println(F("Arrancando el sistema"));

  
  
}

void loop (){
  
}
void ColorLed(byte R, byte G, byte B){
  analogWrite(LEDR, R);
  analogWrite(LEDG, G);
  analogWrite(LEDB, B);
  }

  

