/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledred = 4;  // RED LED
int ledyellow = 7;  // YELLOW LED
int ledgreen = 8;;  // GREEN LED

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledred, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  delay(5000);               // wait for a second
  digitalWrite(ledyellow, HIGH);    // turn the YELLOW LED ON by making the voltage HIGH
  delay(250);               // wait for a second
  digitalWrite(ledred, LOW);   // turn the RED OFF on (LOW is the voltage level)
  digitalWrite(ledyellow, LOW);    // turn the YELLOW LED OFF by making the voltage LOW
  delay(1000);  
  digitalWrite(ledgreen, HIGH);    // turn the GREEN LED ON by making the voltage high
  delay(5000);               // wait for a second
  digitalWrite(ledgreen, HIGH);    // turn the GREEN LED OFF by making the voltage HIGH
  delay(5000);
  digitalWrite(ledgreen, LOW);    // turn the GREEN LED OFF by making the voltage LOW
  digitalWrite(ledyellow, HIGH);    // turn the YELLOW LED ON by making the voltage HIGH
  delay(1000);               // wait for a second
  
}
