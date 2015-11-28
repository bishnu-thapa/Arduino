int LED_Pin = 6; // Use Pin 9 for the LED. (Any PWM Pin will work for this.)
int howBright;   // Intensity of the LED: [0 = Off], [255 = Brightly Lit]

void setup()
{
  pinMode(LED_Pin, OUTPUT);
} 

void loop()
{
  howBright = random(128,255);     // Change brightness to something between 128 and 255
  analogWrite(LED_Pin, howBright); // Illuminate the LED with the brightness picked
  delay(random(50,150));           // Makes LED seem to flicker when on for a random time
} 

