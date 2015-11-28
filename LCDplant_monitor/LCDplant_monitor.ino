// Soil Moisture Sensor Hygrometer example code
// Code author:  aafent. This code is copy free, if you want please mention the author's name and/or the site
//Interface Description (4-wire)
//VCC: 3.3v-5v
//GND: GND
//DO: Digital output interface (0 and 1) threshold taken from potentiometer
//AO: Analog output interface

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

const int moistureAO = 0;

int AO = 0;
int tmp = 0;
int LED = 13;



void setup (){
  Serial.begin(9600);
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  
  // set up the LCD's number of columns and rows: 
  
  //legacy code - for testing
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Torbay Tech Jam");
  //lcd.setCursor(0,1);
  //lcd.print("November 2015");
  //delay(2000);
  
  
  
}
void loop ()
{
  tmp=analogRead( moistureAO );
  if ( tmp != AO ) 
  {
    AO=tmp;
    Serial.print("A=");
    Serial.println(AO);
    // print to lcd screen
    //lcd.begin(16, 2); //set up lcd
    //lcd.println ("Monitor Status");
    //lcd.setCursor(0,1);
    //lcd.print("A=");
    //lcd.print(AO);
    //lcd.print ("wet");
    //delay(2000);
  }
  
  delay (1000);
    {
if(analogRead(0) > 1000){ // depends on soil moisture
lcd.clear();
lcd.begin(16, 2);
//digitalWrite(LED,HIGH);
lcd.println ("Monitor Status");
lcd.setCursor(0,1);
lcd.print("dry");
//delay(1000);
//digitalWrite(LED,HIGH);
}
else
{
  if(analogRead(0) < 700)
  lcd.clear();
  lcd.begin(16, 2);  
  lcd.println ("Monitor Status");
  lcd.setCursor(0,1);
  lcd.print("wet");  
  //digitalWrite(LED, LOW);
  }
      }
  }

