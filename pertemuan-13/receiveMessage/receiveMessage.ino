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

unsigned long lastTimeBotRan;
const unsigned long botRequestDelay = 500;

void handleNewMessages(int numNewMessages) {
  Serial.println("Pesan baru diterima");

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = bot.messages[i].chat_id;
    String text    = bot.messages[i].text;
    String from    = bot.messages[i].from_name;

    if (from == "") from = "User";

    Serial.println("------------");
    Serial.print("Dari   : ");
    Serial.println(from);
    Serial.print("Chat ID: ");
    Serial.println(chat_id);
    Serial.print("Pesan  : ");
    Serial.println(text);

    if (text == "/start") {
      bot.sendMessage(chat_id, "ESP8266 siap menerima perintah 🚀", "");
    }

    if (text == "ping") {
      bot.sendMessage(chat_id, "pong", "");
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("ESP8266 Telegram Receiver");

  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi terhubung!");
  Serial.println(WiFi.localIP());

  client.setInsecure();
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    if (numNewMessages) {
      handleNewMessages(numNewMessages);
    }

    lastTimeBotRan = millis();
  }
}
