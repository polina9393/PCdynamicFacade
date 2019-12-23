// https://learn.adafruit.com/photocells/arduino-code used code example in some places 

#include <Servo.h>
int pos = 0;    // variable to store the servo position
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        

Servo myservo;  // create servo object to control a servo
Servo myservoSecond;  // create second servo object to control a servo


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoSecond.attach(8);
  Serial.begin(9600);
}

void loop() {
  photocellReading = analogRead(photocellPin);  
 

  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;

  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);

  // rotates both servoes when brightness over 70
  if(photocellReading>70){
   myservo.write(100);
   myservoSecond.write(100);
   }else{
    myservo.write(0);
    myservoSecond.write(0);
    };
  
}
