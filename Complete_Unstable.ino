int i, k, ledPinSelect, vRead, button, sectorSelect, colourSelect = 0, previous = 0, sectorCheck = 0, timeMultiplier = 50, complete = 0, first, count, lightNumber;
int GREEN[16], RED[16], BLUE[16];
const int pinLowerLed = 2, pinUpperLed = 49, index = 15, RESETTIME = 50;

void setup() {
  randomSeed(analogRead(random(16)));
  Serial.begin(9600);
  analogReference(DEFAULT);
  for(i = pinLowerLed; i <= pinUpperLed; i++){
    pinMode(i, OUTPUT);
  }
  for(i = 0; i <= index; i++){
    GREEN[i] = (i * 3)+2;
    RED[i] = (i * 3)+3;
    BLUE[i] = (i * 3)+4;
  }
  pinMode(A0, INPUT); pinMode(A1, INPUT); pinMode(A2, INPUT); pinMode(A3, INPUT);
  pinMode(A4, INPUT); pinMode(A5, INPUT); pinMode(A6, INPUT); pinMode(A7, INPUT);
  pinMode(A8, INPUT); pinMode(A9, INPUT); pinMode(A10, INPUT); pinMode(A11, INPUT);
  pinMode(A12, INPUT); pinMode(A13, INPUT); pinMode(A14, INPUT); pinMode(A15, INPUT);
  
  gameStart();
  first = 1;
}

void loop() {
  if(first){
    sector();
    first = 0;
  };
  for(i = 0; i <= timeMultiplier; i++){
    for(button = 0; button <= index; button++){
      vRead = analogRead(button);
      if(vRead > 1000 && !(button == sectorCheck)){
        digitalWrite(BLUE[sectorCheck],LOW);
        digitalWrite(GREEN[sectorCheck],LOW);
        digitalWrite(RED[sectorCheck],LOW);
        delay(200);
        i = 0;
        score();
        timeMultiplier = RESETTIME;
        //gameEnd();
        sector();
      }
      if(vRead > 1000 && (button == sectorCheck)){
        digitalWrite(BLUE[sectorCheck],LOW);
        digitalWrite(GREEN[sectorCheck],LOW);
        digitalWrite(RED[sectorCheck],LOW);
        delay(200);
        i = 0;
        timeMultiplier--;
        sector();
      }
    }    
    delay(20);
  }
  digitalWrite(BLUE[sectorCheck],LOW);
  digitalWrite(GREEN[sectorCheck],LOW);
  digitalWrite(RED[sectorCheck],LOW);
  delay(200);
  score();
  timeMultiplier = RESETTIME;
  //gameEnd();
  sector();
}

