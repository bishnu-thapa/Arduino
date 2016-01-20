

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor left_motor(1);
AF_DCMotor right_motor(2);

void setup() {
  // turn on motor
  mspeed(200);
 
  left_motor.run(RELEASE);
  right_motor.run(RELEASE);
}

void loop()
{
  long randomNumber = random(4);
 
  delay(500);
 
  switch(randomNumber)
  {
    case 0:  forward();
                   break;
                   
    case 1: reverse();
                  break;
                  
    case 2: left();
                  break;
                  
    case 3: right();
                  break;
  }
 
  delay(2000);
  stop();
 
}

void forward()
{
  left_motor.run(FORWARD);
  right_motor.run(FORWARD);
}

void reverse()
{
  left_motor.run(BACKWARD);
  right_motor.run(BACKWARD);
}

void stop()
{
  left_motor.run(RELEASE);
  right_motor.run(RELEASE);
}

void left()
{
  left_motor.run(BACKWARD);
  right_motor.run(FORWARD);
}

void right()
{
  left_motor.run(FORWARD);
  right_motor.run(BACKWARD);
}

void mspeed(int s)
{
  left_motor.setSpeed(s);
  right_motor.setSpeed(s);
}


