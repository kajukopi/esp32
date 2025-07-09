#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include <FS.h>
#include <SPIFFS.h>

const char* ssid = "ESP32-OTA";
const char* password = "12345678";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println("WiFi AP started. Connect to: " + WiFi.softAPIP().toString());

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS mount failed");
    return;
  }

  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

  server.on("/update", HTTP_POST, [](AsyncWebServerRequest *request) {
    bool shouldReboot = !Update.hasError();
    request->send(200, "text/plain", shouldReboot ? "Update success! Rebooting..." : "Update failed.");
    if (shouldReboot) {
      delay(1000);
      ESP.restart();
    }
  }, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data,
        size_t len, bool final) {
    if (!index) {
      Serial.printf("Update Start: %s\n", filename.c_str());
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
        Update.printError(Serial);
      }
    }
    if (!Update.hasError()) {
      if (Update.write(data, len) != len) {
        Update.printError(Serial);
      }
    }
    if (final) {
      if (Update.end(true)) {
        Serial.printf("Update Success: %u bytes\n", index + len);
      } else {
        Update.printError(Serial);
      }
    }
  });

  server.begin();
}

void loop() {
}
