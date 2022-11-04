#include "pitches.h"

byte sensorpir = 7;
byte led = 13;

void setup()
{
    pinMode(sensorpir, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    if (digitalRead(sensorpir) == HIGH)
    {
        Serial.println("Detectado movimiento por el sensor pir");
        tone(8, NOTE_B4);
        delay(500);
        tone(8, NOTE_FS4);
        delay(250);
        tone(8, NOTE_B4);
        delay(250);
        tone(8, NOTE_CS5);
        delay(250);
        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_E5);
        delay(250);
        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_CS5);
        delay(250);

        tone(8, NOTE_B4);
        delay(250);
        tone(8, NOTE_A4);
        delay(250);
        tone(8, NOTE_G4);
        delay(375);
        tone(8, NOTE_D5);
        delay(375);
        tone(8, NOTE_D5);
        delay(500);

        noTone(8);
        delay(725);

        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_A4);
        delay(250);
        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_A4);
        delay(250);
        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_A4);
        delay(250);

        tone(8, NOTE_D5);
        delay(250);
        tone(8, NOTE_E5);
        delay(125);
        tone(8, NOTE_CS5);
        delay(725);

        noTone(8);
        delay(725);
    }
}
