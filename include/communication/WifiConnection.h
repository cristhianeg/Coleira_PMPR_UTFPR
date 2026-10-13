#ifndef WIFI_CONNECTION_H //Does this variable exists? If no, define it
#define WIFI_CONNECTION_H

#include <WiFi.h> //Library of Arduino

/**
 * @class WifiConnection
 * @brief Manages the ESP32 Wi-Fi connection.
 * 
 * This class encapsulates the standard ESP32 WiFi library, 
 * providing a simplified interface to connect to a local network
 * and monitor the connection status.
 */

class WifiConnection{
    private:
        const char* ssid; // Network name (Service Set Identifier)
        const char* password; // Network password (WPA/WPA2)
    public:
    /**
     * @brief Constructor for the WifiConnection class.
     * 
     * Initializes the object with the network credentials, but does 
     * not start the connection process immediately.
     * 
     * @param networkSsid The name of the Wi-Fi network.
     * @param networkPassword The password for the Wi-Fi network.
     */
    WifiConnection(const char* networkSsid, const char* networkPassword);
    
    /**
     * @brief Initiates the connection to the Wi-Fi network.
     * 
     * This method will block the execution in a loop until the ESP32 
     * successfully connects to the router. It prints dots to the serial monitor.
     */
    void connect();

    /**
     * @brief Checks if the ESP32 is still connected to the network.
     * 
     * Can be called periodically in the main loop to attempt reconnection
     * if the signal is lost.
     */
    void checkStatus();
};

#endif