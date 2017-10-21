#include <TinyGPS++.h>

    #include <SoftwareSerial.h>
    #include <TinyGPS.h>
   // #include <TinyGPSPlus.h>
     
    long lat,lon; // create variable for latitude and longitude object

    SoftwareSerial gpsSerial(2, 3); // create gps sensor connection 
   // SoftwareSerial gpsSerial(14, 13); // create gps sensor connection
    TinyGPS gps; // create gps object
     
    void setup(){
      Serial.begin(9600); // connect serial
      gpsSerial.begin(4800); // connect gps sensor
      //gpsSerial.begin(115200); // connect gps sensor
    }
     
    void loop(){
      //Serial.println ("check before GPS Serial is connected ");
      while(gpsSerial.available()){ // check for gps data
        //Serial.println ("The GPS Serial is connected ");
       if(gps.encode(gpsSerial.read())){ // encode gps data
        Serial.println ("check if encode GPS Serial is connected ");
        gps.get_position(&lat,&lon); // get latitude and longitude
        // display position
        Serial.print("Position: ");
        Serial.print("lat: ");Serial.print(lat);Serial.print(" ");// print latitude
        Serial.print("lon: ");Serial.println(lon); // print longitude
       }
      }
    }
