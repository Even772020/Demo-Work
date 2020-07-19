#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "esp8266";
ESP8266WebServer server(80);




void setup()
{

   Serial.begin(115200);
   
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound(HTTP_handleRoot);
     server.begin();    
 
  }

void loop() {
    server.handleClient();
    
  }
  
void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
