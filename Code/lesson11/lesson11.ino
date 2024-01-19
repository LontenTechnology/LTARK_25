#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int i=0;
void setup()
{
  Serial.begin(9600); 
  myservo.attach(9);  // modify each pin to adjust 
  myservo.write(i);
  delay(1000);
}

void loop() 
{
  for(i;i<180;i++)
  {
    myservo.write(i);
    delay(5);
  }
  for(i;i>0;i--)
  {
    myservo.write(i);
    delay(5);
  }
  delay(1000);
}

