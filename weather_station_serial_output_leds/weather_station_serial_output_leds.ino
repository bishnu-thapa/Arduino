#include "DHT.h"
#define DHTPIN 8     // pin DHT is connected
#define DHTTYPE DHT11  

int templed = 3; // blue ked
int humidled = 4; // red led

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  //lcd.begin(16, 2);
  pinMode(templed, OUTPUT); 
    pinMode(humidled, OUTPUT); 
}
void loop() {
  //digitalWrite(templed, LOW);//turn led off
  //digitalWrite(humidled, LOW);  // turn led off
   float h = dht.readHumidity();
  float t = dht.readTemperature();
  // t = t* 9/5 + 32; // display as farenheit
    t = t; // display as centigrade
    if (isnan(t) || isnan(h)) {
    //lcd.setCursor(0, 0);
    //lcd.print("Failed to read from DHT");
    //Serial.println("Failed to read from DHT");
  } else {
    delay(1000); // add delay to stop flickering screen
    Serial.begin(9600);
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" C");
    // turn off LEDs
    
 {  
if(templed >= 19);  // this number depends temperature
digitalWrite(templed, HIGH);//turn led ON

}
 {  
if(humidled >= 47);  // this number depends humidity
digitalWrite(humidled, HIGH);//turn led ON
delay(1000);
}
  
  }
}

//temp and humidity
