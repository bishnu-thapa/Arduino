// Soil Moisture Sensor Hygrometer example code
// Code author:  aafent. This code is copy free, if you want please mention the author's name and/or the site
//Interface Description (4-wire)
//VCC: 3.3v-5v
//GND: GND
//DO: Digital output interface (0 and 1) threshold taken from potentiometer
//AO: Analog output interface
const int moistureAO = 0;

int AO = 0;
int tmp = 0;
int LED = 13;

void setup (){
  Serial.begin(9600);
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  
}
void loop ()
{
  tmp=analogRead( moistureAO );
  if ( tmp != AO ) 
  {
    AO=tmp;
    Serial.print("A=");
    Serial.println(AO);
  }
  
  delay (1000);
    {
if(analogRead(0) > 900){ // depends on soil moisture

digitalWrite(LED,HIGH);
delay(1000);
digitalWrite(LED,HIGH);
}else{
digitalWrite(LED, LOW);
}
    }
}

