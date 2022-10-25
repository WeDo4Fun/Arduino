#include <Wire.h>

#include <LiquidCrystal_I2C.h>        // Incl LCD with I2C Library
#include "DHT.h"                      // Incl DHT Library

#define DHTPIN 5                      // DHT22 output pin attacehd to Arduino Pin 2
#define DHTTYPE DHT22                 // Define DHT type; DHT11 / DHT21 / DHT22


      // LCD Pin conenctions
      // VCC / GND to same
      // SDA/SCL fm I2C to Arduino SDA/SCL

LiquidCrystal_I2C lcd(0x27, 16, 2);   // We create object 'lcd' on address 0x27 with 16x2 screen size. 
                                      // If have more than one LCD, can call them lcd2 etc

float hum;                            // Create/define 'hum' float (decimal) for humidity reading
float temp;                           // Create/define 'temp' float (decimal) for temp reading 

DHT dht(DHTPIN, DHTTYPE);             // Initialize DHT sensor
                                    
void setup()
{
  Serial.begin(9600);
  lcd.init();                         // Start LCD comm
  dht.begin();                        // Start DHT Sensor
  lcd.backlight();                    // Turn on LCD backlight
  lcd.clear();                        // Clear LCD screen
  lcd.setCursor(0,0);                 // Set cursoer to 1st line, 4th row
  lcd.print("I'm alive!");            // Print 
  delay(2000);                        // Wait for 5 seconds
  lcd.clear();                        // Clear LCD screen


  byte degree[8] = {                  // define/draw 'degree' sign
    0b01100,
    0b10010,
    0b10010,
    0b01100,
    0b00000,
    0b00000,
    0b00000,
    0b00000    
  };
  
  lcd.createChar(0, degree);          // Create new character No.0 for degree sign
  
  
}

void loop() {
  delay(60000);                        // Delay helps DHT11 Sensor to stabilise and have required reading time

  hum = dht.readHumidity();           // Get humidity value
  temp = dht.readTemperature();       // Get temperature value
  lcd.clear();                        // Clear display

  // Show temperature on LCD:
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(temp);
  lcd.write(byte(0));                 // add the 'degree' sign 
  lcd.print("c");

  // Show humidity on LCD:
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(hum);
  lcd.print(" %");

  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print("c");
  Serial.print("  //  ");
  Serial.print("Humid: ");
  Serial.print(hum);
  Serial.println(" %");

}
