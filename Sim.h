/*
 * Sim.h
 * A library for using the sim900 module
 *
 * Owner: Fablab Hanoi
 * Written by Fablab Apprentice Nguyen Huy Anh
 *
*/
#ifndef Sim_h
#define Sim_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class Sim
{
	public:
        Sim(int Baud, int TX, int RX);
		void call(String number);
		void sendSMS(String number, String message);
		bool incomingCall();
		bool incomingMessage();
		String callingNumber;
		String messageNumber;
		String Message;
		/*void answer();
		void hangUp();
		void messageRead();
		void messageDelete();*/

	private:
		String fx;
        SoftwareSerial simSerial;
        String getCallingNumber(String S);
        String getMessageNumber(String S);
        String getMessage(String S);

};

#endif
