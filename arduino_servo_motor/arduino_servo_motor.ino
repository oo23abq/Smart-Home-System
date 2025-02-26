#define BLYNK_TEMPLATE_ID "TMPL5Q70wfi4l"
#define BLYNK_TEMPLATE_NAME "Automated Servomotor Control"
#define BLYNK_AUTH_TOKEN "ufhvERokrWRLwpom3snL-1-gclnK9L5k"

#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// WiFi Credentials
char ssid[] = "BT-P8C2NX";
char pass[] = "fEL6LFMFarmRdg";

// Servo Setup
int servoPin = 2;
Servo myservo;
bool servoAttached = false; // Track attachment

// Blynk Virtual Pins
#define VPIN_SERVO V0
#define VPIN_FEEDBACK V1

// Function to move servo
BLYNK_WRITE(VPIN_SERVO) {
    int servo_angle = param.asInt();  
    Serial.printf("Received angle: %d\n", servo_angle);

    if (servo_angle < 0 || servo_angle > 180) {
        Serial.println("Invalid servo angle!");
        return;
    }

    if (!servoAttached) {
        myservo.attach(servoPin, 500, 2400);
        servoAttached = true;
    }
  
    myservo.write(servo_angle);
    delay(15);
    Blynk.virtualWrite(VPIN_FEEDBACK, servo_angle);
    Serial.printf("Servo moved to: %d°\n", servo_angle);
    
    delay(1000); // Wait a bit
    myservo.detach(); // Detach to prevent jitter
    servoAttached = false;
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting...");

    // Initialize Servo
    myservo.setPeriodHertz(50);

    // Connect to WiFi
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi...");
  
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi!");

    // Start Blynk (non-blocking)
    Blynk.config(BLYNK_AUTH_TOKEN);
    Blynk.connect();

    Serial.println("Connected to Blynk!");
    Blynk.syncVirtual(VPIN_SERVO);
}

void loop() {
    Blynk.run();
}
