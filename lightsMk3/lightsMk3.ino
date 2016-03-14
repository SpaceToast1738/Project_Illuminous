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
  //checkPin[pinLowerLed, pinUpperLed, led[pinBuffer], lineNumber]
  errorStatus = checkPin(led[pinBuffer], 11);
}

void loop() {
  if (errorStatus > 0){
    programFail();
    //Serial.println(" err ");
  }  
}

void gameStart(){
  for(i = 0; i <= 12; i++){
    digitalWrite(led[i],HIGH);
    delay(5000);
  }
  for(i = 12; i >= 0; i--){
    digitalWrite(led[i],LOW);
    delay(5000);
  }
}

void programFail(){
  int ledIndex;
  int ledSel;
  int k;
  
  ledIndex = (pinBuffer / 3) - 1;
  for(i = 0; i <= ledIndex; i++){
    ledSel = (i * 3) + 2;
    digitalWrite(led[ledSel], HIGH);
  }
  delay(2000);
  for(i = 0; i <= ledIndex; i++){
    ledSel = (i * 3) + 2;
    digitalWrite(led[ledSel], LOW);
  }
  delay(2000);
}
