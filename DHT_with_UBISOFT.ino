#include <UbidotsMicroESP8266.h>
#include "DHT.h"
#define DHTPIN 2
#define TOKEN "BBFF-WGJJSP7t7LRLJIKUqDKewroS2leiWO"
#define ssid "astagirulloh waatubu ilaih"
#define psswd "123123123"
DHT dht(DHTPIN, DHT11);
Ubidots client(TOKEN);
unsigned long last =1;

void setup(){
  Serial.begin(9600);
  
  dht.begin();
  
  client.wifiConnection(ssid,psswd);

}

void loop(){
  if (millis()-last>1000){
    float hum = dht.readHumidity();

    float temp = dht.readTemperature();

    last=millis();

    client.add("kelembapan" ,hum);

    client.add("Temp",temp);

    client.sendAll(true);
  }
}
