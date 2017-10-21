#include <SoftwareSerial.h>

#define trigPin 9
#define echoPin 10
#define motor 7
#define buzzer 6

void setup()
{
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop()
{ long duration, distance;
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
Serial.print ("duration ");
Serial.print (duration/2);
distance = (duration/2) / 29.1;
Serial.print ("  distance ");
Serial.print (distance);
Serial.println();

if (distance < 70) // Checking the distance, you can change the value
{ 
  Serial.print(distance);
digitalWrite(motor,HIGH); // When the the distance below 100cm
digitalWrite(buzzer,HIGH);
} else
{
digitalWrite(motor,LOW);// when greater than 100cm
digitalWrite(buzzer,LOW); 
} delay(500);
}
