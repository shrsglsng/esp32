/* Note:
- everytime esp restarts/reconnects, it is assigned a new IP by the DHCP (Dynamic Host Configuration Protocol). For a in-home network the router acts as DHCP

- other parameters by DHCP for network config: 
    - Subnet Mask: an 32 bit mask when applied on the IP address distinguishes network portion : host portion
    - Gateway ID : is the IP address of the router (layer-3: forward traffic destined for other neworks)
    - DNS IP: (Domain Name System)  tells the client where to fwd 'domain name queries' i.e human friendly names --(to)--> IP address translation
    
*/

#include "WiFi.h"
#include "ESP32Ping.h"

const char *ssid = "AibotInk workshop";
const char *password = "Aibotink@123";

IPAddress staticIP(192, 168, 31, 007);
IPAddress gatewayIP(192, 168, 31, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns0(192, 168, 31, 1);
IPAddress dns1(0, 0, 0, 0);


void WiFiInit(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi..");
    while(WiFi.status() != WL_CONNECTED){
        Serial.print("..");
        delay(500);
    }
    Serial.println("\n Connection successful");

    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("Subnet Mask: ");
    Serial.println(WiFi.subnetMask());
    Serial.print("Gateway IP: ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("DNS 1: ");
    Serial.println(WiFi.dnsIP(0));
    Serial.print("DNS 2: ");
    Serial.println(WiFi.dnsIP(1));
}

void setup(){
    Serial.begin(115200);
    WiFiInit();
    delay(500);

    int wifi_reconfig_status = WiFi.config(staticIP, gatewayIP, subnet, dns0, dns1);
    if(wifi_reconfig_status){
        Serial.print("New Static IP: ");
        Serial.println(WiFi.localIP());
    }
    else{
        Serial.println("WiFi reconfiguration failed");
    }
}
void loop(){

}

