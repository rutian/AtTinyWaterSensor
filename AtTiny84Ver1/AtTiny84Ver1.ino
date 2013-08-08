/****************************************
* Onto the AtTiny84!!!!
* 8/7/2013
* version "1" 
* find water quality, then quantitatively 
* display data through an RGB LED
* TODO: transfer data to mobile device?
****************************************/

// setup our softwareSerial communications
// you must press reset on the arduino to receive communications!
 #include <SoftwareSerial.h>
 const int rx=4;
 const int tx=3;
 SoftwareSerial mySerial(rx, tx);
  
  
 const int voltageFlipPin1 =10; 
 const int voltageFlipPin2=  9;
 const int sensorPin = 0 ;//analog input
 
 /****************
 * For the RGB LED
 *
 *****************/
 // set cutoff values, relative to potential readings from the sensor
 const int cutoffLow = 1000; // starting to get sketchy
 const int cutoffHigh= 2000; // cannot drink if above
 // 3 pwm pins for the led
 int ledR = 8; 	
 int ledG = 7; 	
 int ledB = 6; 	


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
  
  // configure the led pins
  pinMode(ledR, OUTPUT); 	
  pinMode(ledG, OUTPUT); 
  pinMode(ledB, OUTPUT); 
  
  // configure the output pins
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT); // is this necessary? 
  mySerial.println("hello world");
       
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
  // display to RGB led
  color(answer);
  
  mySerial.print("raw: ");
  mySerial.print(raw);
  mySerial.print(" ans: ");
  mySerial.println(answer);
  
  
 
}






