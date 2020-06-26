#include <LiquidCrystal.h> //bibliothèque d'écrans
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#define PIN 7
#define NUMPIXELS 7 // numero de leds
#define LCD_Backlight 6
#define MOTOR 1

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

long tick;
int delayval = 100;// tempo de delay
int second; 
int minute = 51;
int hour = 15;
int day = 25;
int month = 6;
int year = 2020;

void set_color(int redColor, int greenColor, int blueColor){
  for(int i = 0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i,pixels.Color(redColor, greenColor, blueColor));    
  }
  pixels.show();
  delay(delayval);
}

void tickClock() {
  second = second + 1;
    if (second == 60) {
        minute = minute +1;
        second = 0;
   } 
    if (minute == 60) {
        hour = hour + 1;
        minute = 0 ;
    }
    if (hour == 24) { 
        hour = 0;
        day = day + 1;
    }
    if (day == 31) { 
        month = month + 1;
        day = 0;
    }
    if (month == 12) {
        year = year + 1;
        month = 0;
    }
      lcd.setCursor(6, 0); lcd.print(":");
    lcd.setCursor(9, 0); lcd.print(":");
    if (hour <= 9) {
      lcd.setCursor(4, 0);
      lcd.print("0"); 
      lcd.setCursor(5, 0); lcd.print(hour);
    }
    else if (hour > 9) {
      lcd.setCursor(4, 0); lcd.print(hour);
    }

    if (minute <= 9) {
      lcd.setCursor(7, 0); lcd.print("0");
      lcd.setCursor(8, 0); lcd.print(minute);
    }
    else if (minute > 9) {
      lcd.setCursor(7, 0); lcd.print(minute);
    }

    if (second <= 9) {
      lcd.setCursor(10, 0); lcd.print("0");
      lcd.setCursor(11, 0); lcd.print(second);
    }
    else if (hour > 9) {
      lcd.setCursor(10, 0); lcd.print(second);
    }
      
    lcd.setCursor(5, 1); lcd.print("/");
    lcd.setCursor(8, 1); lcd.print("/");

    if (day <= 9) {
        lcd.setCursor(3, 1); lcd.print("0");
        lcd.setCursor(4, 1); lcd.print(day);
        }
        else if (day > 9) {
        lcd.setCursor(3, 1); lcd.print(day);
        }
    if (month <= 9) {
        lcd.setCursor(6, 1); lcd.print("0");
        lcd.setCursor(7, 1); lcd.print(month);
        }
        else if (month > 9) {
        lcd.setCursor(6, 1); lcd.print(month);
        }
        lcd.setCursor(9, 1); lcd.print(year); 
  }

void setup() {
  pixels.begin();
  lcd.begin(16, 2); //16 caractères et 2 lignes
  pinMode(LCD_Backlight, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  analogWrite(LCD_Backlight, 256);
  digitalWrite(MOTOR, HIGH);
  //servo0.attach(4);
  //servo1.attach(3);
  //servo2.attach(2);
  //servo3.attach(1);
  Serial.begin(9600);
  tick = millis();
}



void loop() {
  
   set_color(2,5,55);
  
  if(millis() > tick + 1000) {
    tickClock();
    tick = millis();
  }

}