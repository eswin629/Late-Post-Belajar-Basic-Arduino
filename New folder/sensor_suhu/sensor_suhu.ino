#include <DHT.h>
DHT dht(2,DHT11);

void setup(){
  Serial.begin(9600);
  dht.begin();
  }

  void loop(){
   // float kelembaman = dht.readHumidity();
    float suhu = dht.readTemperature();

    //Serial.print(" kelembapan: ");
    //Serial.print(kelembaman);
    //delay(200);
    //Serial.print("\n");
    Serial.print("Suhu: ");
    Serial.print(suhu);
    delay(200);
    Serial.print("\n");
    }
