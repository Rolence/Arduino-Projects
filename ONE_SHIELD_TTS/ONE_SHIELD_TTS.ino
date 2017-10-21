#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

float sensorValue = 0;
char charValue[4];

void setup() {
    /* Start communication. */
  OneSheeld.begin();
}

void loop() {
    sensorValue = (analogRead(A0) * 5.00 * 100.0 ) / 1024.0;
    dtostrf(sensorValue,4,1,charValue);
    TextToSpeech.say("Temprature equals");
    delay(1400);
    TextToSpeech.say(charValue);
    delay(1300);
    TextToSpeech.say("Celsius");
    delay(3000);
    }

