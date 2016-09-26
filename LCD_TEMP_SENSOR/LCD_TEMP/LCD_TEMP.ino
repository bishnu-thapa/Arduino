#include  <LiquidCrystal.h>         // Include the library to use a LCD display
#define          sensor           0        // Define the A0 pin as “sensor”

int  Vin;           //  Variable to read the value from the Arduino’s pin
float  Temperature; //  Variable that receives the converted voltage value to temperature
float     TF; // Variable to receive the converted value from  ºC to ºF
LiquidCrystal  lcd    (12, 11, 5, 4, 3, 2); 
/* The function above declares which Arduino’s pins will be used for controlling the LCD */
void  setup()
{
  lcd.begin(16, 2);                            //  It tells the Arduino that the display is a 16x2 type
  lcd.print("Temperature: ");           //  Send the text to the screen of the display.
}
void  loop()
{
  Vin = analogRead (sensor);  /*   Tells the Arduino to read the pin and stores the value in “Vin” */
  Temperature=(500*Vin)/1023;  /* Converts the voltage value into temperature and stores it into the “Temperature”  variable  (in  ºC)*/
  TF = ((9*Temperature)/5)+32; // Converts  ºC to ºF
  lcd.setCursor(0, 1);           // Moves  the cursor of the display to the next line
  lcd.print(TF);    // Exhibits the value of the temperature on the display
  lcd.print(" F");         // Writes “F” to indicate that it is in Fahrenheit scale.

  delay(1000);  //  Waits for a second to read the pin again
}
