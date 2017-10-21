//OneSheeldBlindStickNavigatorC/C++

#define CUSTOM_SETTINGS
#define INCLUDE_GPS_SHIELD
#define INCLUDE_SMS_SHIELD

/* Include 1Sheeld library.*/
#include <OneSheeld.h>
#include <string.h>


#define trigPinL 4
#define echoPinL 5
#define trigPinH 6
#define echoPinH 7
#define Vib1  12
#define Vib2  13
#define SW 8


/* Define a boolean flag. */
boolean isInRange = false;
float lat;
float lon;
String PhoneNumber = "0134087286";
String Message;
String Message1;
String Message2;
char latitude[10];
char longitude[10];


void setup() 
{
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinH, OUTPUT);
  pinMode(echoPinH, INPUT);
  pinMode(Vib1, OUTPUT);
  pinMode(Vib2, OUTPUT);
  pinMode(SW, INPUT);
  /* Start communication.*/
  OneSheeld.begin();
 // Serial.begin(9600);
}

void loop()
{
  
  long durationL, distanceL, durationH, distanceH, MixDist;
  digitalWrite(trigPinL, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinL, HIGH);
 
 
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPinL, LOW);

  durationL = pulseIn(echoPinL, HIGH);

  distanceL = (durationL/2) / 29.1;
  
  
  digitalWrite(trigPinH, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinH, HIGH);
 
 
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPinH, LOW);

  durationH = pulseIn(echoPinH, HIGH);

  distanceH = (durationH/2) / 29.1;

  // Serial.println(distanceL);
  // Serial.println(distanceH);
   
  // delay(1000);
  
  if (distanceL > 40){
    digitalWrite(Vib1,HIGH);
  }
  if (distanceL < 40){
    digitalWrite(Vib1,LOW);
  }
  if (distanceH < 100){
    digitalWrite(Vib1,HIGH);
    delay(200);
    digitalWrite(Vib1,LOW);
    delay(200);
  }

   /* Always check if the smartphone's GPS and a given longitude and latitude are in a range of 100 meters. */
  //if(GPS.isInRange(30.0831008,31.3242943,100))
 // {
  //  if(!isInRange)
  //  {
      /* Send SMS. */
      lat = GPS.getLatitude();
      lon = GPS.getLongitude();
      Message1 = String(lat,8);
      Message2 = String(lon,8);
      
      if (digitalRead(SW) == 0){
     
      Message = "I need Help! I'm at latitude: " + Message1 + " and longitude: " + Message2;
      Message = "Google Maps - https://www.google.co.in/maps/place/" + Message1 + "," + Message2;
      SMS.send(PhoneNumber,Message);
      
      
      delay(3000);
      }
 //     isInRange = true;
 //   }
    
 // }
 // else 
 // {
 //   if(isInRange)
 //   {
      /* Send SMS. */ 
 //     SMS.send("+601123413946","Smartphone is not In Range.");
 //     isInRange = false;
 //   }
    
 // }
  
  delay(1000);
}

