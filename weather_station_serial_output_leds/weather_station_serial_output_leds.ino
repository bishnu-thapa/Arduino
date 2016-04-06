#include "DHT.h"
#define DHTPIN 8 // Pin for humidity and temperature sensor
#define DHTTYPE DHT11  

#define TEMPLED  3 // Blue led for temperature
#define HUMIDLED 4 // Red led for humidity

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(TEMPLED, OUTPUT); 
  pinMode(HUMIDLED, OUTPUT); 
}
void loop() {
  // Read the temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Make sure we actually get some data
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    return;
  }
  
  // Output to serial console
  Serial.print("Humidity: "); 
  Serial.println(h);
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println("C");
  delay(1000);

  if (t >= 20) { // Temperature
    digitalWrite(TEMPLED, HIGH);
  } else {
    digitalWrite(TEMPLED, LOW);
  }

  if (h >= 47) { // Humidity
    digitalWrite(HUMIDLED, HIGH);
  } else {
    digitalWrite(HUMIDLED, LOW);
  }
}

//version 2,0 by Samadi
