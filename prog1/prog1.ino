#include <Streaming.h>
#include <PString.h>

char buffer[28];
PString pstr(buffer, sizeof(buffer));

void setup() {
  Serial.begin(9600);
  pstr.begin();     // Empty the buffer
}

void loop() {
  int first=50, second=100;
  pstr.begin();     // Empty the buffer
  pstr << 'X' << first << 'Y' << second << 'T';
  pstr += " hihi ";
  pstr << millis() << endl;
  Serial << pstr;
  delay(1000);
}
