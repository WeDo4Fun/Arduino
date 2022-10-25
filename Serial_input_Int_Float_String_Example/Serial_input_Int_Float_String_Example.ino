String myName;    // we declare a stiring variable to hold name
int age;          // decalre an integer vaurable of age which is usually given in round numbers (integer)
float height;     // decalre float variable to hold height

void setup() {
  Serial.begin(9600);   // Turning on serial port (9600 speed)
  

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Please enter your name :");    // Prompt the user for his name
  while(Serial.available() ==0) {                // Waitign for user input 
  }
  myName = Serial.readString();                  // Read the string 

  Serial.println("How old are you? ");           // Prompt the user for his age
  while(Serial.available() ==0) {                // Waitign for user input 
  }
  age = Serial.parseInt();                    // Read the Int

  Serial.println("How tall are you? ");          // Prompt the user for his height
  while(Serial.available() ==0) {                // Waitign for user input 
  }
  height = Serial.parseFloat();                  // Read the string 
  Serial.println("");                            // Add empty line
  Serial.print("Hello ");                        // using print instead of println keeps next print in same line
  Serial.print(myName);                          // print the name input
  Serial.print(", you are ");
  Serial.print(age);                            
  Serial.println(" years old.");                  // printLN marks end of line. next line will start below!
  Serial.print("and you are ");
  Serial.print(height); 
  Serial.println(" feet tall");                   // finish the line with LN - next line goes below
  Serial.print("");                               // added a fresh line
}
