#include "WiFi.h"

const char* ssid = "Enter Your Wifi Name";
const char* password = "Enter Your WiFi Password";

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  delay(100);
  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");

  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Not Connected to any internet");
  } else {
    Serial.print("Connected to ");
    Serial.println(ssid);
      // String macc_address= WiFi.Mac();
    String macc_address= WiFi.macAddress();
    Serial.println("Wifi Mac Address: ");
    Serial.print(macc_address);
        delay(2000);
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(3000);
}
