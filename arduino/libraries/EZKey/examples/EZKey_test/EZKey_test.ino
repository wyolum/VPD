#include "EZKey.h"
#include <SoftwareSerial.h>

SoftwareSerial BT(A5, A4); // RX, TX
void setup(){
  keyCommand(BT, MODIFIER_NONE, KEY_A, 0, 0, 0, 0, 0);
}

void loop(){
  keyCommand(BT, MODIFIER_NONE, KEY_A, 0, 0, 0, 0, 0);
  keyCommand(BT, MODIFIER_NONE, 0, 0, 0, 0, 0, 0); // release
  delay(1000);
}
