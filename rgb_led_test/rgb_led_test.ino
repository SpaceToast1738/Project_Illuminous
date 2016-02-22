
//Declare ledName variables (startPin = 23 [+2] | Max = 45)
int LED[12];
int pin;
int i;

//Assign buttonName to pin
int ptb = 38;
int val = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pin = 23;
  for(i = 0; i < 12; i++){
    LED[i] = pin;
    pin = pin + 2;
  };

  for(i = 0; i <= 12; i++){
    pinMode (LED[i], OUTPUT);
  };
  pinMode (ptb, INPUT);
};

void loop() { 
  // put your main code here, to run repeatedly:
  Serial.print(val);
  Serial.print(" ");  

  for(i = 0; i <= 12; i++){     
    digitalWrite(LED[i], HIGH);
    delay(100);
  };
  for(i = 0; i <= 12; i++){
    digitalWrite(LED[i], LOW);
  };  
  for(i = 0; i <= 12; i++){
    digitalWrite(LED[i], HIGH);
  }; 
};
