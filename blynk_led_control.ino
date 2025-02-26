#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h> // ESP32Servo library

const char* ssid = "UHWifi"; // WiFi Credentials
const char* pass = ""; // Update if a password is needed
Servo myServo; // Servo Configuration
#define SERVO_PIN D4 // Change according to your wiring
void setup() {
Serial.begin(115200);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);// Connect to WiFi and Blynk
myServo.attach(SERVO_PIN);// Attach servo to the specified pin
myServo.write(90); // Neutral position at startup
Serial.println("Setup Complete. Connected to Blynk.");
}
BLYNK_WRITE(V1) { // Blynk Virtual Button SWITCH_V1 (V1) - ONE OF THE SERVOMOTOR
int buttonState = param.asInt();
if (buttonState) {
myServo.write(180); // Move to 180° (RIGHT/ON)
Serial.println("Turning Right...");
} else {
myServo.write(0); // Move to 0° (LEFT/OFF)
Serial.println("OFF...");
}
}
void loop() {
Blynk.run(); // Keep Blynk connected
//if(V0==1 && V1==1){Serial.print("Two switches are ON\n");}
}