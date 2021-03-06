// Bits in usbHidKeyboardInput.modifiers
#include <inttypes.h>
#include <SoftwareSerial.h>

typedef uint8_t byte;

const byte MODIFIER_NONE          =byte((0));
const byte MODIFIER_CONTROL_LEFT  =byte((1<<0));
const byte MODIFIER_SHIFT_LEFT    =byte((1<<1));
const byte MODIFIER_ALT_LEFT      =byte((1<<2));
const byte MODIFIER_GUI_LEFT      =byte((1<<3));
const byte MODIFIER_CONTROL_RIGHT =byte((1<<4));
const byte MODIFIER_SHIFT_RIGHT   =byte((1<<5));
const byte MODIFIER_ALT_RIGHT     =byte((1<<6));
const byte MODIFIER_GUI_RIGHT     =byte((1<<7));

// Values for usbHidKeyboardInput.keyCodes
// Only the key codes for common keys are defined here. See Hut1_12.pdf for a full list.
const byte KEY_NONE               =byte(0x00);
const byte KEY_A                  =byte(0x04);
const byte KEY_B                  =byte(0x05);
const byte KEY_C                  =byte(0x06);
const byte KEY_D                  =byte(0x07);
const byte KEY_E                  =byte(0x08);
const byte KEY_F                  =byte(0x09);
const byte KEY_G                  =byte(0x0A);
const byte KEY_H                  =byte(0x0B);
const byte KEY_I                  =byte(0x0C);
const byte KEY_J                  =byte(0x0D);
const byte KEY_K                  =byte(0x0E);
const byte KEY_L                  =byte(0x0F);
const byte KEY_M                  =byte(0x10);
const byte KEY_N                  =byte(0x11);
const byte KEY_O                  =byte(0x12);
const byte KEY_P                  =byte(0x13);
const byte KEY_Q                  =byte(0x14);
const byte KEY_R                  =byte(0x15);
const byte KEY_S                  =byte(0x16);
const byte KEY_T                  =byte(0x17);
const byte KEY_U                  =byte(0x18);
const byte KEY_V                  =byte(0x19);
const byte KEY_W                  =byte(0x1A);
const byte KEY_X                  =byte(0x1B);
const byte KEY_Y                  =byte(0x1C);
const byte KEY_Z                  =byte(0x1D);
const byte KEY_1                  =byte(0x1E);
const byte KEY_2                  =byte(0x1F);
const byte KEY_3                  =byte(0x20);
const byte KEY_4                  =byte(0x21);
const byte KEY_5                  =byte(0x22);
const byte KEY_6                  =byte(0x23);
const byte KEY_7                  =byte(0x24);
const byte KEY_8                  =byte(0x25);
const byte KEY_9                  =byte(0x26);
const byte KEY_0                  =byte(0x27);
const byte KEY_RETURN             =byte(0x28);
const byte KEY_ESCAPE             =byte(0x29);
const byte KEY_BACKSPACE          =byte(0x2A);
const byte KEY_TAB                =byte(0x2B);
const byte KEY_SPACE              =byte(0x2C);
const byte KEY_MINUS              =byte(0x2D);
const byte KEY_EQUAL              =byte(0x2E);
const byte KEY_BRACKET_LEFT       =byte(0x2F);
const byte KEY_BRACKET_RIGHT      =byte(0x30);
const byte KEY_BACKSLASH          =byte(0x31);
const byte KEY_EUROPE_1           =byte(0x32);
const byte KEY_SEMICOLON          =byte(0x33);
const byte KEY_APOSTROPHE         =byte(0x34);
const byte KEY_GRAVE              =byte(0x35);
const byte KEY_COMMA              =byte(0x36);
const byte KEY_PERIOD             =byte(0x37);
const byte KEY_SLASH              =byte(0x38);
const byte KEY_CAPS_LOCK          =byte(0x39);
const byte KEY_F1                 =byte(0x3A);
const byte KEY_F2                 =byte(0x3B);
const byte KEY_F3                 =byte(0x3C);
const byte KEY_F4                 =byte(0x3D);
const byte KEY_F5                 =byte(0x3E);
const byte KEY_F6                 =byte(0x3F);
const byte KEY_F7                 =byte(0x40);
const byte KEY_F8                 =byte(0x41);
const byte KEY_F9                 =byte(0x42);
const byte KEY_F10                =byte(0x43);
const byte KEY_F11                =byte(0x44);
const byte KEY_F12                =byte(0x45);
const byte KEY_PRINT_SCREEN       =byte(0x46);
const byte KEY_SCROLL_LOCK        =byte(0x47);
const byte KEY_PAUSE              =byte(0x48);
const byte KEY_INSERT             =byte(0x49);
const byte KEY_HOME               =byte(0x4A);
const byte KEY_PAGE_UP            =byte(0x4B);
const byte KEY_DELETE             =byte(0x4C);
const byte KEY_END                =byte(0x4D);
const byte KEY_PAGE_DOWN          =byte(0x4E);
const byte KEY_ARROW_RIGHT        =byte(0x4F);
const byte KEY_ARROW_LEFT         =byte(0x50);
const byte KEY_ARROW_DOWN         =byte(0x51);
const byte KEY_ARROW_UP           =byte(0x52);
const byte KEY_NUM_LOCK           =byte(0x53);
const byte KEY_KEYPAD_DIVIDE      =byte(0x54);
const byte KEY_KEYPAD_MULTIPLY    =byte(0x55);
const byte KEY_KEYPAD_SUBTRACT    =byte(0x56);
const byte KEY_KEYPAD_ADD         =byte(0x57);
const byte KEY_KEYPAD_ENTER       =byte(0x58);
const byte KEY_KEYPAD_1           =byte(0x59);
const byte KEY_KEYPAD_2           =byte(0x5A);
const byte KEY_KEYPAD_3           =byte(0x5B);
const byte KEY_KEYPAD_4           =byte(0x5C);
const byte KEY_KEYPAD_5           =byte(0x5D);
const byte KEY_KEYPAD_6           =byte(0x5E);
const byte KEY_KEYPAD_7           =byte(0x5F);
const byte KEY_KEYPAD_8           =byte(0x60);
const byte KEY_KEYPAD_9           =byte(0x61);
const byte KEY_KEYPAD_0           =byte(0x62);
const byte KEY_KEYPAD_DECIMAL     =byte(0x63);
const byte KEY_EUROPE_2           =byte(0x64);
const byte KEY_APPLICATION        =byte(0x65);
const byte KEY_POWER              =byte(0x66);
const byte KEY_KEYPAD_EQUAL       =byte(0x67);
const byte KEY_F13                =byte(0x68);
const byte KEY_F14                =byte(0x69);
const byte KEY_F15                =byte(0x6A);
const byte KEY_CONTROL_LEFT       =byte(0xE0);
const byte KEY_SHIFT_LEFT         =byte(0xE1);
const byte KEY_ALT_LEFT           =byte(0xE2);
const byte KEY_GUI_LEFT           =byte(0xE3);
const byte KEY_CONTROL_RIGHT      =byte(0xE4);
const byte KEY_SHIFT_RIGHT        =byte(0xE5);
const byte KEY_ALT_RIGHT          =byte(0xE6);
const byte KEY_GUI_RIGHT          =byte(0xE7);

void keyCommand(SoftwareSerial BT, uint8_t modifiers, uint8_t keycode1, uint8_t keycode2, uint8_t keycode3, 
                uint8_t keycode4, uint8_t keycode5, uint8_t keycode6);
