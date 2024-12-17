int smallSoundPin = 3;
void setup() {
  pinMode(smallSoundPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(smallSoundPin) == HIGH) {
    Serial.println("Quiet Sound Detected");
  }
  delay(100);
}

    VCC: Connect to 5V on the Arduino.
    GND: Connect to GND on the Arduino.
    DO: Digital output, connect to a digital pin, e.g., D3.
    AO: Analog output, connect to an analog pin, e.g., A1.