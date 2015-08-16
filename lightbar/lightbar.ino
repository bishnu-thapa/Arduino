void setup() {
for (int i = 2; i < 10; i++) {
pinMode(i, OUTPUT);
}
int blink_speed = 200;
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
delay(blink_speed);
}
for (int i = 9; i > 2; i--); {
allLEDsOff();
digitalWrite(i, HIGH);
delay(blink_speed);
}
