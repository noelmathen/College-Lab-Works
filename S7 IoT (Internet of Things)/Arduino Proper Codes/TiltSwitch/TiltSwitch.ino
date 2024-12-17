int tiltPin = 2;   
int ledPin =  13;     
int tiltState = 0;   

void setup() {  
  pinMode(ledPin, OUTPUT);     
  pinMode(tiltPin, INPUT);  
}

void loop(){
  tiltState = digitalRead(tiltPin);

  if (tiltState == HIGH) {     
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}


KY-020	Arduino
S	2
middle	+5V
–	GND