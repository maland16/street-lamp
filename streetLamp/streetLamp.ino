int walkPin = 3;
int handPin = 4;
int buttonPin = 2;
int mode = 0;
int selection = 0;
int critical = 0;

void setup() {
  // Set up Pins/Interrupt
  pinMode(walkPin, OUTPUT);
  pinMode(handPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);        // initialize serial communication

  delay(1000);
  digitalWrite(handPin, LOW);
  digitalWrite(walkPin, LOW);
  delay(1000);
  digitalWrite(handPin, HIGH);
  digitalWrite(walkPin, HIGH);
  delay(1000);
  digitalWrite(handPin, LOW);
  digitalWrite(walkPin, LOW);
  delay(1000);
  digitalWrite(handPin, HIGH);
  digitalWrite(walkPin, HIGH);
  delay(1000);
  digitalWrite(handPin, LOW);
  digitalWrite(walkPin, LOW);
  delay(1000);

  if(digitalRead(buttonPin) == LOW){
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, FALLING);

    mode = 0;
  }else{
    mode = 1;
  }
  delay(500);
}

void loop(){
  if(mode == 0){ // Mode to allow user to manually change light setting via ISR
    if(selection == 0){
      digitalWrite(handPin, LOW);
      digitalWrite(walkPin, LOW);
    }else if(selection == 1){
      digitalWrite(handPin, HIGH);
      digitalWrite(walkPin, LOW);
    }else if(selection == 2){
      digitalWrite(handPin, LOW);
      digitalWrite(walkPin, HIGH);
    }else{
      digitalWrite(walkPin, HIGH);
      digitalWrite(walkPin, HIGH);
    }
    delay(100);
  }else{ // Street lamp mode

    // Walk
    digitalWrite(handPin, HIGH);
    digitalWrite(walkPin, LOW);
    delay(30000);

    // Flash hand
    digitalWrite(walkPin, HIGH);
    
    digitalWrite(handPin, LOW);
    delay(1000);
    digitalWrite(handPin, HIGH);
    delay(1000);
    digitalWrite(handPin, LOW);
    delay(1000);
    digitalWrite(handPin, HIGH);
    delay(1000);
    digitalWrite(handPin, LOW);
    delay(1000);
    digitalWrite(handPin, HIGH);
    delay(1000);
    digitalWrite(handPin, LOW);
    delay(1000);
    digitalWrite(handPin, HIGH);
    delay(1000);

    // Solid hand
    digitalWrite(handPin, LOW);
    delay(30000);
  }
}

void buttonPressed(){
  if(critical == 0){
    critical = 1;
    Serial.println("Button pressed");
    if(selection <4){
      selection++;
    }else{
      selection = 0;
    }
    delay(500);
    critical = 0;
  }
}
  
