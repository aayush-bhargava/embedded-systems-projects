/*
  ==========================================
  PROJECT: ESP8266 Switch Module + ThingSpeak
  BOARD : NodeMCU ESP8266 (ESP-12E Module)

  ESP8266 Board Package URL:
  https://arduino.esp8266.com/stable/package_esp8266com_index.json

  ThingSpeak Channel Details:
  Channel ID : 3411453
  Write API Key : UF0D4UMS7OXMDEMG
  Read API Key  : EALKL0GGDN87S2FD

  Wiring:
  ------------------------------------------
  Switch Module VCC -> 3.3V
  Switch Module GND -> GND
  Switch Module OUT -> D5

  Function:
  ------------------------------------------
  Reads switch state and uploads it to
  ThingSpeak Field 1 every 20 seconds.
  ==========================================
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// WiFi Credentials
const char* ssid = "Arytan 2.4G";
const char* password = "sky12345678";

// ThingSpeak Write API Key
String apiKey = "UF0D4UMS7OXMDEMG";

// Switch connected to D5
#define SWITCH_PIN D5

void setup() {

  // Start Serial Monitor
  Serial.begin(115200);

  // Configure switch pin as input
  pinMode(SWITCH_PIN, INPUT);

  Serial.println();
  Serial.println("ESP8266 Switch Monitoring Started");

  // Connect to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  // Read switch state
  int switchState = digitalRead(SWITCH_PIN);

  Serial.print("Switch State: ");
  Serial.println(switchState);

  // Check WiFi connection
  if (WiFi.status() == WL_CONNECTED) {

    WiFiClient client;
    HTTPClient http;

    // Create ThingSpeak URL
    String url =
      "http://api.thingspeak.com/update?api_key=" +
      apiKey +
      "&field1=" +
      String(switchState);

    Serial.println("Sending Data to ThingSpeak...");
    Serial.println(url);

    // Start HTTP request
    http.begin(client, url);

    // Send GET request
    int httpCode = http.GET();

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    // Close connection
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected!");
  }

  // ThingSpeak Free Account:
  // Minimum update interval = 15 seconds
  delay(20000);
}