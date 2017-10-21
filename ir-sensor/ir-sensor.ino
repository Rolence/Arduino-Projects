const int ProxSensor=2;

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(12, OUTPUT);     
  //Pin 2 is connected to the output of proximity sensor
  pinMode(ProxSensor,INPUT);
}

void loop() {
  if(digitalRead(ProxSensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(12, LOW);   // set the LED on
  }
  else
  {
    digitalWrite(12, HIGH);    // set the LED off
  }
  delay(100);              // wait for a second
}



