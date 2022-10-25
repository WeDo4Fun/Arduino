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
int numRedBlinks=1;            //Number of times Red blink
int numBlueBlinks=3;           //Number of times Blue blink
int numYellowBlinks=5;         //Number of times Yellow blink

 // Notes:
 // if Serail.begin & Serial.print up and running, have to give sufficient time between redings (RX) in order to upload code!!

void setup() {
  // Once entry and universal set-up parameters:  
  Serial.begin(9600);         // to send data back to computer 9600 is the speed 
  pinMode(redLED, OUTPUT);    // Set Red Led Pin 
  pinMode(blueLED, OUTPUT);   // Set Blue Led Pin 
  pinMode(yellowLED, OUTPUT);  // Set Green Led Pin 
  String wm1="Welcome to ";
  String wm2="My Program";
  Serial.print(wm1);
  Serial.println(wm2);
  String wm3;                     // define 'empty' string, net line defines
  wm3 = wm1+wm2;                    // this is called Concatanating 
}

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

  //start of Yellow blink loop
for (l ; l<=numYellowBlinks; l=l+1)  {
  Serial.print(yellowlabel);
  Serial.println(l);
  digitalWrite(yellowLED, HIGH);
  delay(dit);
  digitalWrite(yellowLED, LOW);
  delay(dah);
}

Serial.println(" ");
Serial.println("***End of Loop***");
Serial.println(" ");

delay(longW);
}
