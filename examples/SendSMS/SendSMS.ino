/* A simple Arduino code that sends an SMS to the number defined in the code
 * Replace "**********" with the number that you intend to send an SMS to
 * Replace "test" with the message that you intend to send
 * Owned by Fablab Hanoi
 * Library and example written by Fablab Apprentice Nguyen Huy Anh
 */

#include <Sim.h>
#include <SoftwareSerial.h>

#define TX 7
#define RX 8
#define Baudrate 19200
#define number "0164*******" //number to send SMS to
#define message "test" // content of the SMS

Sim phone(Baudrate,TX,RX); // pin TX, pin RX, Baudrate
void setup() {
  Serial.begin(19200);
  delay(1000);
  phone.sendSMS(number, message); // Send an SMS to <number> with content <message>
}

void loop() {
  //Do nothing here
}
