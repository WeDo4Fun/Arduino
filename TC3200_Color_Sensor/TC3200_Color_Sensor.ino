
//    *** IMPORTANT ***
//    Before running below code, the TCS3200's sensitivity (MIN and MAX values) has to be obtained 
//    using code called "TC3200_Color_Sensor_Sensitivity_Test". 
//
//    Every inidivdual TCS3200 has a slightly different sensitivity and this process has to be 
//    done for each different sensor. Dont need to run the test again when the figures are 
//    acquired for a specific sensor ONCE. The MIN/MAX figures obtoned from the test code will be  
//    inserted in below CODE to the MAP function. 
//    Please note as the sensor outputs LOW (reversed reading) in mapping the MAX figure has to be 
//    mapped to "0" and MIN figure mapped to "255" in the XXXColor = map (xFreq, XY1, XY2, 255, 0) 
//    function below.
//    
//    Connection Chart:
// Color Sensor Pin   Arduino Pin
//      S0                pin4 (output freq scaling selection input 100% / 20% / 2%)
//      S1                pin5 (output freq scaling selection input 100% / 20% / 2%)
//      S2                pin6 (photodiode type selection input)
//      S3                pin7 (photodiode type selection input)
//      OUT               pin8 (output frequency)
//      VCC               5V
//      GND               GND
//  
//    TCS3200 Sensor adjustment matrix:
//
//    SO    S1    Scale 
//    LOW   LOW   Power Down
//    LOW   HIGH  2%
//    HIGH  LOW   20%
//    HIGH  HIGH  100%
//    (For Arduino usually used 20%!! -> Wrtie to sensor S0 : HIGH / S1 : LOW)
//
//    S2    S3    Color Read:
//    LOW   LOW   Red
//    HIGH  HIGH  Green
//    LOW   HIGH  Blue
//    HIGH  LOW   No filter (Luminosity)

//    TCS3200 - Arduino Connection: 

int S0=4;           // asign Color Sensor SCALE pin S0 to Arduino pin 4
int S1=5;           // asign Color Sensor SCALE pin S1 to Arduino pin 4
int S2=6;           // asign Color Sensor Photodiode COLOR Choice pin S2 to Arduino pin 6
int S3=7;           // asign Color Sensor Photodiode COLOR Choice pin S3 to Arduino pin 6
unsigned int SensorOut=8;    // asign Color Sensor OUT pin to Arduino pin 8.  
                    //  'int' assigns 0-255. For bigger no's we use 'UNSIGNED INT' up to 102,400!
                    //  as the clor sensor sends valuesup to 102,400! (for pitch black)

//    RGB Led Light - Arduinio Connection: 

int redPin=9;       // asign RED pin from LED to pin 9
int greenPin=10;    // asign GREEN pin from LED to pin 10
int bluePin=11;     // asign BLUE pin from LED to pin 11 

//    Others:

int rFreq;          // asign an integer for RED photodiode frequncy reading 
int gFreq;          // asign an integer for GREEN photodiode frequncy reading 
int bFreq;          // asign an integer for BLUE photodiode frequncy reading 
int LumFreq;        // asign an integer for LUMINOSITY photodiode frequncy reading

int redColor;       // asign an integer for remapped RED color
int greenColor;     // asign an integer for remapped GREEN color
int blueColor;      // asing an integer for remapped BLUE color 

void setup() {
  
// Setting RGB LED pin modes:

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

// Settign COLOR SENSOR pin modes:

  pinMode(S0, OUTPUT);    // S0 sends LOW/HIGH to the sensor to set SCALE
  pinMode(S1, OUTPUT);    // S1 sends LOW/HIGH to the sensor to set SCALE
  pinMode(S2, OUTPUT);    // S2 sends LOW/HIGH to the sensor to set which color to read
  pinMode(S3, OUTPUT);    // S3 sends LOW/HIGH to the sensor to set which color to read
  pinMode(SensorOut, INPUT); // output pin from sensor to arduino sending frequency

  digitalWrite(S0, HIGH); // Setting Frequency scalling to 20% for Arduino
  digitalWrite(S1, LOW); 

  Serial.begin(9600);     //  Begin serail monitor at speed of 9600
}

void loop() {

// Read the RED output frequency

  digitalWrite(S2, LOW);          // Set photodiodes for RED reading 
  digitalWrite(S3, LOW);          

  rFreq=pulseIn(SensorOut, LOW);  // asign the frequency read to the rFreq variable

//  below is the remaping the RED frequency values from the MIN/MAX  values recevied 
//  from the "TC3200_Color_Sensor_Sensitivity_Test" code. My MIN/MAX readings were
//  80 and 310. Please use your own figures after you run your own test.
//  Also please note, the lower number gets asigned to 255 and higher number to 0 as 
//  it the sensor sends value/intensity in reverse order:
 
  redColor=map(rFreq, 80, 310, 255, 0); // Put in here slightly lower/high MIN/MAX than readings

  Serial.print("R= ");            // print the RED value
  Serial.print(redColor);
  delay(100);

// Read the GREEN output frequency

  digitalWrite(S2, HIGH);         // Set photodiodes for GREEN reading
  digitalWrite(S3, HIGH); 

  gFreq=pulseIn(SensorOut, LOW);  // asign the frequency read to the gFreq variable

//  My MIN/MAX figures from the TEST for GREEN were 160 and 270. For Mapping Green:

  greenColor=map(gFreq, 160, 270, 255, 0);
  
  Serial.print(" / G= ");            // print the GREEN value
  Serial.print(greenColor);
  delay(100);

 
// Read the BLUE output frequency

  digitalWrite(S2, LOW);          // Set photodiodes for GREEN reading
  digitalWrite(S3, HIGH);

  bFreq=pulseIn(SensorOut, LOW);  // asign the frequncy read to the bFreq variable

//  My MIN/MAX figures from the TEST for BLUE were 80 and 100:

  blueColor=map(bFreq, 80, 110, 255, 0);
  
  Serial.print(" / B= ");            // print the BLUE value
  Serial.print(blueColor);
  delay(100);

// Read the LUMINOSITY output frequency

  digitalWrite(S2, HIGH);         // Set photodiodes for LUMINOSITY reading
  digitalWrite(S3, LOW);

  LumFreq=pulseIn(SensorOut, LOW);  //asign the frequncy read to the LumFreq variable

  Serial.print(" / Lum= ");          // print the LUMINOSTY value
  Serial.println(LumFreq);        // print with LN as we want next fresh one start with a new line!
  delay(100);

  if (redColor > 255) redColor=255;
  if (redColor < 0) redColor =0;
  if (greenColor > 255) greenColor=255;
  if (greenColor < 0) greenColor=0;
  if (blueColor > 255) blueColor=255;
  if (blueColor < 0) blueColor=0;
  
  analogWrite(redPin, redColor);                  // Set RED color brightness to brightnessR input value
  analogWrite(greenPin, greenColor);                // Set GREEN color brightness to brightnessG input value
  analogWrite(bluePin, blueColor);                 // Set BLUE color brightness brightnessB input value

  delay(1500);

}
