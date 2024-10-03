#include <LineNotify.h>

// Replace with your WiFi credentials and Line Notify token
const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char *LINE_TOKEN = "YOUR_LINE_TOKEN";

// Create an instance of LineNotify
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

    // Send a message to Line Notify when ESP32 has connected to WiFi
    lineNotify.send("ESP32 has connected to WiFi");
}

void loop()
{
    lineNotify.send("Hello from ESP32");
    delay(10000); // Wait for 10 seconds
}