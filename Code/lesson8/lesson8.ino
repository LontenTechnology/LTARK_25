int ledRed = 11;                
int ledYel = 10;               
int ledGre = 9;              
int ledBlu = 8;               
int KEY = 2;                 // Connect Touch sensor on Digital Pin 2
 
void setup(){
  pinMode(ledRed, OUTPUT);      
  pinMode(ledYel, OUTPUT);  
  pinMode(ledGre, OUTPUT);  
  pinMode(ledBlu, OUTPUT);  
  pinMode(KEY, INPUT);       //Set touch sensor pin to input mode
}
 
void loop(){
   if(digitalRead(KEY)==HIGH) {      //Read Touch sensor signal
        digitalWrite(ledRed, HIGH);  
        delay(500);
        digitalWrite(ledYel, HIGH);   
        delay(500);
        digitalWrite(ledGre, HIGH);   
        delay(500);
        digitalWrite(ledBlu, HIGH);   
        delay(500);
        digitalWrite(ledRed, LOW);   
        delay(500);
        digitalWrite(ledYel, LOW);   
        delay(500);
        digitalWrite(ledGre, LOW);   
        delay(500);
        digitalWrite(ledBlu, LOW);   
     }
   else
   {
        digitalWrite(ledRed, LOW);    // if Touch sensor is LOW, then turn off the led
        digitalWrite(ledYel, LOW); 
        digitalWrite(ledGre, LOW); 
        digitalWrite(ledBlu, LOW); 
   }
}
