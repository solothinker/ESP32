
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
String SwitchIt;
int LED_BUILTIN=2;
String message = "";


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Read received messages (LED control command)
  if (SerialBT.available()){
    char SwitchIt = SerialBT.read();
    if (SwitchIt != '\n'){
      message += String(SwitchIt);
    }
    else{
      message = "";
    }
    Serial.write(SwitchIt);  
  }
  // Check received message and control output accordingly
  if (message =="led_on"){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if (message =="led_off"){
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(20);
}
