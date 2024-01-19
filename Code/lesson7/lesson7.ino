#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2); // set the LCD address to 0x27 for a16 chars and 2 line display

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   lcd.init (); // initialize the lcd
   lcd.init (); // Print a message to the LCD.
   lcd.backlight ();
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   lcd.setCursor (3,0);
   lcd.print ("distance:"); 
   lcd.setCursor (3,1);
   lcd.print (a); 
   lcd.setCursor (6,1);
   lcd.print ("cm"); 
   delay(1000);
   lcd.clear (); // initialize the lcd
}
