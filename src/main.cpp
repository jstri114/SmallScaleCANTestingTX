// LoopBackDemo

// This demo runs on Teensy 3.1 / 3.2, 3.5 and 3.6
// The FlexCAN module is configured in loop back mode: it internally receives
// every CAN frame it sends.

// No external hardware required.

//-----------------------------------------------------------------

#include <ACAN.h>
#include <SPI.h>
#include <Metro.h>
Metro sendCAN = Metro(1000);
Metro heartbeat = Metro(500);

//-----------------------------------------------------------------

void setup () {
  Serial.begin (9600) ;
  Serial.println ("Hello") ;
  ACANSettings settings (500000) ; // 125 kbit/s

  const uint32_t errorCode = ACAN::can0.begin (settings) ;
  if (0 == errorCode) {
    Serial.println ("can0 ok") ;
  }else{
    Serial.print ("Error can0: 0x") ;
    Serial.println (errorCode, HEX) ;
  }
  
}

//-----------------------------------------------------------------

void loop () {
  
  if (sendCAN.check()) {
    CANMessage TEST;
    TEST.id = 0x69;
    TEST.data [0] = 0;
    TEST.data [1] = 1;
    TEST.data [2] = 2;
    TEST.data [3] = 3;
    TEST.data [4] = 4;
    TEST.data [5] = 5;
    TEST.data [6] = 6;
    TEST.data [7] = 7;
    ACAN::can0.tryToSend (TEST);
    Serial.print ("Message sent : ");
    Serial.print (TEST.id, HEX) ;
    Serial.print (" ") ;
    Serial.print (TEST.data[0], HEX) ;
    Serial.print (TEST.data[1], HEX) ;
    Serial.print (TEST.data[2], HEX) ;
    Serial.print (TEST.data[3], HEX) ;
    Serial.print (TEST.data[4], HEX) ;
    Serial.print (TEST.data[5], HEX) ;
    Serial.print (TEST.data[6], HEX) ;
    Serial.print (TEST.data[7], HEX) ;
    Serial.println ("");
  }

  if (heartbeat.check()) {
    digitalToggle(LED_BUILTIN);
  }

}