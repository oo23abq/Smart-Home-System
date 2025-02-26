#define BLYNK_TEMPLATE_ID "TMPL55VO-PqRY"
#define BLYNK_TEMPLATE_NAME "Mohammeds LED"
#define BLYNK_AUTH_TOKEN "iuXJZhrjlhPP834UTmxIel4L_vf5pL6W"


#include <WiFi.h>         // WiFi library for ESP32
#include <WiFiClient.h>   // WiFi Client for network communication
#include <BlynkSimpleEsp32.h>  // Blynk library for ESP32


// Replace with your WiFi credentials
const char* ssid = "BT-P8C2NX";
const char* password = "fEL6LFMFarmRdg";

// Define the LED pin
#define LED_PIN 1  // Change to the GPIO pin connected to your LED

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    
    Serial.println("\nConnected to WiFi!");
    
    // Start Blynk
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

// Blynk function to handle button press on the app
BLYNK_WRITE(V0) {
    int buttonState = param.asInt();  // Read the button value (0 = OFF, 1 = ON)
    digitalWrite(LED_PIN, buttonState);  // Control the LED
}

void loop() {
    Blynk.run();  // Keep Blynk running
}
