#include <ESP8266WiFi.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire  display(0x3c, D1, D2);

//parameters

const char* ssid = "FAMILIA MORAIS-2G";  //2.4 only
const char* password = "N4v3g@nd0$";
//const char* host = "000.000.0.000"; //host to locate a client or DB

void setup(){
  
  Serial.begin(115200); //serial starts

  WiFi.begin(ssid, password); //WiFi starts with parameters to connect

  Serial.println("Trying to connect:");

  display.init(); //starts z fckn oled
  display.flipScreenVertically(); //i dont nd 2 tl ya

  //while try to connect
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP()); //board ip

  display.clear(); //same as z system cls 2 oleds
  display.setTextAlignment(TEXT_ALIGN_CENTER); //really?
  display.setFont(ArialMT_Plain_10); //COMIC SANS SUPREMACY, FCK Z OLED
  display.drawString(63, 10, WiFi.localIP().toString()); //freaking message to a fckn scout
  display.display();
}

void loop(){

  //nothing here :D
  
}
