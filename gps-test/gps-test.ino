#include <TinyGPS++.h>

//#include <TinyGPS.h>

#include <SoftwareSerial.h>

 
static const int RXPin = 2, TXPin = 3; //13=D7 AND 14=D5
static const uint32_t GPSBaud = 9600;
//static const uint32_t GPSBaud = 9600;

 
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
 
void setup()
{
  Serial.begin(115200);
  //Serial.begin(4800);
  ss.begin(GPSBaud);
}
 
void loop()
{
  // Output raw GPS data to the serial monitor
  while (ss.available() > 1){
    Serial.write(ss.read());
  }
}
