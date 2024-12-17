int sensorPin = A0;   
int val;              

void setup() {
  pinMode(A0, INPUT);   
  Serial.begin(9600);   
}

void loop() {
  val = analogRead(sensorPin);  
  Serial.println(val);          

  delay(100);  
}

KY-035	Arduino
S	Pin A0
middle	5V
–	GND