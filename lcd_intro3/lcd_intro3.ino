/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver. There are many of them out there, and you  can usually tell them by the 16-pin interface.
 
 This sketch prints "Arduino Sketch" to the LCD and uses the scrollDisplayLeft() and scrollDisplayRight() methods to scroll the text.
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Torbay Tech Jam");
  lcd.setCursor(0,1);
  lcd.print("August 2015");
  delay(2000);
}

void loop() {
  // scroll 20 positions (string length) to the left 
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(75);

  }
    // scroll 20 positions (display length + string length) to the left
    // to move it back to center:
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(75);
  }
  // delay at the end of the full loop:
  delay(2000);
}
