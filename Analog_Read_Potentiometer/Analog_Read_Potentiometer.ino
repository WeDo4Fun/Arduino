// potentiometer read

int potPen = A0;      // assigning 'potPen' to A0
int readValue;        // declaring our readValue variable
float Voltage;        // decalring our Voltage vairable calc fm readValue


void setup() {
  pinMode(potPen, INPUT);     // decalre potPen an input
  Serial.begin(9600);         // start monitor - serial
 
}

void loop() {
  readValue = analogRead(potPen);        // read potPen and put value to 'readValue'
  Voltage = (5./1023.)*readValue;        // 5v to 1023 digits here we have to put '.' o/wise will convert to integer. We want flaot!!!
  Serial.println(Voltage);               // print out the real voltage 
  delay(2000);                           // in order to slowdown add delay
 
}
