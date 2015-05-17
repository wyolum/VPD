#include "EZKey.h"

void keyCommand(SoftwareSerial BT, uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, 
                uint8_t keycode4, uint8_t keycode5, uint8_t keycode6) {
  BT.write(0xFD);       // our command
  BT.write(modifiers);  // modifier!
  BT.write((byte)0x00); // 0x00  
  BT.write(keycode1);   // key code #1
  BT.write(keycode2); // key code #2
  BT.write(keycode3); // key code #3
  BT.write(keycode4); // key code #4
  BT.write(keycode5); // key code #5
  BT.write(keycode6); // key code #6
}
