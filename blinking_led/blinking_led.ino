
const int ledPin = 13;           // LED is connected to digital pin 13
//const int ledPin = 13 port 14 of arduino =D5 AND PORT 13 = D 12
const int ledPin1 = 14; 

void setup() {
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin, OUTPUT);         // sets digital pin as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledPin, HIGH);     // sets the LED on
  delay(1000);              // waits for a second
  digitalWrite(ledPin, LOW);     // sets the LED off
  delay(1000);              // waits for one second
  digitalWrite(ledPin1, HIGH);     // sets the LED on
  delay(1000);              // waits for a second
  digitalWrite(ledPin1, LOW);     // sets the LED off
  delay(1000);              // waits for one second
}
