#include <WiFi.h>

const char *ssid = "AibotInk workshop";
const char *password = "Aibotink@123";

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t event_info)
{
    Serial.println("Connected to AccessPoint successfull!");
}

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t event_info)
{
    Serial.print("WiFi connected!! ");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t event_info)
{
    Serial.print("WiFi lost connection. Reason: ");
    Serial.println(event_info.wifi_sta_disconnected.reason);
    Serial.println("Trying to reconnect...");
    WiFi.begin(ssid, password);
}

void setup()
{
    Serial.begin(115200);
    WiFi.disconnect(true);
    delay(1000);
    WiFi.onEvent(WiFiStationConnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);
    WiFi.onEvent(WiFiGotIP, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_GOT_IP);
    WiFi.onEvent(WiFiStationDisconnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);

    WiFi.begin(ssid, password);

}

void loop(){
    Serial.println("executing inside loop()..");
    delay(3000);
}
