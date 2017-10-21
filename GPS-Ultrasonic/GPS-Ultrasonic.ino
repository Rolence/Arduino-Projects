#include <TinyGPS.h>
#include <TTS.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 2, TXPin = 3;
static const uint32_t GPSBaud = 9600;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer =7;
long duration;
int distance;
#define PWM 6

//TTS Object
TTS text2speech(PWM);
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(buzzer, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}

void loop()
{
  Serial.flush();
  GPSMethod();
  delay(2000);
  UltrasonicMethod();
  delay(2000);
  Serial.flush();
}

void GPSMethod()
{
   // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    //float latitude = gps.location.lat(), 6;
    //float longitude = gps.location.lng(), 6;

    if (gps.location.lat(), 6 == 4.22222 && gps.location.lng(), 6 == 9.43214)
    {
      text2speech.setPitch(1);
      text2speech.sayText ("Checkpoint");
    }
    else if (gps.location.lat(), 6 == 4.42222 && gps.location.lng(), 6 == 9.42214)
    {
      text2speech.setPitch(1);
      text2speech.sayText ("Checkpoint");
    }
  }
  else
  {
    Serial.print(F("INVALID"));
  }
  
Serial.print(F("  Altitude: ")); 
  if (gps.altitude.isValid())
  {
    Serial.print(gps.altitude.feet(), 6);
    Serial.print(F(","));
    
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
    
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
void UltrasonicMethod()
{
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
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
if (distance < 1800) // Checking the distance, you can change the value
{ 
  //Serial.print(distance);
//digitalWrite(motor,HIGH); // When the the distance below 100cm
digitalWrite(buzzer,HIGH);
} else
{
//digitalWrite(motor,LOW);// when greater than 100cm
digitalWrite(buzzer,LOW); 
} delay(500);
Serial.print("Distance in centimeters: ");
Serial.println(distance);
}

