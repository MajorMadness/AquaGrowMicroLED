
// Taking care of some special events.
void keypadEvent(KeypadEvent key){
  byte chanel;
    switch (keypad.getState()){
    case PRESSED:
        if (key == 'A') {
          manualRelay=true;
          lcd.setCursor(12,0); 
          if(digitalRead(relayPIN[0])==HIGH){
            digitalWrite(relayPIN[0],LOW);
      printRelay(0,0);
          }else{
            digitalWrite(relayPIN[0],HIGH);
      printRelay(0,1);
          }
          Serial.println(digitalRead(relayPIN[0]));
          manualRelay=true;
        }else if (key == 'B') {
          manualRelay=true;
          lcd.setCursor(13,0); 
          if(digitalRead(relayPIN[1])==HIGH){
            digitalWrite(relayPIN[1],LOW);
      printRelay(1,0);
          }else{
            digitalWrite(relayPIN[1],HIGH);
      printRelay(1,1);
          }
          Serial.println(digitalRead(relayPIN[1]));
          manualRelay=true;
        }else if (key == 'C') {
          manualRelay=true;
          lcd.setCursor(14,0); 
          if(digitalRead(relayPIN[2])==HIGH){
            digitalWrite(relayPIN[2],LOW);
      printRelay(2,0);
          }else{
            digitalWrite(relayPIN[2],HIGH);
      printRelay(2,1);
          }
          Serial.println(digitalRead(relayPIN[2]));
          manualRelay=true;
        }else if (key == 'D') {
          manualRelay=true;
          lcd.setCursor(15,0); 
          if(digitalRead(relayPIN[3])==HIGH){
            digitalWrite(relayPIN[3],LOW);
      printRelay(3,0);
          }else{
            digitalWrite(relayPIN[3],HIGH);
      printRelay(3,1);
          }
          Serial.println(digitalRead(relayPIN[3]));
        }else if (key == '1') {
          t.pulse(dosingPins[0],60000 / dosingMlMin[0], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(0,1);
        }else if (key == '2') {
          t.pulse(dosingPins[1],60000 / dosingMlMin[1], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(1,1);
        }else if (key == '3') {
          t.pulse(dosingPins[2],60000 / dosingMlMin[2], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(2,1);
        }else if (key == '4') {
          t.pulse(dosingPins[3],60000 / dosingMlMin[3], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(3,1);
        }else if (key == '5') {
          t.pulse(dosingPins[4],60000 / dosingMlMin[4], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(4,1);
        }else if (key == '6') {
          t.pulse(dosingPins[5],60000 / dosingMlMin[5], LOW);
      Serial.print(F("DOSINGA"));
      Serial.println(key);
          printDose(5,1);
        }else if (key == '7') {
          if(dimming[0].state==1){
            dimming[0].state=0;
            ledDriver.setLEDOff(0*2);
            ledDriver.setLEDOff(0*2+1);
            manualLight=true;
          }else if(dimming[0].state==0){
            dimming[0].state=1;
            ledDriver.setLEDOn(0*2);
            ledDriver.setLEDOn(0*2+1);
            manualLight=true;
          } 
        }else if (key == '8') {
          if(dimming[1].state==1){
            dimming[1].state=0;
            ledDriver.setLEDOff(1*2);
            ledDriver.setLEDOff(1*2+1);
            manualLight=true;
          }else if(dimming[1].state==0){
            dimming[1].state=1;
            ledDriver.setLEDOn(1*2);
            ledDriver.setLEDOn(1*2+1);
            manualLight=true;
          } 
        }else if (key == '9') {
          if(dimming[2].state==1){
            dimming[2].state=0;
            ledDriver.setLEDOff(2*2);
            ledDriver.setLEDOff(2*2+1);
            manualLight=true;
          }else if(dimming[2].state==0){
            dimming[2].state=1;
            ledDriver.setLEDOn(2*2);
            ledDriver.setLEDOn(2*2+1);
            manualLight=true;
          } 
        }else if (key == '*') {
          if(dimming[3].state==1){
            dimming[3].state=0;
            ledDriver.setLEDOff(3*2);
            ledDriver.setLEDOff(3*2+1);
            manualLight=true;
          }else if(dimming[3].state==0){
            dimming[3].state=1;
            ledDriver.setLEDOn(3*2);
            ledDriver.setLEDOn(3*2+1);
            manualLight=true;
          } 
        }else if (key == '#') {
            manualLight=false;
        }else if (key == '0') {
          manualRelay=false;
          lcd.setCursor(15,1); 
          lcd.print(F("A"));
        }
        break;
        
        
    case HOLD:
//      Serial.print(F("keyHOLD"));
//      Serial.println(key);
      if (key == 'A') {
          EEPROM_writeAnything(100, dose_val);
        }else if (key == 'B') {
          EEPROM_writeAnything(102, dose_val);
        }else if (key == 'C') {
          EEPROM_writeAnything(104, dose_val);
        }else if (key == 'D') {
          EEPROM_writeAnything(106, dose_val);
 /*       }else if (key == '*') {
          EEPROM_writeAnything(108, dose_val);
        }else if (key == '#') {
          EEPROM_writeAnything(110, dose_val);
 */       }
        break;
    }

}
