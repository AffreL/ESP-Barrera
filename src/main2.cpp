#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include "functions.hpp"

const char* ssid = "Fibertel WiFi225 2.4"; //SAGVB Ingreso
const char* password = "0142097625";    //SAGIngreso2021

const int puerto = 8088;


uint8_t tiempo = 'T'; 
uint8_t abrir = 'A'; 
uint8_t cerrar = 'C'; 

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

    pinMode(16, OUTPUT);
    pinMode(25, INPUT);
    int aux=0,salida=0,numero=0;
    WiFiClient client = server.available();
    uint8_t data[30];
    if(client){
        Serial.println("Cliente");
        while (client.connected())
        {
            client.read(data, 30);
            Serial.print("Cliente mando: ");
            Serial.println((char *) data);
            
            if(data[1] == tiempo)
            {
                digitalWrite(16,HIGH);
                delay(500);
                salida = 0;
                aux = 0;
                numero = 0;
                while (salida==0 && numero<500)
                {
                    delay(50);
                    numero++;
                    if (digitalRead(25) == 1)
                    {
                        aux = 1;
                    }
                    if (digitalRead(25) == 0 && aux == 1)
                    {
                        aux = 0;
                        salida=1;
                    }
                }
                digitalWrite(16,LOW);
            }
            else if (data[1] == abrir)
            {
                digitalWrite(16,HIGH);
                delay(500);
            }
            else if (data[1] == cerrar)
            {
                digitalWrite(16,LOW);
                delay(500);
            }
        }
        
    }

}
