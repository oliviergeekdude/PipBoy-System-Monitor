#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

#define PIP_GREEN 0x07E0
#define PIP_DARK  0x0000
#define PIP_DIM   0x0320

void drawHeader() {
  tft.setTextColor(PIP_GREEN, PIP_DARK);
  tft.setTextSize(2);
  tft.setCursor(10, 8);
  tft.print("PIP-OS v0.1");

  tft.setTextSize(1);
  tft.setCursor(252, 13);
  tft.print("STAT");

  tft.drawLine(0, 32, 320, 32, PIP_GREEN);
}

void drawBar(int x, int y, int w, int h, int value) {
  tft.drawRect(x, y, w, h, PIP_GREEN);
  int fill = map(value, 0, 100, 0, w - 4);
  tft.fillRect(x + 2, y + 2, fill, h - 4, PIP_DIM);
}

void drawMetric(const char* label, int value, int x, int y) {
  tft.setTextColor(PIP_GREEN, PIP_DARK);
  tft.setTextSize(2);
  tft.setCursor(x, y);
  tft.print(label);

  tft.setCursor(x + 62, y);
  tft.print(value);
  tft.print("%");

  drawBar(x, y + 24, 130, 12, value);
}

void drawTabs() {
  tft.drawLine(0, 210, 320, 210, PIP_GREEN);

  tft.setTextSize(1);
  tft.setCursor(12, 222);
  tft.print("[STAT]");

  tft.setCursor(80, 222);
  tft.print("DATA");

  tft.setCursor(138, 222);
  tft.print("RAD");

  tft.setCursor(188, 222);
  tft.print("INV");

  tft.setCursor(238, 222);
  tft.print("MAP");
}

void drawScanlines() {
  for (int y = 36; y < 210; y += 8) {
    tft.drawFastHLine(0, y, 320, 0x0100);
  }
}

void drawStatPage() {
  tft.fillScreen(PIP_DARK);

  drawHeader();

  drawMetric("CPU", 48, 14, 50);
  drawMetric("GPU", 36, 174, 50);
  drawMetric("RAM", 72, 14, 105);
  drawMetric("DSK", 61, 174, 105);

  tft.setTextSize(2);
  tft.setCursor(18, 162);
  tft.print("CPU TEMP  67C");

  tft.setCursor(18, 185);
  tft.print("GPU TEMP  61C");

  drawTabs();
  drawScanlines();
}

void setup() {
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  tft.init();
  tft.setRotation(1);
  drawStatPage();
}

void loop() {
}