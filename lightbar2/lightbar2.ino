int upspeed = 100;
int downspeed = 100;
void setup() {
for (int i = 2; i < 10; i++) {
pinMode(i, OUTPUT);
}
}
void allLEDsOff(void)
{
for (int i = 2; i < 10; i++) {
digitalWrite(i, LOW);
}
}
void loop() {
for (int i = 2; i < 9; i++) {
allLEDsOff();
digitalWrite(i, HIGH);
delay(upspeed);
}
for (int i = 9; i > 2; i--) {
allLEDsOff();
digitalWrite(i, HIGH);
delay(downspeed);
}
}
