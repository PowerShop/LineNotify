#include "LineNotify.h"

LineNotify::LineNotify(const char *token)
{
    _token = token;
}

String LineNotify::textEncode(const char *str)
{
    String encodedText = "";
    char c;
    while ((c = *str++))
    {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~' || c == '=')
        {
            encodedText += c;
        }
        else if (c == ' ')
        {
            encodedText += '+';
        }
        else
        {
            encodedText += '%';
            char hex[3];
            sprintf(hex, "%02X", c);
            encodedText += hex;
        }
    }
    return encodedText;
}

void LineNotify::send(const char *message)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin("https://notify-api.line.me/api/notify");

        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        http.addHeader("Authorization", String("Bearer ") + _token);

        String postData = "message=" + textEncode(message);

        int httpResponseCode = http.POST(postData);

        if (httpResponseCode > 0)
        {
            String response = http.getString();
            // debug
            Serial.println("Response: " + response + " / " + message);
        }
        else
        {
            Serial.print("Error on sending POST: ");
        }

        // Clear the resources
        http.end();
    }
    else
    {
        Serial.println("WiFi Disconnected");
    }
}