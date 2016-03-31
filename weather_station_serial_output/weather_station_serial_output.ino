#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8     // pin DHT is connected
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  lcd.begin(16, 2);
}
void loop() {
   float h = dht.readHumidity();
  float t = dht.readTemperature();
  // t = t* 9/5 + 32; // display as farenheit
    t = t; // display as centigrade
    if (isnan(t) || isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read from DHT");
    //Serial.println("Failed to read from DHT");
  } else {
    //lcd.clear();
    //lcd.setCursor(0, 0);
    //lcd.print("Humidity: ");
    //lcd.print(h);
    //lcd.print("%");
    //lcd.setCursor(0, 1);
    //lcd.print("Temp: ");
    //lcd.print(t);
    //lcd.print(" C");
    delay(1000); // add delay to stop flickering screen
    Serial.begin(9600);
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" C");
  }

