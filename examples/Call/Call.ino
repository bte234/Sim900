/* A simple Arduino code that calls the number defined in the code
 * Replace "*********" with the number that you intend to call
 * Owned by Fablab Hanoi
 * Library and example written by Fablab Apprentice Nguyen Huy Anh
 */

#include <Sim.h>
#include <SoftwareSerial.h>

#define TX 7
#define RX 8
#define Baudrate 19200
#define number "0164*******"

Sim phone(Baudrate,TX,RX); // pin TX, pin RX, Baudrate
void setup() {
  Serial.begin(19200);
  delay(1000);
  phone.call(number); // call the number defined above

}

void loop() {
  //Do nothing here
}
