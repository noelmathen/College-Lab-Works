int digitalPin = 7;   
int analogPin = A0;   
int ledPin = 13;      
int digitalVal;       
int analogVal;        

void setup()
{
  pinMode(digitalPin,INPUT); 
  pinMode(analogPin, INPUT);
  pinMode(ledPin,OUTPUT);      
  Serial.begin(9600);
}

void loop()
{
  digitalVal = digitalRead(digitalPin); 
  
  if(digitalVal == HIGH) 
  {
    digitalWrite(ledPin, HIGH); 
  }
  else
  {
    digitalWrite(ledPin, LOW);  
  }

  analogVal = analogRead(analogPin);
  Serial.println(analogVal);  

  delay(100);
}

KY-036	Arduino
A0	Pin A0
G	GND
+	5V
D0	Pin 7
