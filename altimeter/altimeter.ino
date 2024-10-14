/*
 * Author: Tharny Elilvannan
 * Last Updated: October 14, 2024
 * Purpose: Gives user the altittude and temperature in Celsius, measured every 10 seconds.
 */

#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>

// initiate barometric pressure sensor 
Adafruit_BMP085 bmps;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// must be updated frequently
float seaLevelPressure = 101000;

// setup runs once
void setup() {

  // initializes how big LCD screen is
  lcd.begin(16, 2);

  lcd.display();

  lcd.print("Initializing...");

  delay(5000);

  lcd.clear();

  if (bmps.begin() != true) {
    lcd.println("Error.");
  } // end of if statement

} // end of setup function

// loop runs repeatedly
void loop() {
  
  lcd.setCursor(0, 0);

  lcd.print("Altitude: ");
  lcd.setCursor(0, 1);
  lcd.print(bmps.readAltitude(seaLevelPressure));
  lcd.println(" meters        ");
  delay(10000);
  lcd.clear();

  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print(bmps.readTemperature());
  lcd.println(" *C        ");
  delay(10000);
  lcd.clear();

} // end of loop function