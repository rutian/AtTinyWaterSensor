#include <SoftwareSerial.h>
const int rx=2;
const int tx=3;


SoftwareSerial mySerial(rx, tx);



void setup() 
{ 
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
   mySerial.begin(4800);
  
} 
 
void loop() 
{ 
  mySerial.println("hello");
  delay(100);
  
}
