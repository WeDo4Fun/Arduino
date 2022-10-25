#include <Servo.h>    // Load servo library

/* Servos raraly rotate 180 degrees. We have to test each servo at teh begining betwen 0 - 180 degress to 
 *  test the limits so tt we dont want to burn it. 
 */
 
int pos=0;          // Declare and initialise the position variable
int servoPin=9;     // Tell Arduino tt server is attached to Pin 9
int servoDelay=25;  // Delay in response by servo to commands

Servo myServo;      // Creating an object and telling Arduino tt it is a Servo, called myServo


void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin); // we are telling Arduino that, an object called myServo, 
                            // whcih is a servo object, is attached to Pin9

}

void loop() {
  // We will ask for input / wait / read in order to test the esrvo limits

  Serial.println("Please input Servo Position Angle : "); // prompt for input
  while (Serial.available()==0) {                         // wait for input
      }
  pos = Serial.parseInt();                                // read user input - write it to 'pos'
  myServo.write(pos);                                     // turn the Servo to user input 'pos' angle

}
