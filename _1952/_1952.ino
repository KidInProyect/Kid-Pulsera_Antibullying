#define LEDR 9
#define LEDB 10
#define LEDG 11
#define BTNW 8
#define BZZ  7
#define COND 2
#define BTT A0

String   name = "Fulanito Tontorron";
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
  
  Serial.begin(9600);
  while(!Serial);
  
  Serial.println("Arrancando el sistema");
  //Esperamos a poner la pulsera (Armamos el cepo)
  
  
  ColorLed(255, 0, 0);
  delay(300);
  ColorLed(0, 255, 0);
  delay(300);
  ColorLed(0, 0, 255);
  delay(300);
  
  while(digitalRead(COND)!=LOW);
  ColorLed(0, 128, 0);
  Tinicio = millis();
  attachInterrupt(digitalPinToInterrupt(COND),Suelto,FALLING);
  
  
}

void loop (){
  
}
void ColorLed(byte R, byte G, byte B){
  analogWrite(LEDR, R);
  analogWrite(LEDG, G);
  analogWrite(LEDB, B);
  
  }

  
void Suelto(){
  detachInterrupt(digitalPinToInterrupt(COND));
  
  int strikes = 0;
  
  for(int i = 0; i<= 5; i++){
   if (pulseIn(COND, LOW, 1000000)!= 0){
      strikes++;
  }
   else { 
      i = 5;
   }
   
  }
  if (strikes == 5){
   ColorLed(255,0,0);
    Warning("suelto");
    }
  attachInterrupt(digitalPinToInterrupt(COND),Suelto,FALLING);
  }

