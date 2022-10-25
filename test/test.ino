void setup() {
 Serial.begin(9600);
 
}

void loop() {

 int j=1;       // decalre j is an integer and set it equal to 1

 while (j<=10) {
 Serial.println(j);
 j=j+1;   
 delay(50); 
 }

 Serial.println(" ");
 
}
