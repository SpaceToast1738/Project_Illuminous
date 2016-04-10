void programFail(int errorCode){
  int ledIndex;
  int ledSel;
  int k;
  
  ledIndex = (pinBuffer / 3) - 1;
  reset();
  for(k = 0; k < errorCode; k++){
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
}

void reset(){
  for(i = 0; i <= 12; i++){
    digitalWrite(led[i],HIGH); 
  }
  delay(2000);
  for(i = 12; i >= 0; i--){
    digitalWrite(led[i],LOW);
  }
  delay(5000);
}

