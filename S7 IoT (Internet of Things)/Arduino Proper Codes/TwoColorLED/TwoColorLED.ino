int redpin = 11; 
int greenpin = 10; 
int val;

void setup() {
	pinMode(redpin, OUTPUT);
	pinMode(greenpin, OUTPUT);
}

void loop() {
	for(val = 255; val > 0; val--) { 
		analogWrite(redpin, val); 
		analogWrite(greenpin, 255 - val); 
		delay(15);
	}
	for(val = 0; val < 255; val++) { 
		analogWrite(redpin, val); 
		analogWrite(greenpin, 255 - val);
		delay(15);
	}
}


KY-011	Breadboard	Arduino
G	330Ω resistor	Pin 10
R	330Ω resistor	Pin 11
Y		GND
