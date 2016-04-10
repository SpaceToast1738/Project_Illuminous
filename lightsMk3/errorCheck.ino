int checkPin(int lnNum){
  Serial.begin(9600); //open serial port
  int pinDiff;
  int pinCheck;

  pinDiff = pinUpperLed - pinLowerLed;
  pinCheck = pinBuffer - 1;
  
  if(pinCheck > pinDiff){
    Serial.print("Buffer Overflow: ");
    Serial.println(lnNum);
    return 1;
  }

  if(pinCheck < pinDiff){
    Serial.print("Buffer Underflow: ");
    Serial.println(lnNum);
    return 2;
  }

  if(pinCheck == (pinLowerLed + pinCheck)){
    Serial.print("Check Success: ");
    Serial.println(lnNum);
    return 0;
  }
}



