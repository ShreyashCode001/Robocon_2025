void stepper_arm(){
  if (ps5.Triangle()) {
    digitalWrite(stepdir1, HIGH);  
    while (ps5.Triangle()) {
      digitalWrite(stepper1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepper1, LOW);
      delayMicroseconds(z);
      Serial.println("ARM UP");
      SerialBT.println("ARM UP");
    }
  }
  
  if (ps5.Cross()) {
    digitalWrite(stepdir1, LOW);
    while (ps5.Cross()) {
      digitalWrite(stepper1, HIGH);
      delayMicroseconds(z);
      digitalWrite(stepper1, LOW);
      delayMicroseconds(z);
      Serial.println("ARM DOWN");
      SerialBT.println("ARM DOWN");
    }
  }
}
