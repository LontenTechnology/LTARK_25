#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>
// Initialize OLED display object and set resolution to 128x64
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

int value=0; 
void setup() {
  // Initialize OLED display screen
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(7,INPUT);
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  value = digitalRead(7); // get adc value 
   // Set Text Style
  display.setCursor(0, 8);
  display.println("value:");
  display.setCursor(35, 8);
  display.println(value);
  if(value==1){
    display.setCursor(0, 18);
    display.println("no obstacles");
  }else{
    display.setCursor(0, 18);
    display.println("obstacles");
  }
  display.display();
  delay(1000);
  display.clearDisplay();
}

