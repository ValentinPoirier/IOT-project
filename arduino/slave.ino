#include <Adafruit_NeoPixel.h>
#define PIN 13
#define NUM_PIXELS 4

Adafruit_NeoPixel jewel = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_RGB + NEO_KHZ800);
int button0 = 2, button1 = 3, button2 = 4, button3 = 5;

void setup()
{
  jewel.begin();
  jewel.show();
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
}

void allumage_led(int button, int num){
  int value = digitalRead(button);
  if (value) {
    jewel.setPixelColor(num, 255, 0, 0);
  } else {
    jewel.setPixelColor(num, 50, 205, 50);
  }
}

void loop()
{
  allumage_led(button0, 0);
  allumage_led(button1, 1);
  allumage_led(button2, 2);
  allumage_led(button3, 3);
  jewel.show();
}