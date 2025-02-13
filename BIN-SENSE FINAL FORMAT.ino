#include <Stepper.h>
#include <Servo.h>
Servo servo1;
#define ir 5
#define proxi 6
#define buzzer 12
int potPin = A0; //input pin
int soil=0;
int fsoil;

Stepper Stepper (SREG_S, 8, 9, 10, 11);

int stepCount = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(proxi, INPUT_PULLUP);
  pinMode(ir, INPUT);
  pinMode(buzzer, OUTPUT);
  servo1.attach(7);
  servo1.write(180);
delay(1000);
servo1.write(70);
delay(1000);
  
}

void loop() 
{
  fsoil=0;
  int L =digitalRead(proxi);
Serial.print(L);
if(L==0)

{
  tone(buzzer, 1000, 1000);
 // step one step STEPPER MOTOR:
  Stepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
servo1.write(180);
delay(1000);
servo1.write(70);
delay(1000);
delay(1000); 
} 

if(digitalRead(ir)==0)
{
   tone(buzzer, 1000, 500);
   delay(1000);
  int soil=0;
  for(int i=0;i<3;i++)
    {
    soil = analogRead(potPin) ;
      soil = constrain(soil, 485, 1023);
        fsoil = (map(soil, 485, 1023, 100, 0))+fsoil;
          delay(75);
      }
    fsoil=fsoil/3;
    Serial.print(fsoil);
    Serial.print("%");Serial.print("\n");

    if(fsoil>20)
           {            
              servo1.write(180);
              delay(1000);
              servo1.write(70);
                delay(1000);
              } 

      else {
         tone(buzzer, 1000, 500);
           delay(1000);
            servo1.write(180);
              delay(1000);
              servo1.write(70);
                delay(1000);}
}

}
