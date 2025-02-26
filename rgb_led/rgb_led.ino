#define BLYNK_TEMPLATE_ID "TMPL5TBIYhlyf"
#define BLYNK_TEMPLATE_NAME "RGB LED"
#define BLYNK_AUTH_TOKEN "bv4D2hhTKB0CskLl4BIXw6A8p26tpz2G"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


// Enter your Wi-Fi credentials
char ssid[] = "Omar's Galaxy S23 Ultra";      // Replace with your Wi-Fi SSID
char pass[] = "FreePalestine";  // Replace with your Wi-Fi password

// Define GPIO pins for RGB LED
const int redPin = 5;    // Connect the Red LED pin
const int greenPin = 6;  // Connect the Green LED pin
const int bluePin = 7;   // Connect the Blue LED pin

// Initialize Blynk Virtual Pins for RGB control
#define VPIN_RED   5
#define VPIN_GREEN 6
#define VPIN_BLUE  7

// Callback functions to set LED colors from Blynk app sliders
BLYNK_WRITE(VPIN_RED) {
  int redValue = param.asInt();  
  analogWrite(redPin, redValue);
}

BLYNK_WRITE(VPIN_GREEN) {
  int greenValue = param.asInt();  
  analogWrite(greenPin, greenValue);
}

BLYNK_WRITE(VPIN_BLUE) {
  int blueValue = param.asInt();  
  analogWrite(bluePin, blueValue);
}

void setup() {
  Serial.begin(115200);
  
  // Set RGB pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start Blynk connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();  // Keep the Blynk connection alive
}
