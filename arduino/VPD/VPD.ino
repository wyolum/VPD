/*
  translate voice commands to bluetooth keyboard navigation
 */
#include <SoftwareSerial.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "EasyVR.h"

SoftwareSerial easy_vr_ser(12,13); // RX, TX
SoftwareSerial ez_key_ser(A5, A4); // RX, TX
EasyVR easyvr(easy_vr_ser);

int8_t bits = 4;
int8_t set = 2;
int8_t group = 0;
uint32_t mask = 0;  
uint8_t train = 0;
uint8_t grammars = 0;
int8_t lang = 0;
char name[33];
bool useCommands = true;
bool useTokens = false;


const char* ws0[] =
{
  "ROBOT",
};
const char* ws1[] =
{
  "ACTION",
  "MOVE",
  "TURN",
  "RUN",
  "LOOK",
  "ATTACK",
  "STOP",
  "HELLO",
};
const char* ws2[] =
{
  "LEFT",     // 0
  "RIGHT",    // 1
  "UP",       // 2
  "DOWN",     // 3
  "FORWARD",  // 4
  "BACKWARD", // 5
};
const char* ws3[] =
{
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE",
  "TEN",
};
const char** ws[] = { ws0, ws1, ws2, ws3 };
const int ws_len = 4;
const int ws_lengths[] = {1, 8, 6, 10};

const int LEFT = 0;
const int RIGHT = 1;
const int FOREWARD = 4;
const int BACKWARD = 5;


char *text = "//hello world";
void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  ez_key_ser.begin(9600);
  // ez_key_ser.print(text);

  // set up easy_vr
  easy_vr_ser.begin(9600);

  if (!easyvr.detect())
  {
    Serial.println("EasyVR not detected!");
    for (;;);
  }
  else{
    Serial.println("EasyVR detected ");
  }
  easyvr.setPinOutput(EasyVR::IO1, LOW);
  Serial.print("Version ");
  Serial.println(easyvr.getID());
  easyvr.setTimeout(0);
  lang = EasyVR::ENGLISH;
  easyvr.setLanguage(lang);
  
  int16_t count = 0;
  
  group = 0;
  mask |= 1; // force to use trigger
  easyvr.setKnob(4);
  Serial.println("Done with setup");
  easyvr.playSound(0, EasyVR::VOL_FULL);
}

void loop()
{
  checkMonitorInput();
  
  easyvr.setPinOutput(EasyVR::IO1, HIGH); // LED on (listening)
  Serial.print("Say a word in Wordset ");
  Serial.println(set);
  for(int ii=0; ii<ws_lengths[set]; ii++){
    Serial.print(ws[set][ii]);
    Serial.print(", ");
  }
  Serial.println("");
  easyvr.recognizeWord(set);

  do
  {
    if (checkMonitorInput())
      return;
  }
  while (!easyvr.hasFinished());
  
  easyvr.setPinOutput(EasyVR::IO1, LOW); // LED off

  int16_t idx;
  // handle voice recognition
  idx = easyvr.getWord();
  if (idx >= 0) // found a word
  {
    if(set == 0){
      easyvr.playSound(0, EasyVR::VOL_FULL);
      delay(10);
      easyvr.playSound(0, EasyVR::VOL_FULL);
    }
    if(set == 2){
      if((idx == LEFT) || (idx == BACKWARD)){
	ez_key_ser.print((char)0x0B);
      }
      else if((idx == RIGHT) || (idx == FOREWARD)){
	ez_key_ser.print((char)0x07);
      }
    }
    // accept forward/backward/right/left
    Serial.print("Word: ");
    Serial.print(idx);
    Serial.print(" = ");
    if (set < 4)
      Serial.println(ws[set][idx]);
      // ---
    set = 2;
  }
}


bool checkMonitorInput()
{
  if (Serial.available() <= 0)
    return false;
  
  // check console commands
  int16_t rx = Serial.read();
  if (rx == 'l')
  {
    easyvr.stop();
    lang++;
    if (easyvr.setLanguage(lang) || easyvr.setLanguage(lang = 0))
    {
      Serial.print("Language set to ");
      Serial.println(lang);
    }
    else
      Serial.println("Error while setting language!");
  }
  if (rx == 'b')
  {
    useTokens = false;
    useCommands = false;
    set++;
    if (set > 3)
      set = 0;
  }
  if (rx == 'g' && grammars > 4)
  {
    useTokens = false;
    useCommands = false;
    set++;
    if (set >= grammars)
      set = 4;
  }
  if (rx == 'c')
  {
    useTokens = false;
    useCommands = true;
    do
    {
      group++;
      if (group > EasyVR::PASSWORD)
        group = 0;
    } while (!((mask >> group) & 1));
  }
  if (rx == 'k')
  {
    useTokens = true;
  }
  if (rx == '4')
  {
    bits = 4;
  }
  if (rx == '8')
  {
    bits = 8;
  }
  if (rx == 'n')
  {
    int16_t num = 0;
    delay(5);
    while ((rx = Serial.read()) >= 0)
    {
      delay(5);
      if (isdigit(rx))
        num = num * 10 + (rx - '0');
      else
        break;
    }
    Serial.print("Play token ");
    Serial.println(num);
    easyvr.stop();
    easyvr.sendToken(bits, num);
  }
  if (rx == 's')
  {
    int16_t num = 0;
    delay(5);
    while ((rx = Serial.read()) >= 0)
    {
      delay(5);
      if (isdigit(rx))
        num = num * 10 + (rx - '0');
      else
        break;
    }
    Serial.print("Play sound ");
    Serial.println(num);
    easyvr.stop();
    easyvr.playSound(num, EasyVR::VOL_DOUBLE);
  }
  if (rx == 'd')
  {
    easyvr.stop();
    Serial.println("Play tones:");
    int16_t num = 0;
    delay(5);
    while ((rx = Serial.read()) >= 0)
    {
      delay(5);
      if (isdigit(rx))
        num = rx - '0';
      else if (rx == '*')
        num = 10;
      else if (rx == '#')
        num = 11;
      else if (rx >= 'A' && rx <= 'D')
        num = rx - 'A';
      else if (rx == '_')
        num = -1;
      else
        break;
      Serial.print(num);
      if (easyvr.playPhoneTone(num, 3))
        Serial.println(" OK");
      else
        Serial.println(" ERR");
    }
  }
  if (rx >= 0)
  {
    easyvr.stop();
    Serial.flush();
    return true;
  }
  return false;
}

