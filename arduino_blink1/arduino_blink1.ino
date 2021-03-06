/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 6;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
               // wait for a second
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);               // wait for 1/2 second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(250);               // wait for 1/2 second
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);               // wait for 1/4 second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(250);               // wait for 1/4 second
}
