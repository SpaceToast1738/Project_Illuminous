int checkPin(int pinBuffer, int lnNum){
  Serial.begin(9600); //open serial port
  int pinDiff;

  pinDiff = pinUpperLed - pinLowerLed;
  pinBuffer--;
  
  if(pinBuffer > pinDiff){
    Serial.print("Buffer Overflow: ");
    Serial.println(lnNum);
    return 1;
  }

  if(pinBuffer < pinDiff){
    Serial.print("Buffer Underflow: ");
    Serial.println(lnNum);
    return 1;
  }

  if(pinUpperLed == (pinLowerLed + pinBuffer)){
    Serial.print("Check Success: ");
    Serial.println(lnNum);
    return 0;
  }
}



