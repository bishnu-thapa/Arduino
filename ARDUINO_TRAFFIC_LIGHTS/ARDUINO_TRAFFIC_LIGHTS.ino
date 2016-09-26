/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
// traffic leds
int ledred = 4;  // RED LED 5mm
int ledyellow = 7;  // YELLOW LED 5mm
int ledgreen = 8;
;  // GREEN LED 5mm
// leds for red / green man
//int ledredM = 10;  // Red LED 3mm
//int ledgreenM = 11;  // Green LED 3mm


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);  

}

// the loop routine runs over and over again forever:
void loop() {
  // STOP TRAFFIC AND TURN GREEN MAN ON FOR PEDESTRIANS

  digitalWrite(ledred, HIGH);   // turn the RED LED on (HIGH is the voltage level)

  //digitalWrite(ledgreenM, HIGH);   // turn the 3mm green man ON



  delay(5000);               // wait for 5 second



  digitalWrite(ledyellow, HIGH);    // turn the YELLOW LED ON by making the voltage HIGH
  delay(1000);               // wait for a second

  // NOW TURN GREEN MAN OFF AND RED MAN ON

  //digitalWrite(ledredM, HIGH);   // RED MAN ON
  //digitalWrite(ledgreenM, LOW);    // GREEN MAN OFF


  digitalWrite(ledred, LOW);   // turn the RED OFF on (LOW is the voltage level)
  digitalWrite(ledyellow, LOW);    // turn the YELLOW LED OFF by making the voltage LOW
  digitalWrite(ledgreen, HIGH);    // turn the GREEN LED ON by making the voltage high

  delay(1000);               // wait for a second


  digitalWrite(ledgreen, HIGH);    // turn the GREEN LED on by making the voltage HIGH



    delay(5000);
  digitalWrite(ledgreen, LOW);    // turn the GREEN LED OFF by making the voltage LOW
  digitalWrite(ledyellow, HIGH);    // turn the YELLOW LED ON by making the voltage HIGH
  delay(1000);               // wait for a second
  digitalWrite(ledyellow, LOW);    // turn the YELLOW LED OFF by making the voltage LOW
  //digitalWrite(ledredM, LOW);   // RED MAN OFF
} 

