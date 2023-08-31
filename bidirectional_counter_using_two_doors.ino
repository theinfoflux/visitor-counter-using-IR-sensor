
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define in 8  // Defining In Sensor
#define out 9 // Defining Out Sensor

#define buzzer 10 

int count = 0; // Declaring count Value
int inside=0;
int outside=0;
void setup()
{
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  delay(2000); // Delay of 2 seconds
  pinMode(in,INPUT); // Setting up In Sensor as INPUT 
  pinMode(out,INPUT); // Setting up Out Sensor as INPUT
  pinMode(buzzer,OUTPUT); // Setting up Bulb(Relay) pin as OUTPUT  
 
}

void loop()
{  
  
  int in_value = digitalRead(in); // Setting Variables & Reading Values from In Sensor
  int out_value = digitalRead(out); // Setting Variables & Reading Values from Out Sensor
    
  if(count==0)
  {
  digitalWrite(buzzer,HIGH);
  }
   lcd.clear();
lcd.setCursor(0, 0);
lcd.print("IN: ");
lcd.setCursor(8, 0);
lcd.print("OUT: ");
lcd.setCursor(0, 1);
lcd.print("Total Inside: ");
lcd.setCursor(14, 1);
lcd.print(count);
lcd.setCursor(4, 0);
lcd.print(inside);
 lcd.setCursor(13, 0);
    lcd.print(outside);
    delay(100);
  if(in_value == LOW)
  {
    count++;
    inside = inside +1;
      if(count<0)
    {
     inside=0;
     outside=0;
      count=0;
      }
    delay(100);
  }                                                       // Conditions
  
  if(out_value == LOW)
  {
    count--;
    outside = outside +1;
    if(count<0)
    {
      inside=0;
      outside=0;
      count=0;
      }
    delay(100);
  }                                                        // Conditions
 
                                                       // Conditions
  
  else
  {
    digitalWrite(buzzer,LOW);    
  }  


   
  // Conditions
}
