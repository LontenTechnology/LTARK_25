#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>
// Initialize OLED display object and set resolution to 128x64
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);

  // Initialize OLED display screen
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  Serial.println("");
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" ℃, ");
  Serial.print((int)humidity); Serial.println(" %");
  // Set Text Style
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(45, 8);
  display.println("T & H");
  
  display.setCursor(0, 18);
  display.println("TEMP:");
  display.setCursor(45, 18);
  display.println(temperature);
  display.setCursor(60, 18);
  display.println("C");

  display.println("H:");
  display.setCursor(45, 28);
  display.println(humidity);
  display.setCursor(60, 28);
  display.println("%RH");
  display.display();
 
  // DHT11 sampling rate is 1HZ.
  delay(1000);
  display.clearDisplay();
}
