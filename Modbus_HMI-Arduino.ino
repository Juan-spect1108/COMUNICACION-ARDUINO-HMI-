#include <SPI.h>
#include <Ethernet.h>
#include "MgsModbus.h"

MgsModbus Mb;
int inByte = 0; // incoming serial byte

// Ethernet settings (depending on MAC and Local network)
byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x94, 0xB5 };
IPAddress ip(192, 168, 0, 22);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

int LECTURA;

void setup()
{

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  // serial setup
  Serial.begin(9600);
 

  // initialize the ethernet device
  Ethernet.begin(mac, ip, gateway, subnet);   // start etehrnet interface
  

  // print your local IP address:
  
 

  // Fill MbData
//  Mb.SetBit(0,false);
  Mb.MbData[0] = 0;
  Mb.MbData[1] = 0;
  Mb.MbData[2] = 0;
  Mb.MbData[3] = 0;
  Mb.MbData[4] = 0;
  Mb.MbData[5] = 0;
  Mb.MbData[6] = 0;
  Mb.MbData[7] = 0;
  Mb.MbData[8] = 0;
  Mb.MbData[9] = 0;
  Mb.MbData[10] = 0;
  Mb.MbData[11] = 0;
  
  // print MbData
 
}

void loop()
{

  if(Serial.available()>0){
    LECTURA= Serial.read();
  }

  Mb.MbData[0]= analogRead(0);

  digitalWrite(6, bitRead(Mb.MbData[1],0));
  digitalWrite(7, bitRead(Mb.MbData[2],0));
  digitalWrite(8, bitRead(Mb.MbData[3],0));
  digitalWrite(9, bitRead(Mb.MbData[4],0));

  if(LECTURA=='1'){
    digitalWrite(7,1);
   
   
   
  }

   if(LECTURA=='2'){
    digitalWrite(7,0);
   
   
   
  }
 

//  Mb.MbmRun();
  Mb.MbsRun();
}
