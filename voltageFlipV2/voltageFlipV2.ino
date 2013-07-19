
// V1 
// 7/8/2013 no more averaging. Read once only, then turn both pins off
#define voltageFlipPin1 20
#define voltageFlipPin2 21
#define sensorPin 0

int flipTimer = 0;


 // some constants for calibration. Use the same variables as the EC shield code
 // shit wat is all fo this
 
 // 1
 double X1 = 212;
 double Y1 = 220;
 double X2 = 739;
 double Y2 = 3000;
 
 // Time to do some maths
 // After calibration, figure out the range and offset
 double scale = (Y2-Y1)/(X2-X1);
 double offset = Y2 - X2*scale;
 
 
void setup(){
  Serial.begin(38400);
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
       
}


void setSensorPolarity(boolean flip){
  if(flip){
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  }else{
    digitalWrite(voltageFlipPin1, LOW);
    digitalWrite(voltageFlipPin2, HIGH);
  }
  
  
  
   // may need to be zero. Dictates the time between when the sensors turn on, and
   // when the voltage is read  (RC time constant of water? Time constant until it reaches fully 
   // 5 volts?
}

void settle(){
  // turn both off  
  digitalWrite(voltageFlipPin1, LOW);
  digitalWrite(voltageFlipPin2, LOW);
  delay(500);
}


void loop(){

  setSensorPolarity(true);
  // may need to be zero? see above in setSensorPolarity
  delay(flipTimer);
  int val1 = analogRead(sensorPin);
  
  setSensorPolarity(false);
  delay(flipTimer);
  // turn everything off
  settle();
  
  reportLevels(val1);  
  
  
 
}


void reportLevels(int val1){
  
  int ans = val1;
  
  double avg;

// use the constants we generated after calibration 
// when this conversion is done, you want this value to 
//  increase as the conductivity increases
  avg = scale*ans+offset;

  String msg = "raw: ";
  msg += ans;
  Serial.print(msg);
  
  Serial.print(" scaled: ");
  Serial.print(avg);
  Serial.println("");

}

