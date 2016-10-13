#include <MaxScroll.h>

#define DISPLAY_DIN_PIN 5
#define DISPLAY_CS_PIN  6
#define DISPLAY_CLK_PIN 7

#define NUMBER_OF_DISPLAYS 1


char message[]          = " Congratulations! you have managed to complete the first phase of the Torbay TechJam mini matrix sign builder workshop at Paignton Library    ";

int pixelWidthOfMessage = getPixelWidthOfString(message);
MaxScroll vdu1(DISPLAY_CS_PIN,DISPLAY_DIN_PIN,DISPLAY_CLK_PIN,NUMBER_OF_DISPLAYS);

void setup()
{
  Serial.begin(9600);
  vdu1.setIntensity(7);
}

void loop()

    {

    for(int i = 0; i < pixelWidthOfMessage;i++)
        {
        vdu1.print(i,message);
        delay(40);
        }

} 
