int sensorPin = 7;  
int val;            

void setup() {
  pinMode(sensorPin,INPUT);   
  Serial.begin(9600);     
}

void loop() {
  val = digitalRead(sensorPin); 
  
  if (val == HIGH) { 
    Serial.println("Line detected"); 
  } else { 
    Serial.println("Line NOT detected"); 
  }

  delay(500);
}

KY-033	Arduino
GND	GND
OUT	Pin 7
VCC	5V