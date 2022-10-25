int redLED=6;                  //Set Red Led Pin Number to 6 
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
int numRedBlinks = 5;          //Number of times Red blink, we deleted =# as will hv seperate input
int numBlueBlinks = 3;         //Number of times Blue blink
int numYellowBlinks = 3;       //Number of times Yellow blink
int voltvalueRed;
int voltvalueBlue;
int voltvalueYellow;

 // Notes:
 // if Serial.begin & Serial.print up and running, have to give sufficient time between redings (RX) in order to upload code!! add a long delay into loop
 // Only dig pin no's 3, 5, 6, 9, 10, 11 can be used as analgWite by way of PWM!!

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


  // input voltage analogue value 0-255 -- move the block into void loop if want to change brightenss in each loop 
  
  Serial.println("Input analog value for Red Led (0-255): ");          // prompt user for analog input number
  while (Serial.available()==0) {};                                    // wait for user input
  voltvalueRed = Serial.parseInt();                                    // read-write user input 

  Serial.println("Input analog value for Blue Led (0-255): ");
  while (Serial.available()==0) {};
  voltvalueBlue = Serial.parseInt();

  Serial.println("Input analog value for Yellow Led (0-255): ");  
  while (Serial.available()==0) {};
  voltvalueYellow = Serial.parseInt();

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

 
 

  //start of Red blink loop
for (j; j<=numRedBlinks; j=j+1)  {                                     // j:variable ; j upto waht no? ; what happens to j on each loop 
  Serial.print(redlabel); 
  Serial.println(j);
  analogWrite(redLED, voltvalueRed);    // apply analog voltage to pin
  delay(dit);
  analogWrite(redLED, 0);
  delay(dit);
}

Serial.println(" ");

  //start of Blue blink loop
for (k ; k<=numBlueBlinks; k=k+1)  { 
  Serial.print(bluelabel);
  Serial.println(k);
  analogWrite(blueLED, voltvalueBlue);
  delay(dah);
  analogWrite(blueLED, 0);
  delay(dah);
}

Serial.println(" ");

  //start of Yellow blink loop - with while loop instead of for:
  
while (l<= numYellowBlinks) {
  Serial.print(yellowlabel);
  Serial.println(l);
  analogWrite(yellowLED, voltvalueYellow);
  delay(dit);
  analogWrite(yellowLED, 0);
  delay(dah);
  l=l+1;
}


Serial.println(" ");
Serial.println("***End of Loop***");
Serial.println(" ");

delay(longW);
}
