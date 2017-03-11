void configMode(){
  
  boolean paso = false; //Almacena el estado completasdodel paso en el que nos encontramos
  char buffer[WifiLength];        //Para las conversiones de string a char[]
  
  Serial.println(F("Introduce el nombre de la red:"));
  do{
    while (Serial.available()==0);
    
    String NameWifi = Serial.readString();
    
    if (NameWifi.length()-1 < WifiLength){
      NameWifi.toCharArray(buffer, NameWifi.length()-1);
      
      for (int i = 0; i<=sizeof(buffer); i++){
        EEPROM.write(EEPROMStart+i, buffer[i]);
        if (i == sizeof(buffer)){
          EEPROM.write(EEPROMStart+ i + 1,'\0');
          }
        }
      
      paso = true;
    }else{
      Serial.println(F("Introduce un nombre de red válido!!"));
      paso = false;
      }
      
  }while(paso != true);

  //////////////////////////////////////////////////////////////////
  for(int i = 0; i <= sizeof(buffer[i]); i++){
    SSID[i]= buffer[i];
    }
  char buffer2[PassLength];        //Para las conversiones de string a char[]
  paso = false;
  
  Serial.println(F("Introduce la pass de la red:"));
  do{
    while (Serial.available()==0);
    
    String PassWifi = Serial.readString();
    
    if (PassWifi.length()-1 < PassLength){
      PassWifi.toCharArray(buffer2, PassWifi.length()-1);
      
      for (int i = 0; i<=sizeof(buffer2); i++){
        EEPROM.write(EEPROMStart+ i + WifiLength, buffer2[i]);
        if (i == sizeof(buffer2)){
          EEPROM.write(EEPROMStart+ i + WifiLength + 1,'\0');
          }
        }
        
      paso = true;
    }else{
      Serial.println(F("Introduce una pass válida!!"));
      paso = false;
      }     
  }while(paso != true);
  ///////////////////////////////////////////////////////////////////
    for(int i = 0; i <= sizeof(buffer2[i]); i++){
    PASS[i]= buffer2[i];
    }
}
