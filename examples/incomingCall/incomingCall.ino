/* A simple code that checks whether there is any incoming calls to sim900
 * The incoming phone number is written in the Serial
 * Owned by Fablab Hanoi
 * Library and examples written by Fablab Apprentice Nguyen Huy Anh
 */

#include <Sim.h>
#include <SoftwareSerial.h>

#define TX 7
#define RX 8
#define Baudrate 19200

Sim phone(Baudrate,TX,RX); // pin TX, pin RX, Baudrate
void setup() {
  Serial.begin(19200);
  delay(1000);
}

void loop() {
  if (phone.incomingCall()) // If there are any incoming calls
  {
    Serial.print("Incoming call from ");
    Serial.println(phone.callingNumber); // print the phone number to Serial
    delay(1000);
  }
}
