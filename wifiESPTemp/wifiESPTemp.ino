#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "DHT.h"
#include <pgmspace.h>
#include <IRremoteESP8266.h>
#include <IRremoteInt.h>

#define DHTPIN 14
#define DHTTYPE DHT11  // change to DHT11 if that's what you have

 
#define WLAN_SSID "INTELBRAS"
#define WLAN_PASS ""


IRsend irsend(15);
const int tm = 198;
const int16_t  desligar[198] = {6150,7350,550,1650,550,1650,550,1600,600,1650,550,1600,600,1600,600,1600,600,1600,550,550,550,600,500,650,550,550,600,550,550,550,600,550,550,550,600,1600,500,1700,600,1600,600,1600,600,1600,550,1650,550,1650,550,1600,550,600,500,650,500,600,600,550,550,550,600,550,550,550,600,550,550,1650,550,1650,550,1650,500,1700,550,1600,600,1600,600,1600,600,1600,600,550,550,550,550,600,550,550,600,550,500,600,500,650,550,550,600,1650,550,1600,600,550,550,1650,550,1650,550,1650,550,1600,600,1600,550,600,500,600,600,1600,600,550,550,550,600,550,550,600,550,550,550,1650,550,1650,550,1650,550,1650,500,1650,600,550,600,1600,500,1700,550,550,600,550,550,600,550,550,550,600,550,1600,600,550,550,600,550,550,600,1600,500,600,600,1600,600,550,600,1600,550,550,600,550,550,1650,550,600,550,1600,600,550,550,1650,550,550,600,1600,600,1600,550,7400,600,};
const int16_t  ligar1[tm]  = {6050,7300,550,1600,600,1600,600,1550,600,1600,600,1600,550,1600,550,1650,550,1600,550,600,550,550,550,550,600,550,550,550,600,500,600,550,550,550,600,1600,550,1600,600,1600,550,1600,600,1600,550,1600,600,1600,550,1650,550,550,550,550,600,550,550,550,550,550,600,550,550,550,600,500,600,1600,600,1550,600,1600,600,1600,550,1600,600,1600,550,1600,600,1600,550,550,600,500,600,550,550,550,600,550,550,550,550,550,600,550,550,1600,600,550,550,1600,600,550,550,1600,550,600,550,1600,550,1650,550,550,550,1600,600,550,550,1600,600,550,550,1600,550,600,550,550,550,1650,550,1600,550,1650,550,1600,550,1650,550,550,550,1650,550,1600,550,600,550,550,550,550,600,550,550,550,600,1550,600,550,550,550,600,550,550,1600,600,550,550,1600,600,500,600,1600,600,500,600,550,550,1600,600,550,550,1600,600,500,600,1600,550,550,600,1600,550,1600,600,7300,600,};

