#include "Wire.h"
#include <LiquidCrystal.h>
#define DS1307_I2C_ADDRESS 0x68
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
byte bcdToDec(byte val)
{
  return ( (val/16*10) + (val%16) );
}
 
void getDateDs1307(byte *second,byte *minute,byte *hour,byte *dayOfWeek,byte *dayOfMonth,byte *month,byte *year)
{
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
 
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
 
  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}
 
 
void setup()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  Wire.begin();
  // AMEND IF YOUR USING A DIFFERENT LCD SCREEN //
  lcd.begin(16, 2);
}
 
void loop()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  String s, m, d, mth, h;
   
  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
 
  if (second < 10) { s = "0" + String(second); } else { s = String(second); }
  if (minute < 10) { m = "0" + String(minute); } else { m = String(minute); }
  h = String(hour);
  if (dayOfMonth < 10) { d = "0" + String(dayOfMonth); } else { d = String(dayOfMonth); }
  if (month < 10) { mth = "0" + String(month); } else { mth = String(month); }
   
  char* days[] = { "NA", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
   
  lcd.clear();
  // JUMP TO CENTER ON A 16X2 SCREEN //
  lcd.setCursor(4,0);
  // CHANGE THE FOLLOWING TO SET THE DATE IN TO YOUR PREFERED ORDER //
  lcd.print(h + ":" + m + ":" + s);
  // NEXT LINE, 1 SPACE IN FROM THE LEFT //
  lcd.setCursor(1,1);
  // PREFIX THE 20 AS THE RTC CHIP ONLY USES 2 DIGITS FOR THE YEAR //
  lcd.print(String(days[dayOfWeek]) + " " + d + "/" + mth + "/20" + year);
  delay(1000); // Wait 1 second
}
//http://computers.tutsplus.com/tutorials/using-an-arduino-as-an-lcd-clock--cms-21696
