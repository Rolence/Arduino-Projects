/*
* Ultrasonic Sensor HC-SR04 interfacing with Arduino.
*/
// defining the pins
const int trigPin = 9;
const int echoPin = 10;
const int buzzer =7;
// defining variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(buzzer, OUTPUT);
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.343/2;
// Prints the distance on the Serial Monitor
if (distance < 1578) // Checking the distance, you can change the value
{ 
  Serial.println(distance);
//digitalWrite(motor,HIGH); // When the the distance below 100cm
digitalWrite(buzzer,HIGH);
} else
{
//digitalWrite(motor,LOW);// when greater than 100cm
digitalWrite(buzzer,LOW); 
} delay(500);
//Serial.print("Distance in centimeters: ");
//Serial.println(distance);
}
