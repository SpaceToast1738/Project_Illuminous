//#include <Arduino.h>
int led[12]; //size of array = LEDNUM * 3 
int errorStatus = 0;
const int pinLowerLed = 30, pinUpperLed = 41, pinBuffer = 12;
int i;

void setup(){
  Serial.begin(9600);
  for(i = 0; i < pinBuffer; i++){
    led[i] = i + pinLowerLed;
    pinMode(led[i], OUTPUT);
    delay(1);
  }
  //checkPin[lineNumber]
  errorStatus = checkPin(11);
}

void loop() {
  if (errorStatus > 0)
    programFail(errorStatus);
  
}



