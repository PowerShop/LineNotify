#include "LineNotify.h"

LineNotify::LineNotify(const char* token) {
    _token = token;
}

void LineNotify::send(const char* message) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin("https://notify-api.line.me/api/notify");

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        http.addHeader("Authorization", String("Bearer ") + _token);

        String postData = "message=" + String(message);

        int httpResponseCode = http.POST(postData);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
        } else {
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }
}