/*
  ESP8266 WiFi Scanner

  Board: NodeMCU 1.0 (ESP-12E Module)

  Board URL:
  https://arduino.esp8266.com/stable/package_esp8266com_index.json
*/

#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("ESP8266 WiFi Scanner");
}

void loop() {

  Serial.println();
  Serial.println("Scanning WiFi Networks...");

  int numNetworks = WiFi.scanNetworks();

  if (numNetworks == 0) {
    Serial.println("No WiFi Networks Found");
  }
  else {
    Serial.print(numNetworks);
    Serial.println(" Networks Found");
    Serial.println("-------------------------------------");

    for (int i = 0; i < numNetworks; i++) {

      Serial.print("Network ");
      Serial.print(i + 1);
      Serial.println(":");

      Serial.print("SSID      : ");
      Serial.println(WiFi.SSID(i));

      Serial.print("RSSI      : ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm");

      Serial.print("Channel   : ");
      Serial.println(WiFi.channel(i));

      Serial.print("Encryption: ");

      if (WiFi.encryptionType(i) == ENC_TYPE_NONE)
        Serial.println("Open");
      else
        Serial.println("Secured");

      Serial.println("-------------------------------------");
    }
  }

  Serial.println("Rescanning in 10 seconds...");
  delay(10000);
}