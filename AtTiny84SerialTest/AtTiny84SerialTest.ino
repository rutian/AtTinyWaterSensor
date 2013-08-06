// test RGB led writing capabilities of the AtTiny 84
	
 #include <SoftwareSerial.h>
  const int rx=4;
  const int tx=3;
  SoftwareSerial mySerial(rx, tx);
  
  int ledR = 8; 

void setup() 	 
{ 	        
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  mySerial.begin(4800);
  pinMode(ledR, OUTPUT); 
} 	 
  	 
void loop() 	
{ 	 
  digitalWrite(ledR,LOW);
  mySerial.println("hello world");
  delay(1000);
  digitalWrite(ledR,255);
  delay(1000);
} 	 
  	 

