#include <Servo.h>    // Load the Servo Lib

// Analog pin for values 0-255 needs a pin with '~'
// Pins with NO '~' write only HIGH or LOW (5V - 0V)

int trigPin=13;         // Ultrasonic trig pin is connected to Arduino pin 13
int echoPin=11;         // Ultrasonic echo pin is connected to Arduino pin 11

int servoControlPin=6;  // Servo control pin connected to Arduino pin 6

float pingTime;         // Time for ping to travel to target and return. We use 'float' as we 
                        // want to have real and accurate numbers (numbers with deciamls).   
float targetDistance;   // Distance from target to distance
float speedOfSound=347; // Speed of sound in m/s in air at 21 degrees celcius
float servoAngle;       // Variable for the angle of the servo

Servo myPointer;        // We need to create a servo object. An object to interact with

void setup() {
  Serial.begin(9600);   // Turn on Serial Port
  pinMode(servoControlPin, OUTPUT); // Servo Control Pin is an output 
  pinMode(trigPin, OUTPUT);         // Ultrasonic sensor trigger pin, out from Arduino to send a ping
  pinMode(echoPin, INPUT);          // Ultrasonic sensor send reading back to Arduino

  myPointer.attach(servoControlPin); // Tell Arduino which pin the servo object is attached to

}

void loop() {
  // We have to make a measurement of ping time. We have to create a pulse, whcih creates a trigger tellign the ultrasonic
  // sensor to send a ping, by: LOW/HIGH/LOW with a pause to give a moment signal to settle

   digitalWrite(trigPin, LOW);  // No.1 set the trigger pin LOW 
   delayMicroseconds(2000);     // Pause to let signal to settle
   digitalWrite(trigPin, HIGH); // No.2 set the trigger pin HIGH
   delayMicroseconds(15);       // Pause very short time in HIGH state so tt sensor can see tt we sent a HIGH signal
   digitalWrite(trigPin, LOW);  // No.3 bring the trig pin back to low

   // The above sends a LOW/HIGH/LOW signal to the HC_SR04 Ultrasonic Sensor telling it to send a PING

   pingTime = pulseIn(echoPin, HIGH); // this is telling Arduino that the HC_SR04 will be sending a HIGH pulse (LOW/'HIGH'/LOW)
                                      // measure the ping time in 'microseconds': we have to convert to seconds
                                      // 1sec = 1,000,000 microseconds
   pingTime = pingTime/1000000.;      // Converting pingTime to seconds. We put '.' to make sure number stays as float!

   targetDistance = speedOfSound * pingTime;  // Calculates ping time distance. From sensor to target and back
   targetDistance = targetDistance/2;         // Calculates and gives distance in metters
   targetDistance = targetDistance*100;       // Calcualtes and gives distance in centimeters

  Serial.print("The target to distance to is: ");
  Serial.print(targetDistance);
  Serial.println(" cm");

// Calculationg slope and angle:
//  Slope(m) = (y2-y1)/(x2-x1)
//  We use servo angles from 15 degrees to 165 degrees (instead of 0-180: not to burn servo)
//  y1 = 15   y2 = 165 degrees
//  We did measure scale 0cm to 100cm
//  x1 = 0cm  x2 = 100cm
//  m=(165-15)/(100-0) => m=15/10
//  if we want to find a servo angle for any given distance: 
//  y-y1 = m(x-x1) igf we put the y1 and x1 values:
//  y-15 = (15./10.)x       [we put '.' to keep number as float]
//  => y = (15./10.) x
 
  servoAngle = 180 - ((15./10.) * targetDistance + 15);   // calculate servoAngel based on target distance)

//  Serial.print("Angle : ");
//  Serial.println(servoAngle);
 
  if (servoAngle >= 165)  servoAngle = 165;
  if (servoAngle <= 15) servoAngle = 15;
  
  myPointer.write(servoAngle);          // wrtie servoAngle to myPointer

  delay(500);                           // delay to slow things down a tad
}