const int16_t  temp16[tm]  =  {6000,7350,550,1650,450,1700,600,1600,500,1650,550,1650,500,1650,600,1600,500,1700,550,550,500,600,500,650,550,550,500,600,550,600,500,600,550,600,450,1700,550,1650,450,1700,550,1650,550,1600,500,1700,550,1600,550,1650,550,550,500,650,550,550,500,600,550,600,450,650,550,600,450,650,550,550,500,650,450,1700,550,1650,450,1700,550,1650,450,1700,550,1650,450,1750,550,1600,500,600,550,600,450,650,550,550,500,650,550,550,500,1700,550,550,550,1600,500,650,550,1600,600,550,550,1600,500,1700,550,550,500,1700,550,550,550,1650,550,550,550,1600,600,550,550,550,600,1600,550,1600,600,1600,550,1600,600,1600,550,550,600,1600,550,1600,600,550,550,550,500,650,550,550,550,600,500,1650,550,550,550,600,550,550,550,1650,550,550,550,1650,550,550,550,1600,550,600,550,550,550,1650,550,550,550,1600,600,550,550,1600,500,650,550,1600,500,1700,550,7350,550,};
const int16_t  temp17[tm]  = {6050,7300,550,1650,550,1600,550,1650,550,1600,550,1650,550,1600,600,1600,550,1600,550,600,550,550,550,550,600,550,550,550,550,600,550,550,550,550,600,1600,550,1650,550,1600,550,1650,550,1600,550,1600,600,1600,550,1600,600,550,550,550,550,600,550,550,550,600,550,550,550,550,600,550,550,1600,600,500,600,1600,550,1600,600,1600,600,1600,550,1600,600,1600,550,550,550,1650,550,550,550,550,600,550,550,550,550,550,600,550,600,1550,600,550,550,1600,550,600,600,1550,550,600,550,1600,550,1600,600,550,550,1600,600,550,550,1600,600,550,550,1600,550,600,550,550,550,600,550,1600,550,1650,550,1600,550,1650,550,550,550,1650,550,1600,550,1650,550,550,600,550,550,550,550,550,550,1650,550,550,550,550,600,550,550,1600,600,550,550,1600,550,550,600,1600,550,550,600,550,550,1600,600,550,550,1600,600,550,550,1600,550,600,550,1600,550,1650,550,7350,550,};
const int16_t  temp18[tm]  = {6050,7300,600,1550,550,1650,600,1550,600,1600,600,1600,600,1550,600,1600,600,1550,600,550,550,550,500,600,600,550,500,600,600,500,600,550,550,550,600,1600,550,1600,600,1600,550,1600,600,1600,550,1600,600,1600,600,1550,600,550,550,550,600,500,600,550,600,500,500,650,600,500,500,650,600,1550,550,600,600,1550,500,1700,600,1550,550,1650,600,1550,500,1700,600,500,600,1600,600,500,600,500,600,550,600,500,600,500,600,550,550,1600,600,550,550,1600,600,500,600,550,600,500,600,1600,600,1550,600,550,600,1550,600,550,600,1550,600,1600,600,1550,600,550,600,500,550,1650,600,500,550,1650,550,1600,550,1650,600,500,550,1650,550,1600,500,600,600,1600,550,550,600,550,500,600,600,1550,600,550,600,500,600,550,600,1550,600,550,600,1550,600,550,600,1550,600,500,650,500,600,1550,600,550,600,1550,600,550,600,1550,600,500,650,1550,550,1650,600,7250,600,};
const int16_t temp19[tm]  = {6000,7350,500,1700,600,1550,550,1650,600,1550,550,1650,600,1600,550,1600,600,1600,550,550,600,500,600,550,550,550,600,500,600,550,550,550,600,550,550,1600,550,1650,550,1600,600,1600,550,1600,600,1600,550,1600,600,1600,550,550,600,550,550,550,550,600,550,550,500,600,600,500,550,600,600,1550,600,550,550,1600,550,1650,600,1550,550,1650,600,1550,550,1650,600,500,600,1600,550,550,500,650,550,550,500,650,600,500,600,500,600,1600,500,600,600,1600,600,500,600,500,600,550,550,1600,600,1600,550,550,600,1600,550,550,600,1600,550,1600,600,1600,550,550,500,650,550,550,600,500,600,1600,600,1550,600,1600,600,500,600,1600,550,1600,600,1600,500,1650,600,550,500,600,600,500,550,1650,600,500,600,550,550,550,600,1600,550,550,550,1650,550,550,600,1600,550,550,550,550,600,1600,550,550,600,1600,500,600,600,1550,650,500,600,1550,550,1650,600,7300,600,};
const int16_t temp20[tm]  = {6050,7350,600,1550,600,1600,600,1550,600,1600,600,1550,600,1600,600,1550,600,1600,600,500,600,550,600,500,500,650,600,500,500,600,600,500,600,550,600,1550,600,1600,600,1550,600,1600,600,1550,550,1650,600,1600,600,1550,600,500,600,550,600,500,600,550,600,500,600,500,600,550,600,500,600,1600,600,500,550,1650,600,1550,600,1600,600,1550,600,1600,600,1550,600,550,600,1550,600,550,600,500,550,550,600,550,550,550,600,500,550,1650,600,500,550,1650,600,500,550,600,600,500,550,1650,600,1550,550,600,550,1600,550,550,600,1600,550,1600,600,1600,550,550,600,550,550,1600,600,1600,550,550,600,1600,550,1600,600,500,600,1600,600,1550,600,550,600,500,600,1600,600,500,550,600,600,1550,600,550,600,500,550,550,600,1600,550,550,600,1600,550,550,600,1600,550,550,600,500,550,1650,600,500,550,1650,600,500,550,1650,600,500,600,1600,600,1550,600,7300,600,};


