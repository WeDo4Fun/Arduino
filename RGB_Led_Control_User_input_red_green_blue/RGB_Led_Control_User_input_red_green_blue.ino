int redPin=11;                // Set red LED pin to 11
int greenPin=10;              // Set green LED pin to 10
int bluePin=6;                // Set blue LED pin to 6
int brightness=255;            // Establish INT variable for brightness
String colorChoice;            // Set up variable to hold user color choice input  


void setup() {

  Serial.begin(9600);         // Turn on Serial port with speed of 9600
  pinMode(redPin, OUTPUT);    // Set up pinmodes to output
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

}

void loop() {

  Serial.println("Please input your color choice (red/green/blue): ");   // Prompt user for color choice input
  while(Serial.available()==0) {                                // Wait for user input 
  }
  colorChoice = Serial.readString();                            // Read/register user input string

  if (colorChoice=="red") {
    analogWrite(redPin, brightness);      // turn RED on to given brightness 
    analogWrite(greenPin, 0);             // turn GREEN off
    analogWrite(bluePin, 0);               // turn BLUE off
  }

    if (colorChoice=="green") {
    analogWrite(redPin, 0);               // turn RED off
    analogWrite(greenPin, brightness);    // turn GREEN on to given brightness 
    analogWrite(bluePin, 0);               // turn BLUE off
  }

    if (colorChoice=="blue") {
    analogWrite(redPin, 0);               // turn RED off
    analogWrite(greenPin, 0);             // turn GREEN off
    analogWrite(bluePin, brightness);      // turn BLUE  on to given brightness 
  }

    if ( colorChoice != "red" && colorChoice != "green" && colorChoice != "blue") {
    Serial.println(" "); 
    Serial.println("Input is not a valid color. Please input red or green or blue");  
    Serial.println(" "); 
    }

}
