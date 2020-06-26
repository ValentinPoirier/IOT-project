#include <LiquidCrystal.h> //bibliothèque d'écrans
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //épingles pour la bibliothèque

int second; // créer une variable pour stocker les secondes.
int minute = 51 ; // créer une variable pour stocker le nombre de minutes actuellement à l'horloge.
int hour = 15 ; // créer une variable pour stocker le du nombre d'heures que l'horloge affiche actuellement.
int day = 25 ; // créer une variable pour gèrer le jour où la veille est en cours.
int month = 6 ; // créer une variable pour stocker lesmois en cours sur l'horloge.
int year = 2020 ; // créer une variable pour l'année où la veille est en cours.

void setup() {//Fonction initial
  Serial.begin(9600); // démarrage du moniteur de port série
  lcd.begin(16, 2); // définir la position des caractères sur l'écran, c'est-à-dire 16 lignes et 2 pixels à partir du haut.
}

void loop() {//Boucle for
  for (second = 0 ; second < 60 ; second++) {//cycle en fraction de seconde
    lcd.setCursor(6, 0); lcd.print(":");//en séparant les heures, les minutes et les secondes à l'aide de... ":" 
    lcd.setCursor(9, 0); lcd.print(":");
    Serial.print(minute); Serial.print(":");//sur le moniteur du port, on écrit les minutes et les secondes.
    Serial.println(second);//
    if (hour <= 9) {
      lcd.setCursor(4, 0);//changement à l'écran 
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
      
    lcd.setCursor(5, 1); lcd.print("/");//en séparant le jour, le mois et l'année à l'aide "/"
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
   delay(1000); 
}
    minute = minute + 1; //si 60 secondes se sont écoulées, on ajoute 1 minute.
    if (minute == 60) {//Si 60 minutes se sont écoulées, nous ajoutons 1 heure et mettons les minutes à zéro.
        hour = hour + 1;
        minute = 0 ;
    }
    if (hour == 24) { //si 24 heures se sont écoulées, on ajoute 1 jour et on met l'heure à zéro.
        hour = 0;
        day = day + 1;
    }
    if (day == 31) { //Si 31 jours se sont écoulés, on ajoute 1 mois et on met le jour à zéro.
        month = month + 1;
        day = 0;
    }
    if (month == 12) {//si 12 mois se sont écoulés, on ajoute 1 an et on met le mois à zéro.
        year = year + 1;
        month = 0;
    }
}