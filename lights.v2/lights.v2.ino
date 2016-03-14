//4 LEDs each with 3 input pins 3 * 4 = 12
//LEDs starts from pin 30 ends at pin 41

int LED[12]; //LED[led * 3]
int i, k, ledIndex, ledPinSelect, timeMultiplier = 60, vRead, button[4];
const int pinLowerLED = 30, pinUpperLED = 41; //defines highest and lowest LED pin

void setup() {
  Serial.begin(9600);

  for(i = pinLowerLED; i <= pinUpperLED; i++){
    k = i - pinLowerLED;
    LED[k] = i;
    pinMode(LED[k], OUTPUT);
  }
  
  for(i = 0; i <= 3; i++){
    button[i] = i;
    pinMode(button[i], INPUT);
  }
  randomSeed(analogRead(15));
  gameStart();
}

void loop(){
  selectLed();
  
  for(i = 0; i <= timeMultiplier; i++){
   delay(25);
    vRead = analogRead(button[(ledPinSelect - pinLowerLED) / 3]);
    if(vRead > 100){
      Serial.println(vRead);
      timeMultiplier--;
      Serial.println(timeMultiplier);
      Serial.println(i);
      break;
    }
    
    if(i == timeMultiplier)
      gameOver();
  }
  
  for(i = pinLowerLED; i <= pinUpperLED; i++){
    digitalWrite(LED[i - pinLowerLED], LOW);
  }
  delay(200);
}

void gameStart(){
  for(i = 0; i <= 12; i++){
    digitalWrite(LED[i],HIGH);
    delay(200);
  }
  for(i = 12; i >= 0; i--){
    digitalWrite(LED[i],LOW);
    delay(200);
  }
}

void selectLed(){
  ledIndex = (pinUpperLED - pinLowerLED) / 3;
  ledPinSelect = pinLowerLED + (random(ledIndex) * 3);
  selectLedColour();
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
void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  asm volatile ("  jmp 0");  
}  

void gameOver(){
  for(i = 0 ; i <= 24; i++){
    selectLed();
    delay(200);
    for(k = pinLowerLED; k <= pinUpperLED; k++){
      digitalWrite(LED[k - pinLowerLED], LOW);
    }
  }
  software_Reset();
}


