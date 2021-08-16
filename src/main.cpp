// #include <Arduino.h>
// //Si usa Wifi
// #include <Wifi.h>
// //Si usa Ethernet 
// #include <SPI.h>
// #include <Ethernet.h>


// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>

// //MQTT
// #include <PubSubClient.h>

// #include "esp32-hal-cpu.h"
// #include <DNSServer.h>

// #include "header.hpp"
// #include "functions.hpp"
// #include "ESP32_MQTT.hpp"

// #include "SPIFFS.h"

// #include "ConfigRead.hpp"
// #include "ConfigReset.hpp"

// void setup() {
//   Serial.begin(115200);
//   setCpuFrequencyMhz(240);
//   log("\nInfo: Iniciando Setup");

//   if(MQTT){
//     client.setServer(mqttserver, 1883);
//     client.setCallback(callback);
//     log("\nInfo: Cliente MQTT Deshabilitado");
//   }else{
//     log("\nInfo: Cliente MQTT Deshabilitado");
//   }

//   //FIXME tema de pines esta en functions.hpp(definir que tipo son) y header.hhp(definir cuales son)
//   configPines();

//   //FIXME corroborar tema de configuracion
//   configRead();

// }


// void loop() {
//   // put your main code here, to run repeatedly:
// }