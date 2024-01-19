#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Initialize OLED display object and set resolution to 128x64
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  Serial.begin(9600);

  // Initialize OLED display screen
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Set Text Style
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Display prompt information Drawing Shapes
  display.setCursor(30, 8);
  display.println("Drawing Shapes");

  // Drawing Text Square:
  display.setTextSize(1);
  display.setCursor(10, 25);
  display.println("Square:");

  // Draw a square inside the screen
  display.drawRect(15, 40, 20, 20, WHITE);  // (x, y, width, height, color)

  // Display Text Circle:
  display.setTextSize(1);
  display.setCursor(60, 25);
  display.println("Circle:");

  // Draw circles inside the screen
  display.drawCircle(80, 50, 12, WHITE);  // (centerX, centerY, radius, color)


  // Update display content
  display.display();
}

void loop() {

}


