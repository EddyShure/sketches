#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);


int period = 5000;
int number = 1;
int lastnumber = 0;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void loop() {
  clearall();
  
  for (int i = 0; i < number; i++) {
    strip.setPixelColor(i, strip.Color(10, 10, 10));
    strip.show();
    delay(10);
  }
  delay(1000);
  
  if (number != (strip.numPixels() - 1)) {
    number = lastnumber + number;
  } else {
    number = 0;
    lastnumber = 0;
  }
  lastnumber = number;
}

void clearall() {
    for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
}
