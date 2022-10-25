13//  TC3200 Color Sensor Sensitivty Testing
//
//  Need to run this program once to print on Serial Monitor the MIN/MAX values of
//  the color sensor. These figures needs to obtained only ONE time, but for
//  each sensor unit as each one has slightly different sensitivity. 
//  After the MIN/MAX figures are obtained, we use them in next code called "TC3200_Color_Sensor"
//
//  Conenction Chart
//
// Color Sensor Pin   Arduino Pin
//      S0                pin4 (output freq scaling selection input 100% / 20% / 2%)
//      S1                pin5 (output freq scaling selection input 100% / 20% / 2%)
//      S2                pin6 (photodiode type selection input)
//      S3                pin7 (photodiode type selection input)
//      OUT               pin8 (output frequency)
//      VCC               5V
//      GND               GND
//  
//    TC3200 Color Sensor Reading Adjustment Chart:
//    
//    SO    S1    Scale 
//    LOW   LOW   Power Down
//    LOW   HIGH  2%
//    HIGH  LOW   20%
//    HIGH  HIGH  100%
//    For Arduino usually used 20%!! Set S0 HIGH / S1 LOW
//
//    S2    S3    Color Read:
//    LOW   LOW   Red
//    HIGH  HIGH  Green
//    LOW   HIGH  Blue
//    HIGH  LOW   No filter (Luminosity)
//    
//    Run below code, hold R/G/B color cards in front of the sensor at different distances. Start with RED,
//    followed by GREEN and BLUE. From the Serial Monitor note readings for each color card. 
//    Note the MIN/MAX reading figures for RED whilst holding RED, MIN/MAX figures for GREEN whilst holding
//    the GREEN card, followed by BLUE.
//    These MIN/MAX figures establish this individual TCS3200's sensor sensitivity.
//    We will use these MIN and MAX numbers from reading the RED card for Red mapping (and same for GREEN and BLUE)
//    in next code, inserting these MIN/MAX numbers to XXXColor = map (xFreq, XY1, XY2, 255, 0) 




int S0=4;           // asign Color Sensor SCALE pin S0 to Arduino pin 4
int S1=5;           // asign Color Sensor SCALE pin S1 to Arduino pin 4
int S2=6;           // asign Color Sensor Photodiode COLOR Choice pin S2 to Arduino pin 6
int S3=7;           // asign Color Sensor Photodiode COLOR Choice pin S3 to Arduino pin 6
unsigned int SensorOut=8;    // asign Color Sensor OUT pin to Arduino pin 8. 'int' 
                    //  assigns 0-255. For bigger no's we use 'unsigned int' up to 102,400!
                    //  as the clor sensor sends a reading of numbers up to 102,400! (pitch black)


int redPin=9;       // asign RED pin from LED to pin 9
int greenPin=10;    // asign GREEN pin from LED to pin 10
int bluePin=11;     // asign BLUE pin from LED to pin 11 

int rFreq;          // asign an integer for RED photodiode frequncy reading 
int gFreq;          // asign an integer for GREEN photodiode frequncy reading 
int bFreq;          // asign an integer for BLUE photodiode frequncy reading 
int LumFreq;        // asign an integer for LUMINOSITY photodiode frequncy reading


void setup() {
  Serial.begin(9600);   // Turn on serial port

// Setting LED pin modes:

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

  Serial.print("R= ");            // print the RED value
  Serial .print(rFreq);
  delay(100);

// Read the GREEN output frequency

  digitalWrite(S2, HIGH);         // Set photodiodes for GREEN reading
  digitalWrite(S3, HIGH); 

  gFreq=pulseIn(SensorOut, LOW);  // asign the frequency read to the gFreq variable

  Serial.print(" / G= ");            // print the GREEN value
  Serial.print(gFreq);
  delay(100);

 
// Read the BLUE output frequency

  digitalWrite(S2, LOW);          // Set photodiodes for GREEN reading
  digitalWrite(S3, HIGH);

  bFreq=pulseIn(SensorOut, LOW);  // asign the frequncy read to the bFreq variable

  Serial.print(" / B= ");            // print the BLUE value
  Serial.print(bFreq);
  delay(100);

// Read the LUMINOSITY output frequency

  digitalWrite(S2, HIGH);         // Set photodiodes for LUMINOSITY reading
  digitalWrite(S3, LOW);

  LumFreq=pulseIn(SensorOut, LOW);  //asign the frequncy read to the LumFreq variable

  Serial.print(" / Lum= ");          // print the LUMINOSTY value
  Serial.println(LumFreq);        // print with LN as we want next fresh one start with a new line!
  delay(1500);

}
