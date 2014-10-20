#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  for(int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(random(255) / PI * 42, random(255) / PI * 42, random(255) / PI * 42));
      strip.show();
      delay(random(42));
  }
  for(int i = strip.numPixels(); i > 0; i--) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      strip.show();
      delay(random(42));
  }
}
