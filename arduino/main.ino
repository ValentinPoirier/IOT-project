#include <LiquidCrystal.h> //bibliothèque d'écrans
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define PIN 7
#define NUMPIXELS 7 // numero de leds
#define LCD_Backlight 6
#define MOTOR 1
#define NUMPIXELSBANDE 4

int S_BOISEE[] = {50,50,50,0};
int S_MENTOLEE[] = {80, 0, 0, 80};
int S_TURTLE[] = {110, 110, 110, 110};
int pct_senteurs[] = {0, 25, 50, 75, 100};

//Cercle 7 LED
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS + 4, PIN, NEO_GRB + NEO_KHZ800);
//Servo moteurs
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servos[4] = {servo0, servo1, servo2, servo3};

                   
// Variables et fonctions horloge                   
long tick;
int second; 
int minute = 51;
int hour = 15;
int day = 25;
int month = 6;
int year = 2020;

// Variable de reglage d'heure de reveil
int o_hours = 0;
int o_min = 0; 

// Met a jour les couleurs
void set_color(int redColor, int greenColor, int blueColor){
  for(int i = 0; i<7; i++){
    pixels.setPixelColor(i,pixels.Color(redColor, greenColor, blueColor));    
  }
  pixels.show();
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

// Fonction de parsing de l'heure de reveil
int getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length();

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return (found > index ? data.substring(strIndex[0], strIndex[1]) : "").toInt();
}  // Fin

//Fonctions Bande 4 LED (fiole vide ou pleine)
void allumage_led(int num, int full){
  if (full) {
    pixels.setPixelColor(num, 50, 205, 50);
  } else {
    pixels.setPixelColor(num, 255, 0, 0);
  }
  pixels.show();
}

void change_LED(String s) {
  char *full_or_empty = &s[2];
  int num = s[1] - 48 + 1;
  if (!strcmp(full_or_empty, "full") || !strcmp(full_or_empty, "empty")) {
  	allumage_led(num, !strcmp(full_or_empty, "full"));
  } else {
    Serial.println("Mauvaise commande");
  }
  Serial.print("La LED numero ");
  Serial.print(num - 1);
  Serial.print(" est dorenavant ");
  Serial.println(full_or_empty);
}

void init_led(void) {
  for (int k = NUMPIXELS; k < NUMPIXELS + 4; k++) {
  	allumage_led(k, 1);
  }
}
                 
                   
//Fonctions Diffuseur de senteurs
void servos_init(void) {
  for (int k = 0; k < 4; k++) {
  	servos[k].write(0);
  }
}

void reset_servos(int time_before_reset) {
  int start_time = millis();
  int current_time = millis();
  while (current_time - start_time < time_before_reset) {
  	current_time = millis();
  }
  servos_init();
}

void senteur(int values[]) {
  for (int k = 0; k < 4; k++){
    servos[k].write(values[k]);
    Serial.println(values[k]);
  }
  reset_servos(2000);
}

void senteur_personnalisee(String s) {
  int tab_senteurs[4];
  for (int k = 0; k < 4; k++) {
  	int index = s[2 + k] - 48;
    int value = pct_senteurs[index];
    tab_senteurs[k] = value;
  }
  senteur(tab_senteurs);
}

void diffuseur(String s) {
  if (s == "s_boisee") {
    senteur(S_BOISEE);
    Serial.println("Senteur Boisee !");
  } else if (s == "s_mentolee") { 
    senteur(S_MENTOLEE);
    Serial.println("Senteur Mentolee !");
  } else if (s == "s_turtle") { 
    senteur(S_TURTLE);
    Serial.println("Dead turtle... :x");
  } else if (s[1] == 'p') {
    senteur_personnalisee(s);
  } else {
    Serial.println("Mauvaise saisie");
  }
}

//setup & loop
                   
void setup() {
  pixels.begin();
  lcd.begin(16, 2); //16 caractères et 2 lignes
  pinMode(LCD_Backlight, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  analogWrite(LCD_Backlight, 256);
  digitalWrite(MOTOR, HIGH);
  Serial.begin(9600);
  tick = millis();
  
  set_color(2,5,55);
  
  //Bande 4 LED
  init_led();
  pixels.show();
  
  //Diffuseur
  servo0.attach(5);
  servo1.attach(4);
  servo2.attach(3);
  servo3.attach(2);
  servos_init();
}



void loop() {
  if(millis() > tick + 1000) {
    tickClock();
    tick = millis();
  }
  if (Serial.available() > 0) {
  	String s = Serial.readString();
    if (s[0] == 's') {
      diffuseur(s);
    } else if (s[0] == 'l') { 
      change_LED(s);
    } else {
      Serial.println("Reveil active");
      o_hours = getValue( s, ':', 0);
  	  o_min = getValue( s, ':', 1);
  	  Serial.println(o_hours);
  	  Serial.println(o_min);
    }
  }
  if(o_hours == hour && o_min == minute){
    String s = "s_boisee";
    diffuseur(s);
  }
}