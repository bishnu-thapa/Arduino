int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
 
 setRgb(0,0,0); // All colours off
}

void loop() {
 int Rgb[3];

 Rgb[0] = 255;
 Rgb[1] = 0;
 Rgb[2] = 0; 

 for (int decrease = 0; decrease < 3; decrease += 1) { // colours increase and decrease
 int increase = decrease == 2 ? 0 : decrease + 1;

 for(int i = 0; i < 255; i += 1) { // Fades the colours
 Rgb[decrease] -= 1;
 Rgb[increase] += 1;
 
 setRgb(Rgb[0], Rgb[1], Rgb[2]);
 delay(5);
 }
 }
}

void setRgb( int red, int green, int blue) {
 analogWrite(redPin, red);
 analogWrite(greenPin, green);
 analogWrite(bluePin, blue);
 }
