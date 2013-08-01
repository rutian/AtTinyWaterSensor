
// Onto the AtTiny85
// 7/24/2013


// setup our softwareSerial communications
// you must press reset on the arduino to receive communications!
 #include "includes.h"
 #include <SoftwareSerial.h>
 const int rx=4;
 const int tx=3;
 SoftwareSerial mySerial(rx, tx);

 // may need to be zero. Dictates the time between when the sensors turn on, and
 // when the voltage is read  (RC time constant of water? Time constant until it reaches fully 
 // 5 volts?
 int flipTimer = 1;


 // some constants for calibration. 
 double X1 = 166;
 double Y1 = 220;// low end calibration solution  
 double X2 = 546;
 double Y2 = 3000;// high end calibration solution
 
 // Time to do some maths
 // After calibration, figure out the range and offset
 double scale = (Y2-Y1)/(X2-X1);
 double offset = Y2 - X2*scale;
 
 
void setup(){
  // setup your software serial
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  mySerial.begin(4800);
  
  // configure the output pins
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT); // is this necessary? 
       
}

void loop(){

  setSensorPolarity(true);
  // may need to be zero? see above when flipTimer is declared
  delay(flipTimer);
  
  //make a reading
  int raw = analogRead(sensorPin);
  
  setSensorPolarity(false);
  
  delay(flipTimer);
  
  settle();
  
  int answer = returnScaled(raw);  
  
  mySerial.print("raw: ");
  mySerial.print(raw);
  mySerial.print(" ans: ");
  mySerial.println(answer);
 
}






