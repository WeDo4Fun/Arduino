int redLED=8;                  //Set Red Led Pin Number 
int blueLED=9;                 //Set Blue Led Pin Number 
int yellowLED=10;              //Set Yellow Led Pin Number 
float pi=3.14;                 //Example for Float Number 
int dit=50;                    //Delay time short
int dah=100;                   //Delay time long 
int longW=20000;               //Delay time LONG Break 
int j=1;                       //For loop counter 
String redlabel="Red   : ";    //Set RedLed serial print sring 
String bluelabel="Blue  : ";   //Set BlueLed serial print sring 
String yellowlabel="Yellow: "; //Set YellowLed serial print sring 
int numRedBlinks;              //Number of times Red blink, we deleted =# as will hv seperate input
int numBlueBlinks;             //Number of times Blue blink
int numYellowBlinks;       //Number of times Yellow blink

 // Notes:
 // if Serail.begin & Serial.print up and running, have to give sufficient time between redings (RX) in order to upload code!!

void setup() {
  // Once entry and universal set-up parameters:  
  Serial.begin(9600);         // to send data back to computer 9600 is the speed - turn on seriial port 
  pinMode(redLED, OUTPUT);    // Set Red Led Pin an output pin
  pinMode(blueLED, OUTPUT);   // Set Blue Led Pin an output pin
  pinMode(yellowLED, OUTPUT);  // Set Green Led Pin an output pin
  String wm1="Welcome to ";
  String wm2="My Program";
  Serial.print(wm1);
  Serial.println(wm2);
  Serial.println(" ");

  // input number of blinks command: 
  
  Serial.println("How many times do you want the Red LED to blink? "); // prompt user for input
  while (Serial.available()==0) {};                                    // wait for user input
  numRedBlinks = Serial.parseInt();                                    // read-write user input 

  Serial.println("How many times do you want the Blue LED to blink? ");
  while (Serial.available()==0) {};
  numBlueBlinks = Serial.parseInt();

  Serial.println("How many times do you want the Yellow LED to blink? ");  
  while (Serial.available()==0) {};
  numYellowBlinks = Serial.parseInt();

}

        // Red Blink Number input:
    

void loop() {
  // main code body, will run repeatedly in loop
  // introducing Serial.print() : prints only once & Serial.println() : continious print
  // in Seerial.print(x) x is only once varriable, for several, we hv to use several Serial.print..
  
  // we hv to reset the counter j, k, l to 1 in each loop!
int j=1;  
int k=1;
int l=1;

 
 

  //strt of Red blink loop
for (j; j<=numRedBlinks; j=j+1)  {  
  Serial.print(redlabel); 
  Serial.println(j);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
}

Serial.println(" ");

  //start of Blue blink loop
for (k ; k<=numBlueBlinks; k=k+1)  { 
  Serial.print(bluelabel);
  Serial.println(k);
  digitalWrite(blueLED, HIGH);
  delay(dah);
  digitalWrite(blueLED, LOW);
  delay(dah);
}

Serial.println(" ");

  //start of Yellow blink loop - with while loop instead of for:
  
while (l<= numYellowBlinks) {
  Serial.print(yellowlabel);
  Serial.println(l);
  digitalWrite(yellowLED, HIGH);
  delay(dit);
  digitalWrite(yellowLED, LOW);
  delay(dah);
  l=l+1;
}


Serial.println(" ");
Serial.println("***End of Loop***");
Serial.println(" ");

delay(longW);
}
