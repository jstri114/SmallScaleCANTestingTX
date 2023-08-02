#include <Arduino.h>

#include <CAN.h>

// SPIClass.setMOSI(11);
// 	//void setMISO(uint8_t pin);
// 	//void setSCK(uint8_t pin);



void setup() {
  CAN.setPins(10);

  Serial.begin(9600);
  // while (!Serial);
// int pin = MCP2515Class::_csPin;
//   Serial.println("CAN Sender");
//   Serial.print(pin);
  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  else {
    Serial.println("CAN started successfully!");
  }
}

void loop() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12);
  CAN.write('h');
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);

  // // send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  // Serial.print("Sending extended packet ... ");

  // CAN.beginExtendedPacket(0xabcdef);
  // CAN.write('w');
  // CAN.write('o');
  // CAN.write('r');
  // CAN.write('l');
  // CAN.write('d');
  // CAN.endPacket();

  // Serial.println("done");

  // delay(1000);
}