#include "communication/WifiConnection.h"
#include <M5Unified.h>

WifiConnection::WifiConnection(const char* networkSsid, const char* networkPassword){
    ssid = networkSsid;
    password = networkPassword;
}

void WifiConnection::connect() {
    Serial.print("Connecting to Wi-Fi: ");
    Serial.println(ssid);
    
    //Writing on M5stack v2.7 screen that the wifi is connecting
    M5.Display.clear();
    M5.Display.setColor(TFT_WHITE);
    M5.Display.setFont(&fonts::Font4);
    M5.Display.setCursor(16, 16);
    M5.Display.println("Connecting to Wi-Fi...");


    WiFi.begin(ssid, password);

    // WL_CONNECTED is a constant from the WiFi library.
    // We stay in this loop while the status is NOT connected.
    while (WiFi.status() != WL_CONNECTED) {
        delay(500); // 500ms delay is mandatory to prevent Watchdog crashes
        Serial.print(".");
    }

    // When the loop finishes, it means we are connected!
    Serial.println("");
    Serial.println("Wi-Fi connected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // Prints the IP given by your router

    //Writing on M5stack v2.7 screen that the wifi is connected and IP adress
    M5.Display.clear();
    M5.Display.setColor(TFT_WHITE);
    M5.Display.setFont(&fonts::Font4);
    M5.Display.setCursor(16, 16);
    M5.Display.println("Connected to Wi-Fi.");
    M5.Display.setCursor(16, 40);
    M5.Display.print("IP: ");
    M5.Display.println(WiFi.localIP());
}

void WifiConnection::checkStatus() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Warning: Wi-Fi connection lost!");
    }
}