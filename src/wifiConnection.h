#pragma once

#include <ESP8266WiFi.h>
#include "mywifi.h"

void connectWiFi()
{
    WiFi.mode(WIFI_OFF);
    delay(5000);
    WiFi.mode(WIFI_STA);
    Serial.println();
    delay(2000);

    if (WiFi.SSID() != ssid) WiFi.begin(ssid, password);
    else Serial.println("WiFi config loaded");

    Serial.printf("Connecting to %s", ssid);

    while ( WiFi.status() != WL_CONNECTED ) 
    {        
        static int secs = 0;
        ++secs;
        delay(1000);
        Serial.print('.');
        if (secs == 60) 
        {
            Serial.print("reload");
            WiFi.begin(ssid, password);
        }
    }
    Serial.println("done");
    Serial.println(WiFi.localIP());
}
