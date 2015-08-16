
int upspeed = 500;
int downspeed = 500;
void setup() {
for (int i = 2; i < 11; i++) {
pinMode(i, OUTPUT);
}
}
void allLEDsOff(void)
{
for (int i = 2; i < 11; i++) {
digitalWrite(i, LOW);
}
}
void loop() {
for (int i = 2; i < 10; i++) {
allLEDsOff();
digitalWrite(i, HIGH);
delay(upspeed);
}
for (int i = 10; i > 2; i--) {
allLEDsOff();
digitalWrite(i, HIGH);
delay(downspeed);
}
}
