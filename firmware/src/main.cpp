#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);

  tft.setCursor(20, 40);
  tft.println("Vault-Tec");

  tft.setCursor(20, 80);
  tft.println("PIP-OS BOOT");

  tft.setCursor(20, 130);
  tft.println("Hello, Vault Dweller");
}

void loop() {
}