ESP8266WebServer server(80);
WiFiClient client;
 
 
DHT dht(DHTPIN, DHTTYPE, 14);

float humidity, temp_c, temp_f, heatindex;

void ReadSensor();
void handle_root();
void initHardware();

void ligar();
void fdesligar();

void tempZero();
void tempUm();
void tempDois();
void tempTres();
void tempQuatro();

String webPage = "";

void setup() {
  pinMode(16, OUTPUT);
  pinMode(0, OUTPUT);
  initHardware();
  webPage += "<p><a href=\"socket1On\"></a>&nbsp;<a href=\"socket1Off\"></a>&nbsp;<a href=\"temp16\"></a></a>&nbsp;<a href=\"temp17\"></a></a>&nbsp;<a href=\"temp18\"></a></a>&nbsp;<a href=\"temp19\"></a></a>&nbsp;<a href=\"temp20\"></a></p><p>Pronto</p>";
  irsend.begin();
  Serial.begin(115200);
  delay(10);
 
  // Connecting to wifi
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  // Set a static IP (optional)  
  IPAddress ip(192, 168, 206, 55);
  IPAddress gateway(192, 168, 205, 255);
  IPAddress subnet(255, 255, 248, 0);
  WiFi.config(ip, gateway, subnet);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to wifi with IP ");  
  Serial.println(WiFi.localIP());

  // Define capabilities of our little web server
  //server.on("/", handle_root);
   server.on("/", [](){
    server.send(200, "text/html", webPage);
  });

  server.on("/socket1On", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Ligar a porra toda");
    ligar();
    
  });
  
  server.on("/socket1Off", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    fdesligar();
  });

  server.on("/temp16", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    tempZero();
  });

  server.on("/temp17", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    tempUm();
  });

   server.on("/temp18", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    tempDois();
  });

    server.on("/temp19", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    tempTres();
  });

   server.on("/temp20", [](){
    server.send(200, "text/html", webPage);
    Serial.println("Desligar a porra toda");
    tempQuatro();
  });


  server.on("/temp", [](){
    ReadSensor();
    server.send(200, "text/plain", String(temp_f));
  });
  
  server.on("/temp_c", [](){
    ReadSensor();
    server.send(200, "text/plain", String(temp_c));
  });

 
  server.on("/humidity", [](){
    ReadSensor();
    server.send(200, "text/plain", String(humidity));
  });
 
  server.on("/heatindex", [](){
    ReadSensor();
    server.send(200, "text/plain", String(heatindex));
  });

  server.on("/heatindex", [](){
    ReadSensor();
    server.send(200, "text/plain", String(heatindex));
  });

  server.begin();
  Serial.println("HTTP server started");

  dht.begin();
}

void handle_root() {
  server.send(200, "text/plain", "All systems go. Read data from /temp or or /temp_c or /humidity or /heatindex.");
  delay(100);
}

void loop() {
  //ligar();
  server.handleClient();
  delay(10);

}

//Sensor de temperatura
void ReadSensor() {
  // Read humidity (percent)
  humidity = dht.readHumidity();
  // Read temperature as Celsius
  temp_c = dht.readTemperature();
  // Read temperature as Fahrenheit
  temp_f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp_c) || isnan(temp_f)) {
    Serial.println("Failed to read from DHT sensor :-(");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  heatindex = dht.computeHeatIndex(temp_f, humidity);
}

void initHardware()
{
  Serial.begin(115200);
  //pinMode(DIGITAL_PIN, INPUT_PULLUP);
  //pinMode(LED_PIN, OUTPUT);
  //digitalWrite(LED_PIN, LOW);
  // Don't need to set ANALOG_PIN as input, 
  // that's all it can be.
}

void ligar(){
   digitalWrite(16, HIGH);
   digitalWrite(0, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&ligar1[i])); 
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }
 

 
void fdesligar(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&desligar[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }

  void tempZero(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&temp16[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }

 void tempUm(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&temp17[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }

  void tempDois(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&temp18[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }

   void tempTres(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&temp19[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }

  void tempQuatro(){
  
   digitalWrite(0, HIGH);
   digitalWrite(16, LOW);
    unsigned int rawCode1[tm];
       for(int i=0; i<tm; i++){
            rawCode1[i]= (pgm_read_word(&temp20[i]));
        }
     irsend.sendRaw(rawCode1,tm,38);   
    delay(2000);
    
 }



