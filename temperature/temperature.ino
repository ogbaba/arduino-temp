#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
int pinBouton = 5;

SimpleDHT11 dht11;
int etat = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pinBouton, INPUT);
}

void loop() {
  // start working...
  etat = digitalRead(pinBouton);
  if (etat == HIGH)
  {
    // read without samples.
    byte temperature = 0;
    byte humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
      return;
    }
   
    Serial.println("Temperature et humidité : ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" H");
    delay(1500);
  }
  // DHT11 sampling rate is 1HZ.
}
