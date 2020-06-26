# `Réveil olfactif` : Un réveil en douceur

## Equipe 
- Valentin Poirier
- Olivier Quéret 
- Manitra Ranaivoharison
- Yasmine Touzene

## Présentation :clipboard:

Le réveil olfactif est un projet iot d'école qui permet de se réveiller d'une nouvelle façon.



## fonctionnalités
- Réveil :
    -   réveil à une heure précise avec sélection de la senteur
    -   réveil avec minuteur avec sélection de l'odeur
- Partage du réveil :
    -   une personne ayant l'autorisation d'accès peut déclencher la diffusion de senteur
- Lumière & senteur :
	-	Il est possible d'allumer un lumière en même temps que la diffusion de senteur



## Rendu 3D

- Lien : https://www.tinkercad.com/things/hs0zLIIOjoh
- Rendu : 

![alt text](https://github.com/ValentinPoirier/IOT-project/blob/master/images/5.png?raw=true "3D modeling")

## TinkerCad
- Lien : https://www.tinkercad.com/things/7A4iS2HO7pj
- Rendu : 

![alt text](https://github.com/ValentinPoirier/IOT-project/blob/master/images/tinkercad.png?raw=true "TinkerCad")



       
## Pièces

Arduino UNO :pager:
- image :

![alt text](https://res.cloudinary.com/rsc/image/upload/b_rgb:FFFFFF,c_pad,dpr_2.0,f_auto,h_393,q_auto,w_700/c_pad,h_393,w_700/F7697409-02?pgw=1 "Arduino UNO")

Neopixel Jewel
- image :

![alt text](https://cdn-reichelt.de/bilder/web/xxl_ws/A300/ADAFRUIT-2226-30091174-01.png "Neopixel Jewel")

Module Wifi (ESP8266)

- image :

![alt text](https://static.generation-robots.com/4533-large_default/module-serie-wifi-esp8266.jpg "Module Wifi")


Servo moteur
- image : 

![alt text](https://ae01.alicdn.com/kf/HTB1Lkrhkx3IL1JjSZPfq6ArUVXad.jpg?size=110180&height=1000&width=1000&hash=b811dc6388c4f0b26431e36b3537a5f0 "Servo moteur")

Moteur CC
- image :  

![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQzSC3Lehd2PHZblMsG20nJkxenlI69yfgBKQ&usqp=CAU "Moteur CC")

Ecran LCD 16*2
- image : 

![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcSJsOXqVwoVUcjuzYi-IjgjnrwHq1CEwMinfA&usqp=CAU "Ecran LCD")

Neopixel bande
- image : 

![alt text](https://asset.conrad.com/media10/isa/160267/c1/-/fr/1516566_BB_00_FB/image.jpg?x=400&y=400 "Neopixel à bande")

## Fonctionnement

Pour utiliser votre réveil, vous devez télécharger l'application mobile qui vous permettra de configurer votre réveil

Alarme :  
![alt text](? "alarme")  

? :  
![alt text](? "?")  

? :  
![alt text](? "?")  

? :  
![alt text](? "?")  

? :  
![alt text](? "?")


## Commandes

La communication entre le réveil olfactif et l'application se fera via Wifi. Pour simuler la réception de messages dans Tinkercard, nous utilisons le moniteur série avec les différentes commandes.

Les commandes permettant la diffusion de senteurs prédéfinies :
## s_boisee 
## s_mentolee
## s_turtle

Exemple avec la senteur boisee s_boisse, les trois premières fioles s'ouvrent à 50%, la dernière ne s'ouvre pas.
![alt text](https://github.com/ValentinPoirier/IOT-project/blob/master/images/senteur_boisee.PNG?raw=true "TinkerCad")

Les commandes permettant la diffusion de senteurs personnalisées :
L'utilisateur peut indiquer pour chaque fiole si il souhaite l'ouvrir à 0%, 25%, 50%, 75% ou 100%. L'application enverra donc des messages commençant par "sp" suivi de 4 chiffres représentant respectivement les 4 fioles. (0 -> 0%, 1 -> 25%, 2 -> 50%, 3 -> 75%, 4 -> 100%)
Exemples :
## sp0123
## sp0505
## sp1234
## ...
L'utilisateur peut programmer son reveil en tapant dans le moniteur série:
Exemple : 
## 10:52
## 07:30
