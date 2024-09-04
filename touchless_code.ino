#include "DHTesp.h"  // Include the DHTesp library

DHTesp dht;
int buz = 11;

void setup() {
  Serial.begin(9600);
  Serial.println("Status:");
  dht.setup(2, DHTesp::DHT11);  // Initialize DHT11 sensor at pin 2
  pinMode(buz, OUTPUT);
}

void loop() {
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  
  Serial.print("Status: ");
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  
  Serial.print("Humidity (%): ");
  Serial.print(humidity, 1);
  Serial.print("\t");
  
  Serial.print("Temperature (C): ");
  Serial.print(temperature, 1);
  Serial.println();
  
  delay(1000);
  
  if (temperature >= 30) {
    Serial.println("Temperature is high in the body");
    for (int i = 0; i < 8; i++) {
      digitalWrite(buz, HIGH);
      delay(50);
      digitalWrite(buz, LOW);
      delay(50);
    }
  } else {
    Serial.println("Temperature is normal in the body");
    digitalWrite(buz, LOW);
    delay(1000);
  }
}
