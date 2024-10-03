# LineNotify 📲
A simple and efficient library for ESP32 to send real-time notifications to the LINE application via the LINE Notify API.

## 🔥 Features

- Seamlessly send messages from ESP32 to LINE.
- Uses the official LINE Notify API.
- Great for IoT notifications, alerts, and system monitoring.

## 📥 Installation

1. **Clone or Download** this repository.
2. **Add to Arduino Libraries**: Copy the `LineNotify` folder into your Arduino libraries directory (default location: `~/Documents/Arduino/libraries`).
3. **Register with LINE Notify**: Get your token from [LINE Notify](https://notify-bot.line.me/th/).

## 🛠️ Usage

### 1. Include the Library

Start by including the `LineNotify` library in your sketch:

```cpp
#include <LineNotify.h>

// Replace with your WiFi credentials and LINE Notify token
const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char *LINE_TOKEN = "YOUR_LINE_TOKEN";

// Create an instance of LineNotify
LineNotify lineNotify(LINE_TOKEN);

void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Wait until WiFi is connected
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Send a notification to LINE when ESP32 is connected
    lineNotify.send("ESP32 is now connected to WiFi!");
}

void loop() {
    // Send a periodic notification
    lineNotify.send("Hello from ESP32");
    delay(10000); // Wait for 10 seconds before sending again
}
```
### 2. Sending Messages

After connecting to WiFi, the `LineNotify` library allows you to send messages directly to your LINE app by calling the `.send()` function.

---
## 📞 Contact

If you have any questions or need further assistance, feel free to reach out!

- **Facebook**: [Min Sakmueng](https://www.facebook.com/Min.Sakmueng)
- **Email**: [aaaxcvg@gmail.com](mailto:aaaxcvg@gmail.com)
