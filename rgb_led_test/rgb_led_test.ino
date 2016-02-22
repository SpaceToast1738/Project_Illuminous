
//Declare variables
int LED[12];
int pin = 23, i, val = 0;

//Assign button push to pin
int ptb = 38;

void setup() {
  //This runs once to initialise all the variables.
  Serial.begin(9600); //Initialise a serial port for debugging

  //loop to assign each LED a pin
  //this should loop once for every LED in the circuit [Currently: 12]
  for(i = 0; i < 12; i++){
    LED[i] = pin; //pin starts at pin 23 initialised at variable stage
    pin = pin + 2; //LEDs are currently positioned at every 2 pins so increment pins by 2
  };

  //Another loop to set all the LEDs to output devices
  //this should loop once for every LED in the circuit [Currently: 12]
  for(i = 0; i <= 12; i++){
    pinMode (LED[i], OUTPUT);
  };

  //set the ptb to an input
  pinMode (ptb, INPUT);
};

void loop() { 
  // put your main code here, to run repeatedly:
  
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
