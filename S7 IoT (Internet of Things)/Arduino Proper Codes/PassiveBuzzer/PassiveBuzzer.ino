int buzzer = 8; 

void setup() {
	pinMode(buzzer, OUTPUT); 
}

void loop() {
	for (int i = 0; i < 100; i++) {  
		digitalWrite(buzzer, HIGH); 
		delay(1); 
		digitalWrite(buzzer, LOW); 
		delay(1);
	}
	delay(50);
	for (int j = 0; j < 100; j++) { 
		digitalWrite(buzzer, HIGH);
		delay(2); 
		digitalWrite(buzzer, LOW);
		delay(2);
	}
	delay(500);
}
