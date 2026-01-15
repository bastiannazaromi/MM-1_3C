#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "LAB Hardware 2";
const char* password = "harkatnegeri";

#define BOT_TOKEN "7731595619:AAFCCUokLsPsrdR-7jhS2_cQWYFSLmHOrWc"
#define CHAT_ID   "1028996259"

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

String serialMessage = "";

void setup() {
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  client.setInsecure();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (serialMessage.length() > 0) {
        Serial.print("Mengirim ke Telegram: ");
        Serial.println(serialMessage);

        bot.sendMessage(CHAT_ID, serialMessage, "");

        serialMessage = "";
      }
    } 
    else {
      serialMessage += c;
    }
  }

  
}
