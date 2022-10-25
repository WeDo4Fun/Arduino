// Establishing the variables we will use
// Make sure to use digital pins with PWM capability marked with "~" sign! We used No 6, 10, 11 and GND

int redLED=11;     // Set Red Led pin to 11
int greenLED=10;   // Set Green Led pin to 10
int blueLED=6;     // Set Blue Led pin to 6
int brightnessR;   // register RED brightness virabale (0-255)
int brightnessG;   // register GREEN brightness virabale (0-255)
int brightnessB;   // register BLUE brightness virabale (0-255)

void setup() {

  Serial.begin(9600);        // Turn Serial Monitor ON
  pinMode(redLED, OUTPUT);   // Set redLED to pin OUTPUT mode
  pinMode(greenLED, OUTPUT); // Set greenLED to pin OUTPUT mode
  pinMode(blueLED, OUTPUT);  // Set blueLED to pin OUTPUT mode 
}

void loop() {

  Serial.println(" ");                               // Empty line for begining of loop
 
  Serial.print("Please enter R value (0-255): ");    // Prompt the user for RED brightness value
  while(Serial.available()==0) {                     // Wait for user input
  }
  brightnessR = Serial.parseInt();                   // Register the input for RED brightness
  Serial.println(brightnessR);                       // Print the input number 

  Serial.print("Please enter G value (0-255): ");    // Prompt the user for GREEN brightness value
  while(Serial.available()==0); {                    // Wait for user input
  }
  brightnessG = Serial.parseInt();                   // Regsiter the input for GREEN brightness 
  Serial.println(brightnessG);                       // Print the input number

  Serial.print("Please enter B value (0-255): ");    // Prompt the user for BLUE brightness value
  while(Serial.available()==0) {                     // Wait for user input    
  }
  brightnessB = Serial.parseInt();                   // Regsiter the input for BLUE brigtness
  Serial.println(brightnessB);                       // Print the input number

  Serial.println(" ");                               // Leave one blank line 
  Serial.print("(R/G/B) : (");                       // Print values in proper format (R/G/B) : (_/_/_)
  Serial.print(brightnessR);
  Serial.print("/");
  Serial.print(brightnessG);
  Serial.print("/");
  Serial.print(brightnessB);
  Serial.println(")");
  Serial.println(" ");                               // Leave one blank line
  Serial.println("++++++++++++++++");                // Print a seperator line in Serial Monitor 
  
  analogWrite(redLED, brightnessR);                  // Set RED color brightness to brightnessR input value
  analogWrite(greenLED, brightnessG);                // Set GREEN color brightness to brightnessG input value
  analogWrite(blueLED, brightnessB);                 // Set BLUE color brightness brightnessB input value

}
