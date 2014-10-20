#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

int lastvalue = 0;
int value = 0;
int globalbrightness = 10;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show(); 
}

void loop() {
  clearall();
  value = analogRead(0);
  value = map(value, 0, 1023, 0, strip.numPixels());
  Serial.print(value);
  Serial.print(" _ ");
  Serial.println(lastvalue);
  if (lastvalue > value) {
    delay(100);
    for(int i = value; i < lastvalue; i--) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      strip.show();
      delay(12); 
    }
  } else if (lastvalue < value) {
    delay(100);
    for(int i = lastvalue; i < value; i++) {
      strip.setPixelColor(i, strip.Color(100, 100, 100));
      strip.show();
      delay(12); 
    }
  } else {
     // nothing
  }
  lastvalue = value;
}

void clearall() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
}

