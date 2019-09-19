/* A simple Arduino code that informs whenever there are any new SMS
 * The message phone number and content can be seen in Serial
 * Owned by Fablab Hanoi
 * Library and example written by Fablab Apprentice Nguyen Huy Anh
 */

#include <Sim.h>
#include <SoftwareSerial.h>

#define TX 7
#define RX 8
#define Baudrate 19200

Sim phone(Baudrate,TX,RX);
void setup() {
  Serial.begin(19200);
  delay(1000);
}

void loop() {
  if (phone.incomingMessage()) // if there is a new SMS
    {
      Serial.print("Got a message from: ");
      Serial.println(phone.messageNumber); // the number of the sender
      Serial.print("Message: ");
      Serial.println(phone.Message); // the content of SMS
    }

}
