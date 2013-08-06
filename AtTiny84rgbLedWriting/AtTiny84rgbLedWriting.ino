// test RGB led writing capabilities of the AtTiny 84
	
int ledR = 8; 	
int ledG = 7; 	
int ledB = 6; 	

 #include <SoftwareSerial.h>
  const int rx=4;
  const int tx=3;
  SoftwareSerial mySerial(rx, tx);
  	 
// set cutoff values, relative to potential readings from the sensor
int cutoffLow = 1000; // starting to get sketchy
int cutoffHigh= 2000; // cannot drink if above


void setup() 	 
{ 	        
  
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  mySerial.begin(4800); 

  pinMode(ledR, OUTPUT); 	
  pinMode(ledG, OUTPUT); 
  pinMode(ledB, OUTPUT); 
} 	 
  	 
void loop() 	
{ 	 


color(1800);
     

} 	 
  	 
void color (int reading)    
{ 
  // cutoff values. what to do... cutoffLow cutoffHigh
  if(reading < cutoffLow)// safe safe safe
  {
        int value = (256*reading)/(cutoffLow);
        analogWrite(ledR,(int) value);
        analogWrite(ledG,255);
  }
  else if (reading >=cutoffLow && reading < cutoffHigh)// yo water is getting kinda sketchy
  {
        // do math. scale down the G until you hit cutoffHigh.
        int value = 510 - ((51/200)*reading) ;
        mySerial.print(reading);
        mySerial.print(" ");
        mySerial.println(value);
        analogWrite(ledG,value);
        analogWrite(ledR,255);
           
    
  }
  else if (reading>= cutoffHigh) //ALL red. indicate unsafe to drink
  {
       analogWrite(ledG,0);
       analogWrite(ledR,255);

  }

} 	 

void writeColor( byte red, byte green, byte blue){
  
  
  
  
}
  	 

