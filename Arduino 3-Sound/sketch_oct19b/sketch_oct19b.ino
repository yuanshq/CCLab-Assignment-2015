#include "pitches.h"

const int speaker = 8;
const int buttonPin = 11;
int buttonState = 0;

const int photocellPin = 0;
int photocellReading= 0;

const int echopin=3; 
const int trigpin=2; 


int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int melody3[] = {
  NOTE_C3, NOTE_G4, NOTE_G2, NOTE_A2, NOTE_G3, 0, NOTE_C4, NOTE_B3
};

int melody2[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  };

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(echopin,INPUT); 
  pinMode(trigpin,OUTPUT);
}

void loop() {
  //-----------------Button Control-----------------------
  buttonState = digitalRead(buttonPin);
  
//  Serial.println(buttonState);
//  delay(100);

  if(buttonState == HIGH){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations1[thisNote];
      tone(8, melody1[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
   }
  //-----------------Button Control-----------------------

  //-----------------Distance Sensor Control--------------
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW); 
  float distance = pulseIn(echopin,HIGH);
  distance = distance/58.0;
  
  Serial.println(distance);
//  delay(100);
  
  if(distance<30){
    for (int thisNote = 0; thisNote < 16; thisNote++) {
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }
  delay(60);  
  //-----------------Distance Sensor Control--------------

  //------------------Light Sensor Control----------------
  photocellReading = analogRead(photocellPin);
  
//  Serial.println(photocellReading);  
//  delay(100);  

  if(photocellReading < 500){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations1[thisNote];
    tone(8, melody3[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
  }
  //------------------Light Sensor Control----------------
}
