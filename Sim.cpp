/*
 * Sim.h
 * A library for using the sim900 module
 *
 * Owner: Fablab Hanoi
 * Written by Fablab Apprentice Nguyen Huy Anh
 *
*/

#include "Sim.h"


Sim::Sim(int Baud, int TX, int RX):simSerial(TX,RX)
{
    simSerial.begin(Baud);
    simSerial.println("AT+CNMI=2,2,0,0,0");
}
void Sim::call(String number)
{

    fx = "ATD"+number+";\r";
    simSerial.println(fx);
    //Serial.println(fx);
}

void Sim::sendSMS(String number, String message)
{

    simSerial.print("AT+CMGF=1\r");
    delay(1000);
    fx = "AT+CMGS=\"" + number + "\"\r";
    simSerial.print(fx);
    delay(1000);
    String ms = message + "\r";
    simSerial.print(ms);
    delay(1000);
    simSerial.write(0x1A);
    delay(1000);
}

String Sim::getCallingNumber(String S)
{
    return(S.substring(18,S.length()-16));
}

bool Sim::incomingCall()
{
    if (simSerial.available())
    {
        String S = simSerial.readString();
        String stat = S.substring(2,6);
        if (stat=="RING")
        {
            callingNumber = getCallingNumber(S);
            return(1);
        }else
        return(0);
    }else return(0);
}
String Sim::getMessageNumber(String S)
{
    String res;
    for (int i=1;i<=S.length();i++)
    {
        if (S.substring(i,i+1)=="\"")
        {
            int k = i+1;
            while (S.substring(k,k+1)!="\"") k++;
            res = S.substring(i+1,k);
            break;
        }
    }
    return(res);
}
String Sim::getMessage(String S)
{
    return(S.substring(messageNumber.length()+38,S.length()-2));
}
bool Sim::incomingMessage()
{
    if (simSerial.available())
    {
        String S = simSerial.readString();
        String stat = S.substring(2,6);
        if (stat =="+CMT")
        {
            messageNumber = getMessageNumber(S);
            Message = getMessage(S);
            return(1);
        } else return(0);
    } else return(0);
}
