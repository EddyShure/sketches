#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int val = 0;
byte count = 0;
byte history[5];

byte globalbrightness = 50;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
}

void loop() {
  val = analogRead(0);
  
  val = map(val, 0, 1023, 0, strip.numPixels());
  history[count] = val;
  blinkone();
  
  count++;
  count = count % 5;
  
}

void blinkone() {
  clearall();
  strip.setPixelColor((history[getindex(count - 1)]), rgb(globalbrightness / 8));
  strip.setPixelColor((history[getindex(count - 2)]), rgb(globalbrightness / 16));
  strip.setPixelColor((history[getindex(count - 3)]), rgb(globalbrightness / 32));
  strip.setPixelColor(history[count], rgb(globalbrightness));
  strip.show();
  delay(50);
  }

int rgb(int brightness) {
   byte red = 255;
   byte green = 255;
   byte blue = 255; 
   return strip.Color(red * brightness / 255, green * brightness / 255, blue * brightness / 255);
}

int getindex(int count) {
  while (count >= 5) {
    count = count - 5;
  }
  while (count < 0) {
    count = count + 5;
  }
  return count;
}

void clearall() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}


