// Constants
const int tempPin = A0;  // Pin where the TMP is connected
const float voltageReference = 5.0;  // Reference voltage (5V for most Arduino boards)

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the value from the TMP sensor (range: 0 to 1023)
  int sensorValue = analogRead(tempPin);

  // Convert the analog reading to voltage
  float voltage = sensorValue * (voltageReference / 1023.0);

  // Print the voltage value to the Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100.0;  // TMP36's scale is 10mV per degree Celsius, offset by 500mV at 0°C

  // Print the temperature value to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Wait for a short period
  delay(1000);  // Delay to give time between readings
}
