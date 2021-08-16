#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include "functions.hpp"

const char* ssid = "asda";
const char* password = "adsas";

const int puerto = 8088;

enum Data { T, A, C};

WiFiServer server(puerto);

void setup(){

    Serial.begin(115200);
    Serial.print("Conectandose a ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Wifi conectado con la siguiente Dirección IP: ");
    Serial.println(WiFi.localIP());

    server.begin();

    configPines();
    
}

void loop(){

    WiFiClient client = server.available();
    uint8_t data[30];
    if(client){
        Serial.println("Cliente");
        while (client.connected())
        {
            client.read(data, 30);
            Serial.print("Cliente mando: ");
            Serial.println((char *) data);
            
            Data ctr;
            switch (ctr)
            {
            case 'T':
                digitalWrite(11,HIGH);
                delay(500);
                digitalWrite(11,LOW);
                break;
            case 'A':
                digitalWrite(11,HIGH);
                delay(500);
                digitalWrite(11,LOW);
                break;
            case 'C':
                digitalWrite(11,HIGH);
                delay(500);
                digitalWrite(11,LOW);
                break;
            default:
                break;
            }
        }
        
    }

}
