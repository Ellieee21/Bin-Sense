#include <Adafruit_VCNL4010.h>
#include <IRSensor>
#define sensor_DO A0
#include <Servo.h>
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200

int IRSensor = 9; // connect IR sensor module to Arduino pin D9
int LED = 13; // connect LED to Arduino pin 13
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
Serial.begin(115200); // Init Serial at 115200 Baud Rate.
Serial.println("Serial Working"); // Test to check if serial is working or not
pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
pinMode(LED, OUTPUT); // LED Pin Output
Serial.begin(9600); // for rain drop
myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 // Declare pins as output for motor and driver:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{
  int val = digitalRead(sensor_DO); // for raindrop until (val)
  Serial.print("Digital Output: ");
  Serial.print(val);
    if (val == 1) {
    Serial.println("   Status: Dry");
  } else {
    Serial.println("   Status: Wet");
  }
  delay(1000);
}
if (digitalRead = " Status: Dry" )// for if else sa servo motor for dry
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input [this is for IR]
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led [this is for IR]
    digitalWrite(LED, LOW); // LED LOW
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
    // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(LED, HIGH); // LED High
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }

  if (digitalRead = " Status: Wet")// for if else sa wet {servo motor}
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input [this is for IR]
  if (sensorStatus == HIGH) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led [this is for IR]
    digitalWrite(LED, HIGH); // LED LOW
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  //Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(LED, HIGH); // LED High
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }
}