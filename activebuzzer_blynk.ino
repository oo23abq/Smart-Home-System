#define BLYNK_TEMPLATE_ID "TMPL5M9bNtwAa"
#define BLYNK_TEMPLATE_NAME "Active Buzzer Control"
#define BLYNK_PRINT Serial

#include <WiFi.h>  // WIFI library for ESP32 boards
#include <BlynkSimpleEsp32.h>


char ssid[] = "BT-P8C2NX";       // Replace with your WiFi SSID
char pass[] = "fEL6LFMFarmRdg";   // Replace with your WiFi password
char auth[] = "3DvTwqqzIAwBBkOv0cowtgvFM863-hPh";       // Replace with your authentication token

const int buzzerPin = 13;  // Buzzer connected to D8

BLYNK_WRITE(V1) {
  int buzzerState = param.asInt();  // Read button state from Blynk
  digitalWrite(buzzerPin, buzzerState);
}

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);  // Ensure buzzer is OFF initially

  Blynk.begin(auth, ssid, pass);  // Connect to WiFi and Blynk
}

void loop() {
  Blynk.run();  // Keep connection alive
}
