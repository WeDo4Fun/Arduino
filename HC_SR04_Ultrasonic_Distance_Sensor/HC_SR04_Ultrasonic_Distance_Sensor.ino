// Pin Setup:

int trigPin=13;     // Sensor Trigger Pin connected to Arduino 13
int echoPin=11;     // Sensor cho pin connected to Arduino 13
float pingTime;     // Time for png to hit target and return. We want 
float speedOfSound; // Speed of sOund - we will measure 
float targetDistance=30;  //

void setup() {
  Serial.begin(9600) ;      // Turn on serial port
  pinMode(trigPin, OUTPUT); // Set Trigger pin output to send to sensor
  pinMode(echoPin, INPUT);  // Set Echo pin INPUT, receiving signal back from sensor
}

void loop() {
  // we will send a LOW/HIGH/LOW signal:
  digitalWrite(trigPin, LOW);   // Set Trigger Pin Low
  delayMicroseconds(2000);      // Pause to let signal to settle
  digitalWrite(trigPin, HIGH);  // Send HIGH Trigger Signal
  delayMicroseconds(10);        // Pause with Trigger pin at HIGH mode
  digitalWrite(trigPin, LOW);   // 

  pingTime = pulseIn(echoPin, HIGH);  // we are listenign to the HIGH signal - pingTime in microseconds

  speedOfSound = 2*targetDistance/pingTime;    // Gives us speed in cm per microseconds
                                              // 1s = 1,000,000 microseconds
                                              // 1meter = 100 cm 
  speedOfSound = speedOfSound/100*1000000; // Gives Speed of Sound in m/s

  Serial.print("Speed of sound is : ");
  Serial.print(speedOfSound); 
  Serial.println(" meters per second.");
  delay(1500);
  }
