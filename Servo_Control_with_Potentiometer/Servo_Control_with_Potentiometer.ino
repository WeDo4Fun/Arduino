#include <Servo.h>    // Load servo library

/*  Servos raraly rotate 180 degrees. We have to test each servo at teh begining betwen 0 - 180 degress to 
 *  test the limits so tt we dont want to burn it. 
 *  The potentiometer reads 0v to 5v and gives readon 0 to 1023 to Arduino through the pin
 *  These figures will need to be put int to 'pos' from 10 to 170!
 *  We have to calc teh map function 
 *  y(15, 170):x(0, 1023)
 *  slope (m) = (y2-y1) / (x2-x1)
 *  m= (170-15) / (1023-0) = 155/1023
 *  => y-y1 = m((x-x1) => (y-15) = 155/1023 (x-0) => y= (155/1023)x + 15
 *  pos=(155/1023) 'pos reading' + 15
 */
 
int pos=0;           // Declare and initialise the position variable
int servoPin=9;      // Tell Arduino tt server is attached to Pin 9
int potPin=A0;       // Connect potentiometer to pin A0
int potReading;      // Establsih integer for Potentimeter reading
int servoDelay=1000; // Delay in response by servo to commands

Servo myServo;      // Creating an object and telling Arduino tt it is a Servo, called myServo


void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin); // we are telling Arduino that, an object called myServo, 
                            // whcih is a servo object, is attached to Pin9

}

void loop() {

potReading = analogRead(potPin);    // Read potentiometer

pos = (180./1023.)*potReading;   // We put'.' after numbers to make sure we dont goto floats
myServo.write(pos);                 // write pos to servo
  delay(servoDelay);
}
