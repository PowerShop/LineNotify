#ifndef LINENOTIFY_H
#define LINENOTIFY_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class LineNotify {
public:
    LineNotify(const char* token);
    void send(const char* message);
    String textEncode(const char *str);

private:
    const char* _token;
};

#endif // LINENOTIFY_H