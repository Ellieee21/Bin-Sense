#include <Servo.h>
#include <Stepper.h>

// Stepper motor setup
const int stepsPerRevolution = 2048;
const int stepperSteps90 = stepsPerRevolution / 4;
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

// Servo
Servo myServo;
const int servoPin = 6;

// Sensors
const int raindropSensorPin = A0;
const int proximitySensorPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(proximitySensorPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // Initial servo position
  stepper.setSpeed(10);
}

void loop() {
  int proximityState = digitalRead(proximitySensorPin);
  int raindropValue = analogRead(raindropSensorPin);

  Serial.print("Proximity: "); Serial.print(proximityState);
  Serial.print(" | Rain Sensor Value: "); Serial.println(raindropValue);

  // Proximity sensor is LOW when object is detected (NPN type)
  if (proximityState == LOW) {
    if (raindropValue >= 1000) {
      Serial.println("Dry object detected.");
      activateMechanism();
    } 
    else if (raindropValue <= 400) {
      Serial.println("Wet object detected.");
      activateMechanism();
    } 
    else {
      Serial.println("Object detected, but moisture is unclear. Ignoring.");
    }

    delay(2000); // Prevent rapid re-triggering
  }

  delay(100);
}

void activateMechanism() {
  // Rotate stepper motor 90°
  stepper.step(stepperSteps90);

  // Move servo like a door
  myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);

  // Return stepper to original position
  stepper.step(-stepperSteps90);
}
