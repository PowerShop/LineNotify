#include <LineNotify.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char *LINE_TOKEN = "YOUR_LINE_TOKEN";

LineNotify lineNotify(LINE_TOKEN);

void setup()
{
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    lineNotify.send("ESP32 has connected to WiFi");
}

void loop()
{
    lineNotify.send("This is a message from ESP32");
    delay(10000); // Wait for 10 seconds
}

// Path: src/LineNotify.cpp
