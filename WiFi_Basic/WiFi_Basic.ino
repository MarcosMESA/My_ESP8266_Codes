#include <ESP8266WiFi.h>

//parameters

const char* ssid = "wifi name";  //2.4 only
const char* password = "wifi password";
//const char* host = "000.000.0.000"; //host to locate a client or DB

void setup(){
  
  Serial.begin(115200); //serial starts

  WiFi.begin(ssid, password); //WiFi starts with parameters to connect

  Serial.println("Trying to connect:");

  //while try to connect
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
  Serial.println(WiFi.localIP()); //board ip
  
}

void loop(){

  //nothing here :D
  
}
