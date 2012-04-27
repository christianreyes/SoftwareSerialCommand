// Demo Code for SerialCommand Library
// Steven Cogswell
// May 2011

#include <SoftwareSerial.h>
#include "SerialCommand.h"
#include "SoftwareSerialCommand.h"

const int arduinoLED = 13;   // Arduino LED on board

SoftwareSerial ss(4, 5);
SoftwareSerialCommand sCmd;     // The demo SerialCommand object

void setup() {
  pinMode(arduinoLED, OUTPUT);      // Configure the onboard LED for output
  digitalWrite(arduinoLED, LOW);    // default to LED off

  Serial.begin(9600);
  ss.begin(9600);
  
  if(ss.isListening())
    Serial.println("Software Serial Listening!");
  // Setup callbacks for SerialCommand commands
  sCmd.addCommand("!",    LED_on);          // Turns LED on
  sCmd.setDefaultHandler(unrecognized);      // Handler for command that isn't matched  (says "What?")
  Serial.println("Ready");
}

void loop() {
  sCmd.readSerial(&ss);     // We don't do much, just process serial commands
  
  //while (ss.available()) {
  //  Serial.println("READING");
  //  char inChar = ss.read(); 
  //  Serial.println(inChar);
  //}
}


void LED_on() {
  Serial.println("LED on");
  digitalWrite(arduinoLED, HIGH);
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}
