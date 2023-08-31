
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int irPin1=9;
int irPin2=8;
int count=0;
boolean state1 = true;
boolean state2 = true;
boolean insideState = false;
boolean outsideIr=false;
boolean isPeopleExiting=false;
int i=1;
void setup() {
Serial.begin(9600);
 lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  lcd.print("Visitor Counter"); // Printing "Visitor Counter" to the LCD
pinMode(irPin1, INPUT);
pinMode(irPin2, INPUT);
}
void loop() {  
  if ((digitalRead(irPin1)==LOW) && (i==1) && (state1==true)){
     outsideIr=true;
     delay(100);
     i++;
     state1 = false;
  }
   else if ((digitalRead(irPin2)==LOW) && (i==2) &&   (state2==true)){
     Serial.println("Entering inside the room");
     outsideIr=true;
     delay(100);
     i = 1 ;
     count++;
       lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
     Serial.print("No. of people inside room: ");
     Serial.println(count);
     state2 = false;
  }
  if (digitalRead(irPin1)){
     state1 = true;
    }
     if (digitalRead(irPin2)){
     state2 = true;
    }  
  
}
