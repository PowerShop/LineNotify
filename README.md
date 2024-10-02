# LineNotify
Simple Library for EPS32 to send message to LINE Application
# LineNotify Library for ESP32

This library allows you to send notifications to LINE using the ESP32. It uses the LINE Notify API to send messages.

## Installation

1. **Download the Library**: Clone or download this repository.
2. **Add to Arduino Libraries**: Copy the `LineNotify` folder to your Arduino libraries directory (usually located at `~/Documents/Arduino/libraries`).

## Usage

### Include the Library

Include the `LineNotify` library in your sketch:

```cpp
#include "LineNotify.h"

const char* token = "your_LINE_token";
LineNotify lineNotify(token);

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    lineNotify.send("This is a message from ESP32");
    delay(10000); // Wait for 10 seconds
}
```
### Explanation:
- **Installation**: Instructions on how to install the library.
- **Usage**: Examples of how to include, initialize, and use the library.
- **Full Example**: A complete example sketch demonstrating the usage of the library.
- **License**: Information about the license.
