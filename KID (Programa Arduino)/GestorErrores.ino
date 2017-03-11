void Warning(String error){
  if(error = "suelto"){
    tone(BZZ, 1000, 1000);
    Serial.println(F("LA PULSERA ESTÁ MUY SUELTAAAAAAAA"));
    delay(10);
    }
  if(error = "Serial Exception"){
    while(1==1){
      ColorLed(255,0,0)
      delay(500);
      ColorLed(0,0,0)
      delay(500);
    }
   }
}
