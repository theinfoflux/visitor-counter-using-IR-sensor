
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int inside;
int outside;
const int ir1 = 8;
const int ir2 = 9;
const int buzzer = 10;
int count = 0;
boolean ir1Triggered = false;
unsigned long ir1Time;
byte currStateA;
byte prevStateA = HIGH;
boolean ir2Triggered  = false;
unsigned long ir2Time;
byte currStateB ;
byte prevStateB = HIGH;
void setup() {
  // put your setup code here, to run once:
 Serial.begin (9600);
 lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.print("Visitor Counter"); //
pinMode (ir1, INPUT);
pinMode (ir2, INPUT);
pinMode (buzzer, OUTPUT);

}

void loop() {

currStateA = digitalRead(ir1);



 if (currStateA != prevStateA)

 {

       if (currStateA == LOW)

       {

       ir1Triggered = true;

       ir1Time = millis ();

       }

 }

// prevStateA = currStateA;



 currStateB = digitalRead (ir2);

 if (currStateB != prevStateB)

 {

 if (currStateB == LOW)

 {

 ir2Triggered = true;

 ir2Time = millis ();

 }

 }

// prevStateB = currStateB;



 if (ir2Triggered && ir1Triggered)

{

 if (ir1Time> ir2Time)

 {

 count ++;

    
    inside = inside +1;
    if(count<0)
    {
      count=0;
      inside=0;
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
   
 Serial.println(count);

 delay(500);

 }

 if (ir2Time> ir1Time)

 {

 count--;
    outside = outside +1;

    if(count<0)
  {  
    count=0;
    outside=0;
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

 }

 ir1Triggered = false;

 ir2Triggered  = false;

}
 if(count==0)
  {
    lcd.clear();
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Buzzer is on");
    delay(200);
  }                                                       // Conditions
  
  else
  {
    digitalWrite(buzzer,LOW);    
  }                 
}
