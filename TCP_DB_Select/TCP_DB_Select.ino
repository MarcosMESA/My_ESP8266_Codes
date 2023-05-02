#include <ESP8266WiFi.h>

const char* ssid = "********";
const char* password = "*******";
const char* host = "*.*.*.*";

IPAddress ip(*,*,*,*);
IPAddress gateway(*,*,*,*);
IPAddress subnet(*,*,*,*);

const int int_LED = 16;
String line;
String proto;

void setup() {
  Serial.begin(115200);
  pinMode(int_LED, OUTPUT);
  delay(10);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" - WiFi Connected -");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  proto="*";

  Serial.print("Connecting to ");
  Serial.println(host);

  WiFiClient client;
  const int httpPort=80;
  if(!client.connect(host, httpPort)){
    Serial.println("- Connection Failed -");
    return;
  }

  Serial.println("- CONNECTED! -");
  Serial.println("DB IP: ");
  Serial.println(host);

  //C:\xampp\htdocs\...
  
  String url = "/prototipo_protocolo/index.php/?";
  url += "proto=";
  url += proto;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
  "Host: " + host + "\r\n" +
  "Connection: close\r\n\r\n");
  delay(10);

  unsigned long timeout = millis();
  while(client.available()==0){
    if(millis()-timeout>5000){
      Serial.println("- Client Timeout -");
      client.stop();
      return;
    }
  }

  while(client.available()){
    line = client.readStringUntil('\r');
    Serial.println(line);
    digitalWrite(int_LED, HIGH);
    delay(1000);
  }
  
  //debug
  if(line.indexOf(proto)>0){
    Serial.println("- PROTOCOL FOUND -");
  }
  else{
    Serial.println("- PROTOCOL NOT FOUND -");
  }
  //------------
  
  Serial.println("- Closing Connection -");
  digitalWrite(int_LED, LOW);
  delay(500);
}
