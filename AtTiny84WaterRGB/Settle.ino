// settle down between readings
void settle(){
  // turn both pins off, and pause before flipping again
  digitalWrite(voltageFlipPin1, LOW);
  digitalWrite(voltageFlipPin2, LOW);
  delay(1000);
}