void score(){
  for(i = index; i >= 0; i--){
    digitalWrite(BLUE[i],LOW);
    digitalWrite(GREEN[i],LOW);
    digitalWrite(RED[i], LOW);
  }
  
  count = (50 - timeMultiplier);
  lightNumber = count % 10;
  Serial.println(lightNumber);
  Serial.println(count);
  Serial.println();

  if(count <= 10){
    for(i = 0; i <= index; i++){
      digitalWrite(RED[i],HIGH);
    }
  }
  
  if(count >= 11 && count <=20){
    for(i = 0; i <= index; i++){
      digitalWrite(RED[i],HIGH);
      digitalWrite(GREEN[i],HIGH);
    }
  }
  
  if(count >= 21 && count <= 30 ){
    for(i = 0; i <= index; i++){
      digitalWrite(BLUE[i],HIGH);
      digitalWrite(RED[i],HIGH);
    }
  }
  
  if(count >= 31 && count <= 40){
    for(i = 0; i <= index; i++){
      digitalWrite(BLUE[i],HIGH);
    }
  }
  
  if(count >= 41 && count <=50){
    for(i = 0; i <= index; i++){
      digitalWrite(GREEN[i],HIGH);
    }
  }
  
  switch(lightNumber){
    case 0:
      if(count > 0){
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
        digitalWrite(RED[5],HIGH);
        digitalWrite(RED[6],HIGH);
        digitalWrite(RED[7],HIGH);
        digitalWrite(RED[9],HIGH);
        digitalWrite(RED[10],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
        digitalWrite(BLUE[5],HIGH);
        digitalWrite(BLUE[6],HIGH);
        digitalWrite(BLUE[7],HIGH);
        digitalWrite(BLUE[9],HIGH);
        digitalWrite(BLUE[10],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        digitalWrite(GREEN[5],HIGH);
        digitalWrite(GREEN[6],HIGH);
        digitalWrite(GREEN[7],HIGH);
        digitalWrite(GREEN[9],HIGH);
        digitalWrite(GREEN[10],HIGH);
      }
      break;
    case 1:
        digitalWrite(RED[0],HIGH);
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(GREEN[0],HIGH);
        break;
    case 2:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        break;
    case 3:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        break;
    case 4:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        break;
    case 5:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        break;
    case 6:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
        digitalWrite(RED[5],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
        digitalWrite(BLUE[5],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        digitalWrite(GREEN[5],HIGH);
        break;
    case 7:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
        digitalWrite(RED[5],HIGH);
        digitalWrite(RED[6],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
        digitalWrite(BLUE[5],HIGH);
        digitalWrite(BLUE[6],HIGH);
  
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        digitalWrite(GREEN[5],HIGH);
        digitalWrite(GREEN[6],HIGH);
        break;
    case 8:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
        digitalWrite(RED[5],HIGH);
        digitalWrite(RED[6],HIGH);
        digitalWrite(RED[7],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
        digitalWrite(BLUE[5],HIGH);
        digitalWrite(BLUE[6],HIGH);
        digitalWrite(BLUE[7],HIGH);
        
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        digitalWrite(GREEN[5],HIGH);
        digitalWrite(GREEN[6],HIGH);
        digitalWrite(GREEN[7],HIGH);
        break;
    case 9:
        digitalWrite(RED[0],HIGH);
        digitalWrite(RED[1],HIGH);
        digitalWrite(RED[2],HIGH);
        digitalWrite(RED[3],HIGH);
        digitalWrite(RED[4],HIGH);
        digitalWrite(RED[5],HIGH);
        digitalWrite(RED[6],HIGH);
        digitalWrite(RED[7],HIGH);
        digitalWrite(RED[9],HIGH);
  
        digitalWrite(BLUE[0],HIGH);
        digitalWrite(BLUE[1],HIGH);
        digitalWrite(BLUE[2],HIGH);
        digitalWrite(BLUE[3],HIGH);
        digitalWrite(BLUE[4],HIGH);
        digitalWrite(BLUE[5],HIGH);
        digitalWrite(BLUE[6],HIGH);
        digitalWrite(BLUE[7],HIGH);
        digitalWrite(BLUE[9],HIGH);
        
        digitalWrite(GREEN[0],HIGH);
        digitalWrite(GREEN[1],HIGH);
        digitalWrite(GREEN[2],HIGH);
        digitalWrite(GREEN[3],HIGH);
        digitalWrite(GREEN[4],HIGH);
        digitalWrite(GREEN[5],HIGH);
        digitalWrite(GREEN[6],HIGH);
        digitalWrite(GREEN[7],HIGH);
        digitalWrite(GREEN[9],HIGH);
        break;
    default: 
        digitalWrite(RED[0],LOW);
        digitalWrite(BLUE[0],LOW);
        digitalWrite(GREEN[0],LOW);
      break;
  }
  delay(3000);
  gameStart();
}

void sector(){
  sectorSelect = random(16);
  sectorCheck = sectorSelect;
  while(previous == colourSelect || ((previous == 0 && colourSelect == 4) || (previous == 0 && colourSelect == 6) || (previous == 4 && colourSelect == 0) || (previous == 4 && colourSelect == 6) || (previous == 6 && colourSelect == 0) || (previous == 6 && colourSelect == 4))){
    colourSelect = random(7);
  }
  previous = colourSelect;
  switch (colourSelect){
    case 0:
      digitalWrite(BLUE[sectorSelect], HIGH);
      break;
    case 1:
      digitalWrite(RED[sectorSelect], HIGH);
      break;
    case 2:
      digitalWrite(GREEN[sectorSelect], HIGH);
      break;
    case 3:
      digitalWrite(BLUE[sectorSelect], HIGH);
      digitalWrite(RED[sectorSelect], HIGH);
      break;
    case 4:
      digitalWrite(BLUE[sectorSelect], HIGH);
      digitalWrite(GREEN[sectorSelect], HIGH);
      break;
    case 5:
      digitalWrite(RED[sectorSelect], HIGH);
      digitalWrite(GREEN[sectorSelect], HIGH);
      break;
    case 6:
      digitalWrite(BLUE[sectorSelect], HIGH);
      digitalWrite(RED[sectorSelect], HIGH);
      digitalWrite(GREEN[sectorSelect], HIGH);
      break;
    default:
      digitalWrite(BLUE[sectorSelect], LOW);
      digitalWrite(BLUE[sectorSelect], LOW);
      digitalWrite(BLUE[sectorSelect], LOW);
      break;
  }
}

void gameStart(){
  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],HIGH);
    delay(40);
    digitalWrite(GREEN[i],HIGH);
    delay(40);
    digitalWrite(BLUE[i],HIGH);
    delay(40);
  }
  for(i = index; i >= 0; i--){
    digitalWrite(BLUE[i],LOW);
    delay(40);
    digitalWrite(GREEN[i],LOW);
    delay(40);
    digitalWrite(RED[i], LOW);
    
  }
}

void gameEnd(){  
 for(i = 0; i <= index; i++){
    digitalWrite(RED[i],HIGH); 
  }
  delay(300);

  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],LOW); 
  }
  delay(300);

  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],HIGH); 
  }
  delay(300);

  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],LOW); 
  }
  delay(300);

  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],HIGH); 
  }
  delay(300);

  for(i = 0; i <= index; i++){
    digitalWrite(RED[i],LOW); 
  }
  gameStart();
}

