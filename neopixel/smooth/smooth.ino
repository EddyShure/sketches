int red = 5;
int green = 6;
int blue = 3;

int time = 0;
int periode = 5000;
int value_r, value_g, value_b;
int globalbrightness = 50;

void setup() {
  Serial.begin(115200);
}

void loop() {
  rgbShow();
  analogWrite(red, value_r * globalbrightness / 255);
  analogWrite(green, value_g * globalbrightness / 255);
  analogWrite(blue, value_b * globalbrightness / 255);
  //delay(100);
  //analogWrite(red, 0);
  //analogWrite(blue, 0);
  //analogWrite(green, 0);
  //ydelay(100);
}

void rgbShow() {
  time = millis();
  value_r = 128+127*cos(2*PI/periode*time);
  value_g = 128+127*cos(2*PI/periode*time * 0.1337);
  value_b = 128+127*cos(2*PI/periode*time * 0.2337);
}
