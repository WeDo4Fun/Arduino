#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // We create object 'lcd' on address 0x27 with 16x2 screen size. 
                                      // If have more than one LCD, can call them lcd2 etc
                                     
void setup()
{
  lcd.init();                         // Start LCD comm
  lcd.backlight();                    // Turn on LCD backlight
  lcd.clear();                        // Clear LCD screen
  lcd.setCursor(0,0);                 // Set cursoer to 1st line, 4th row
  lcd.print("I'm alive!");            // Print 
  delay(5000);                        // Wait for 5 seconds
  lcd.clear();                        // Clear LCD screen
}
 
 
void loop() {
/*
  //  Demo 1 - Flash back light: 
  lcd.setCursor(0,0); 
  lcd.print("Back light demo");
  lcd.setCursor(0,1);
  lcd.print("4 times"); 
  delay(2000);
  lcd.clear();

  for(int i=0; i<4; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }

  // Turn backlight on:
  lcd.backlight();
*/

  // Demo 2 - Scroll:
  lcd.setCursor(0,0);                 // Set cursor ot beg of 1st line
  lcd.print("Scroll demo - ");
  delay(1500);
  lcd.autoscroll();                   // Set the dispaly to autoscroll
  for (int thisChar=0; thisChar<10; thisChar++) {       // we instruct to to print form 0 to 9
    lcd.print(thisChar);
    delay(500);
  }

  lcd.noAutoscroll();                 // We have to turn of autoscroll

  lcd.clear();                        // Clear screen

  delay (1000);

  // Demo 3 - Make custom characters:
  // We are on a 5x8 dot mapping the charachter
  byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000    
  };

  byte smiley[8] = {
    0b00000,
    0b00000,
    0b01001,
    0b00000,
    0b00000,
    0b01001,
    0b00110,
    0b00000
  };

  byte armsDown[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
  };
  byte armsUp[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
  };

  // To chreate character we use createChar(# no asigned, name given aboove):

  lcd.createChar(0, heart);   // Created new character no, 0 suing 'heart' shape above
  lcd.createChar(1, smiley);
  lcd.createChar(2, armsDown);
  lcd.createChar(3, armsUp);  // We can create MAX 8 custom characters

  // Use characters: 

  lcd.setCursor(0,0);
  lcd.print("I ");
  lcd.write(byte(0));         // We call the assigned (0-8) custom character with lcd.write(byte(#)); 
  lcd.print(" Isabel ");
  lcd.write(byte(1));

  for (int manChar=0; manChar <10; manChar++) {
    lcd.setCursor(4,1);
    lcd.write(byte(2));
    delay(500);
    lcd.setCursor(4,1);
    lcd.write(byte(3));
    delay(500); 
  }

  /* if you want to change the man arm Up/DOWN with a potentiometer: 
   * attach the potentiometer (1 to GRD / 2 to A0 / 3 to 5V) 
   * int sensorReading = analogRead(A0);    // reads a number from 0 to 1023!
   * int delayTime = map(sensorReading, 0, 1023, 200, 1000)   // convert the reading fm 200 milisec to 1 sec!
   * insert 'delayTime' into delays!
   */
 
}
