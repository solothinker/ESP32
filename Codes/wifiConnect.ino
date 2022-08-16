#include <WiFi.h>

const char* WIFI_NAME = "*****";//<- name of wifi
const char* PASSWORD = "*****";//<- put the password
const int WIFI_TIMEOUT_MS = 20000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(WIFI_NAME,PASSWORD);

  unsigned long startTime = millis();

  while(WiFi.status()!= WL_CONNECTED && millis()-startTime<WIFI_TIMEOUT_MS)
  {
    delay(100);
    Serial.print(".");
  }

  if (WiFi.status()!= WL_CONNECTED){
    Serial.println("\nFailed...");
  }else{
  Serial.println("\nConnected to WiFi Network");
  Serial.println(WiFi.localIP());}

}

void loop() {
  // put your main code here, to run repeatedly:

}
