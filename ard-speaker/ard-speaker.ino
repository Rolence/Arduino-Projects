#include <TTS.h>

// Media pins
#define ledPin 13       // digital pin 13 
#define PWM 10                         

// Variables
char text [50];
boolean state=0;

TTS text2speech(PWM);  // speech output is digital pin 10

void setup() { 
  //media
  pinMode(ledPin, OUTPUT); 
}

//================================================================
// Main Loop
//================================================================
void loop(){
    state = !state;
    digitalWrite(ledPin, state);
    Test_Speech();
    delay(1000);          // delay a second
}  
//================================================================


void Test_Speech() {
 text2speech.setPitch(6); //higher values = lower voice pitch
 strcpy(text, "Hello  master! How are you doin?");
 text2speech.sayText(text);
 delay(500);
 text2speech.setPitch(1); //lower values = higher voice pitch
 strcpy(text, "I am fine, thankyou.");
 text2speech.sayText(text);
}
