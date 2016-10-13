
#include <avr/pgmspace.h>
#include "MaxScroll.h"
        
void MaxScroll::command(volatile byte opcode, volatile byte data)
       
    {
        
    //enable the CS line
    
    digitalWrite(this->pinCS,LOW);
    
    //Now shift out the data as many times as there are devices

    for(int i = 0; i < this->noOfDevices;i++)

        {

        shiftOut(this->pinDIN,this->pinCLK,MSBFIRST,opcode);
        shiftOut(this->pinDIN,this->pinCLK,MSBFIRST,data);

        }

    digitalWrite(this->pinCS,HIGH);
        
    }
     
MaxScroll::MaxScroll(int pinCS,        // Chip Selection Pin 
               int pinDIN,             // Data In Pin
               int pinCLK,             // Data Clock
               int noOfDevices         // No Display Devices
              )

    {
    this->pinCS       = pinCS;
    this->pinDIN      = pinDIN;
    this->pinCLK      = pinCLK;
    this->noOfDevices = noOfDevices;

    pinMode(this->pinCS,OUTPUT);
    pinMode(this->pinDIN,OUTPUT);
    pinMode(this->pinCLK,OUTPUT);
    
    this->setStateStartup();        // Switch out of shutdown state.
    this->setNormalMode();          // Set all displays to NORMAL MODE
    this->setDisplayScanLimit(7);   // Set all displays to scan all available columns.
    this->setIntensity(1);          // Go halves on LED intensity.
    this->setDecodeMode(0);         // Dont use DECODE mode (7 digit BCD mode)
    }
  
  
void MaxScroll::setNormalMode()

    {

    this->command(OP_DISPLAYTEST,0);
      
    }
    
void MaxScroll::setTestMode()

    {
    
    this->command(OP_DISPLAYTEST,1);
      
    }
    
    
void MaxScroll::setStateStartup()

    {
       
    this->command(OP_SHUTDOWN,1);
     
    }
    
void MaxScroll::setStateShutdown()

    {
      
    this->command(OP_SHUTDOWN,0);
         
    }
 
void MaxScroll::setDecodeMode(volatile byte mode)

    {
    this->command(OP_DECODEMODE, mode);
    }

void MaxScroll::setDisplayScanLimit(volatile byte limit)

    {
      
    this->command(OP_SCANLIMIT,limit);
    
    }
    
void MaxScroll::setIntensity(volatile byte intensity)

    {
      
    this->command(OP_INTENSITY,intensity);
      
    }

void MaxScroll::print(int offset, const char * string)

    {
      
    for(int columns = 0; columns < 8; columns ++)
  
        {
        
        digitalWrite(this->pinCS,LOW);
        
        for(int devs = this->noOfDevices - 1; devs >= 0; devs--)
        
            {
            int offsetColumn = offset + (devs * 8) + columns;
            int charIndex    = offsetColumn / 6;
            char stringData  = string[charIndex];
            byte columnData  = pgm_read_byte_near(standardFontData + (((unsigned int) stringData) * 5) + (offsetColumn % 6));
       
            shiftOut(this->pinDIN,this->pinCLK,MSBFIRST,(columns % 8)+1);

            if((offsetColumn % 6) == 5)
                columnData = 0;

            shiftOut(this->pinDIN,this->pinCLK,MSBFIRST,columnData);
        
            }
            
        digitalWrite(this->pinCS,HIGH);
            
        }

    }    

int getPixelWidthOfString(const char *string)

    {

    return(strlen(string) * 6);

    }
   
