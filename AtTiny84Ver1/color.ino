// code to write color to LEDs

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

        double value = 510 - (.255*reading) ;

        analogWrite(ledG,value);
        analogWrite(ledR,255);
           
    
  }
  else if (reading>= cutoffHigh) //ALL red. indicate unsafe to drink
  {
       analogWrite(ledG,0);
       analogWrite(ledR,255);

  }

} 	 


  	 

