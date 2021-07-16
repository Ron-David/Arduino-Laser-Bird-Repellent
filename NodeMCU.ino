
#include "UbidotsESPMQTT.h"

#define TOKEN "----" // Your Ubidots TOKEN
#define WIFINAME "----"  // Your SSID
#define WIFIPASS "----"  // Your Wifi Pass
#include <SoftwareSerial.h>

SoftwareSerial mySerial(D1, D2);
Ubidots client(TOKEN);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(9600);
  client.setDebug(true);  // Pass a true or false bool value to activate debug messages
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
}

void loop() {
  if (!client.connected()) {
    client.reconnect();
  }

  // Publish values to data source
  String msg = mySerial.readStringUntil('\r');

  client.add("Distance", msg.toInt());  // Insert your variable Labels and the value to be sent
  if (!(msg == "")) {
    client.add("Birds", 1);  // Insert your variable Labels and the value to be sent
  }
  
  client.ubidotsPublish("source1");
  client.loop();
  delay(5000);
}
