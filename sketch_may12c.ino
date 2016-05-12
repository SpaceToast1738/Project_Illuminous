int LED[48], i, k, ledPinSelect;
int GREEN[16], RED[16], BLUE[16];
const int pinLowerLed = 2, pinUpperLed = 49, ledIndex = 15;

void setup() {
 for(i = pinLowerLed; i <= pinUpperLed; i++){
  k = i - 2;
  LED[k] = i;
  pinMode(LED[k], OUTPUT);
 }

 for(i = 0; i <= ledIndex; i++){
  GREEN[i] = (i * 3);
  RED[i] = (i * 3);
  BLUE[i] = (i * 3);
 }
 
 gameStart();
}

void loop() {
  for(i = 0; i <= ledIndex; i++){
    digitalWrite(RED[i], HIGH);
    delay(20);
  }
}

void gameStart(){
  for(i = pinLowerLed; i <= pinUpperLed; i++){
    digitalWrite(LED[i-2],HIGH);
    delay(20);
  }
  for(i = pinUpperLed; i >= pinLowerLed; i--){
    digitalWrite(LED[i-2],LOW);
    
  }
}

void selectLedColour(){
  switch(random(7)){
    case 0: 
      digitalWrite(ledPinSelect,HIGH);
      digitalWrite(ledPinSelect+1,HIGH);
      digitalWrite(ledPinSelect+2,HIGH);
      break;
    case 1: 
      digitalWrite(ledPinSelect,HIGH);
      digitalWrite(ledPinSelect+1,HIGH); 
      break;
    case 2: 
      digitalWrite(ledPinSelect,HIGH);
      digitalWrite(ledPinSelect+2,HIGH);
      break;
    case 3: 
      digitalWrite(ledPinSelect+1,HIGH);
      digitalWrite(ledPinSelect+2,HIGH);
      break;
    case 4: 
      digitalWrite(ledPinSelect,HIGH);
      break;
    case 5: 
      digitalWrite(ledPinSelect+1,HIGH);
      break;
    case 6: 
      digitalWrite(ledPinSelect+2,HIGH);
      break;
  }
}
