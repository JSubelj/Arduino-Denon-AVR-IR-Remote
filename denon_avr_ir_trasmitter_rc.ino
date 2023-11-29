// Arduino Denon AVR IR Transmitter Remote Control 

// This works for Arduino Mega 2560
// Required:
//    - jumper cables
//    - IR diode
//    - 200-250 ohm resistor
// Connection:
//    - Negative pin of IR diode to GND
//    - Positive pin to via 200 ohm - 250 ohm resistor PIN 9 (on Mega 2560, it is other pin for other boards)

#include <IRremote.h>  

#define PIN_SEND 9
#define REPEAT_NUM 1

void setup() {
  Serial.begin(230400);        // opens serial port, sets data rate to 9600 bps
  IrSender.begin(PIN_SEND);  // Initializes IR sender
}

// pronto codes at: http://assets.denon.com/documentmaster/us/denon%20master%20ir%20hex.xls
// If using PROGMEM then you need to call function irsend.sendPronto_P(command,num_of_reps);
// If using normal variable then call irsend.sendPronto(command,num_of_reps);
const char toggle_power[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";
const char up[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 001E 000A 0046 000A 001E 000A 0046 000A 0046 000A 0679";
const char down[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 0046 000A 001E 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 001E 000A 0046 000A 0046 000A 0679";
const char left[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 0679 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0679";
const char right[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 0046 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";
const char enter[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";
const char system_setup[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 001E 000A 0046 000A 0046 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 0046 000A 001E 000A 0046 000A 0046 000A 0679";
const char back[] PROGMEM = "0000 0070 0000 0032 0080 0040 0010 0010 0010 0010 0010 0030 0010 0010 0010 0030 0010 0010 0010 0030 0010 0010 0010 0010 0010 0030 0010 0010 0010 0010 0010 0030 0010 0030 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0030 0010 0010 0010 0030 0010 0010 0010 0010 0010 0010 0010 0010 0010 0030 0010 0010 0010 0010 0010 0010 0010 0030 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0010 0030 0010 0030 0010 0010 0010 0010 0010 0010 0010 0030 0010 0030 0010 0010 0010 0ACE";
const char vol_up[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";
const char vol_down[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 001E 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";
const char mute[] PROGMEM = "0000 006D 0000 0020 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 0679 000A 001E 000A 0046 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0046 000A 0046 000A 001E 000A 001E 000A 001E 000A 001E 000A 0046 000A 0046 000A 0679";


// IrSender.sendDenon did not work, thats why I use sendPronto. Also Denon publishes their Pronto codes on the web.

void loop() {
  Serial.print("Enter command:");
  while (Serial.available() == 0) {}  //wait for data available
  String c = Serial.readString();     //read until timeout
  c.trim();                           // remove any \r \n whitespace at the end of the String

  if(c=="power"){
    Serial.println("Sending 'power'");
    IrSender.sendPronto_P(toggle_power, REPEAT_NUM);
  } else if(c=="u"){
    Serial.println("Sending 'up'");
    IrSender.sendPronto_P(up, REPEAT_NUM);
  } else if(c=="d"){
    Serial.println("Sending 'down'");
    IrSender.sendPronto_P(down, REPEAT_NUM);
  } else if(c=="r"){
    Serial.println("Sending 'right'");
    IrSender.sendPronto_P(right, REPEAT_NUM);
  } else if(c=="l"){
    Serial.println("Sending 'left'");
    IrSender.sendPronto_P(left, REPEAT_NUM);
  } else if(c=="e"){
    Serial.println("Sending 'enter'");
    IrSender.sendPronto_P(enter, REPEAT_NUM);
  } else if(c=="b"){
    Serial.println("Sending 'back'");
    IrSender.sendPronto_P(back, REPEAT_NUM);
  } else if(c=="ss"){
    Serial.println("Sending 'system setup'");
    IrSender.sendPronto_P(system_setup, REPEAT_NUM);
  } else if(c=="volu"){
    Serial.println("Sending 'volume up'");
    IrSender.sendPronto_P(vol_up, REPEAT_NUM);
  } else if(c=="vold"){
    Serial.println("Sending 'volume down'");
    IrSender.sendPronto_P(vol_down, REPEAT_NUM);
  } else if(c=="mute"){
    Serial.println("Sending 'mute'");
    IrSender.sendPronto_P(mute, REPEAT_NUM);
  } else {
    Serial.println("Command '"+c+"' not found.");
    Serial.println("Commands:");
    Serial.println("   power  - power toggle");
    Serial.println("   u      - up");
    Serial.println("   d      - down");
    Serial.println("   l      - left");
    Serial.println("   r      - right");
    Serial.println("   e      - enter");
    Serial.println("   b      - back");
    Serial.println("   ss     - system setup");
    Serial.println("   volu   - volume up");
    Serial.println("   vold   - volume down");
    Serial.println("   mute   - toggle mute");
  }
}
