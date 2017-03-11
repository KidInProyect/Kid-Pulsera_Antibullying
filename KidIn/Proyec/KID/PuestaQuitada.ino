//Fichero con las interrupciones usadas para detectar si la pulsera está
//Puesta o no.



void Suelto(){
  detachInterrupt(digitalPinToInterrupt(COND));
  Serial.println(F("La pulsera está posiblemente suelta"));
  int strikes = 0;
  
  for(int i = 0; i<= 5; i++){
   if (pulseIn(COND, LOW, 500000)!= 0){
      strikes++;
      Serial.println(F("Strike++"));
      tone(BZZ, 1000, 300);
      delay(500);
  }
   else { 
      i = 5;
   }
   
  }
  
  if (strikes == 5){
   ColorLed(255,0,0);
   Warning("suelto");
    }
  
  //attachInterrupt(digitalPinToInterrupt(COND), Atado, RISING);
  }
  
void Atado(){
  detachInterrupt(digitalPinToInterrupt(COND));
      int strikes = 0;
    
    for(int i = 0; i<= 5; i++){
      if (pulseIn(COND, HIGH, 100000)!= 0){
        strikes++;
    
      }else { 
        i = 5;
       }
    
    }
    
    if (strikes == 5) attachInterrupt(digitalPinToInterrupt(COND), Atado, RISING);
    else attachInterrupt(digitalPinToInterrupt(COND), Suelto, FALLING);
  }
