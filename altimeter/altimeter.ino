#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>

/*
 * Author: Tharny Elilvannan
 * Last Updated: October 10, 2024
 * Purpose: Gives user the altittude.
 */

// initiate barometric pressure sensor 
Adafruit_BMP085 bmps;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// setup runs once
void setup() {

  // initializes how big LCD screen is
  lcd.begin(16, 2);

  lcd.display();

  lcd.print("Initializing...");

  delay(1000);

  if (bmps.begin() != true) {
    lcd.println("Error. Check wiring.");
  } // end of if statement

  while (1) {

  } // end of while

} // end of setup function

// loop runs repeatedly
void loop() {
  
  double seaLevelPressure = bmps.readSealevelPressure();

  lcd.print("Altitude = ");
  lcd.print(bmps.readAltitude(seaLevelPressure * 100));
  lcd.println(" m");
  delay(1000);

} // end of loop function