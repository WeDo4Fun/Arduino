// potentiometer read A0 => write to digitial pwm Pin9
// reads 0-1023 / wrties 0-255 slope is 255/1023
// write value = 255/1023xreadValue
 
int LEDPin = 9;        // declare Led is attached to pwm dig pin 9
int potPin = A0;       // decalre the potentiameter pin 'potPin' to A0
int readValue;         // declaring our readValue variable whih will later read
int writeValue;        // declaring varaible to write to LEDPin

void setup() {
  Serial.begin(9600);         // we actaully do not need but good to have it on - turn on start monitor 
  pinMode(potPin, INPUT);     // decalre potPen an INPUT
  pinMode(LEDPin, OUTPUT);    // decalre LEDPin to an OUTPUT
 
}

void loop() {
  readValue = analogRead(potPin);                  // read voltage fm potentiometer potPin and put value to 'readValue'
  writeValue = (255./1023.) * readValue;           // calc writeValue - make sure to put '.' for float value
  analogWrite(LEDPin, writeValue);                 // writign to digi pwn / analog value 
  Serial.print("You are writing the value of :");  // donr put 'ln' as we dont want it to jump to nextline
  Serial.println(writeValue);                      // print out the real voltage 
 
}
