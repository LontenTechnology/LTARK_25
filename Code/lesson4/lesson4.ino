#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>
// Initialize OLED display object and set resolution to 128x64
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

int soil_value=0; 
void setup() {
  Serial.begin(9600);
  // Initialize OLED display screen
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  soil_value = analogRead(0); // get adc value 
   // Set Text Style
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.println("value:");
  display.setCursor(35, 8);
  display.println(soil_value);
  if(soil_value>600) 
  {
    Serial.println("I'm thirsty"); 
    display.setCursor(0, 18);
    display.println("I'm thirsty");
  } 
  Serial.println(soil_value); 
  display.display();
  delay(1000);
  display.clearDisplay();
}

