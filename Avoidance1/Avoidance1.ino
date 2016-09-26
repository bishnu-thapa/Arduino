/* Code Written by Roy Pe'er. I've explained all the code in the grey comments.
I recommend you to go over the code, examine it, play with it, improve it and modify it according to your needs. 
For more awesome videos, subsrice to my channel:
http://www.youtube.com/subscription_center?add_user=Roypeer1
*/
#include <AFMotor.h> // import your motor shield library
#define trigPin A0   // define the pins of your sensor
#define echoPin A1 

#define FAST   255   // Fast Speed for no near objects
#define MEDIUM 192   // Meduim Speed when aproaching object
#define SLOW   128   // Slow Speed when very near object / turning

#define FAR     100
#define NEARER  50
#define NEAR    25

AF_DCMotor motor1(1,MOTOR12_8KHZ); // set up motors.
AF_DCMotor motor2(2,MOTOR12_8KHZ);
 
int getDistance(uint8_t trigPin, uint8_t echoPin)
    
    {
    long duration, distance;
    
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); // delays are required for a succesful sensor operation.
    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10); //this delay is required as well!
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;// convert the distance to centimeters.
    return(distance);
    }


void forward(uint8_t mspeed)
    {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(mspeed);
    motor2.setSpeed(mspeed);
    }
    
void left(uint8_t mspeed)
    {
    motor1.setSpeed(mspeed);
    motor2.setSpeed(mspeed);
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    }


void right(uint8_t mspeed)
    {
    motor1.setSpeed(mspeed);
    motor2.setSpeed(mspeed);
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    }

void setup() 
    {
    Serial.begin(9600); // begin serial communitication  
    Serial.println("Motor test!");
    pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
    pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
    
    forward(200);
    }

 
void loop()

    {
    long distance; // start the scan    
    
     distance = getDistance(trigPin,echoPin);
     
     Serial.print(distance,DEC);
     Serial.print("\n");
     
     if(distance > FAR)                          // No near object go fast 
         forward(FAST);
         
     if(distance > NEARER and distance < FAR)    // Near object slow down
         forward(MEDIUM);
  
     if (distance < NEAR)                        // Very near object turn right slowly 
          right(SLOW);   
    }

