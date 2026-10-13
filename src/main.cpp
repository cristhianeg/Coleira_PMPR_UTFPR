#include <M5Unified.h>
#include "communication/WifiConnection.h"

WifiConnection myWifi("Put_here_your_ssid","Put_here_your_password");

void setup() {
    M5.begin();
    myWifi.connect(); 
}

void loop() {
    M5.update();
}