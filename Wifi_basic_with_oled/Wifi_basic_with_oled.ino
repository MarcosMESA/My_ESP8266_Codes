#include <ESP8266WiFi.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire  display(0x3c, D1, D2);

//parameters

const char* ssid = "ssid";  //2.4 only
const char* password = "wifi_password";
//const char* host = "000.000.0.000"; //host to locate a client or DB

void setup(){
  
  Serial.begin(115200); //serial starts

  WiFi.begin(ssid, password); //WiFi starts with parameters to connect

  Serial.println("Trying to connect:");

  display.init(); //oled starts
  display.flipScreenVertically(); //flips screen vertically

  //while try to connect
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP()); //board ip

  display.clear(); //clear screen
  display.setTextAlignment(TEXT_ALIGN_CENTER); //center align
  display.setFont(ArialMT_Plain_10); //set font
  display.drawString(63, 10, WiFi.localIP().toString()); //transform ip in string and show on screen
  display.display();
  
}

void loop(){

  //nothing here :D
  
}
