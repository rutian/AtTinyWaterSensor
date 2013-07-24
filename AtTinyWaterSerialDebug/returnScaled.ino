int returnScaled(int val1){
  
  int ans = val1;
  
  double avg;

  // use the constants we generated after calibration 
  avg = scale*ans+offset;
    
  if (val1 <X1){
    // if the value is less than our intial calibration value,
    // return the uncalibrated value
    return val1;
  }
  
  else{
    return (int) avg;
  }


}
