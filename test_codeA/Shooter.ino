void v7_shooter() {
  static int pwmValues[16] = {25, 50, 75, 100, 120, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 255};
  static int currentStep = 0;
  static int lastPWM = 0;
  static bool isStopped = true;

  digitalWrite(S1_PWM, HIGH);
  digitalWrite(S2_PWM, HIGH);

  if (ps5.L1()) {
    lastPWM = pwmValues[currentStep];
    for (int i = currentStep; i >= 0; i -= 2) {
      analogWrite(S1_PWM, pwmValues[i]);
      analogWrite(S2_PWM, pwmValues[i]);
      Serial.println(pwmValues[i]);
      delay(10);
    }
    analogWrite(S1_PWM, 0);
    analogWrite(S2_PWM, 0);
    currentStep = 0;
    isStopped = true;
    Serial.println("Motors Stopped.");
  } 
  
  else if (ps5.R1() && isStopped) {
    analogWrite(S1_PWM, lastPWM);
    analogWrite(S2_PWM, lastPWM);
    isStopped = false;
    Serial.print("Motor Resumed at PWM: ");
    Serial.println(lastPWM);
  }

  if (!isStopped) {
    if (ps5.R2() && currentStep < 15) {
      currentStep++;
      analogWrite(S1_PWM, pwmValues[currentStep]);
      analogWrite(S2_PWM, pwmValues[currentStep]);
      Serial.print("PWM increased to: ");
      Serial.println(pwmValues[currentStep]);
      delay(200);
    } 
    else if (ps5.L2() && currentStep > 0) {
      currentStep--;
      analogWrite(S1_PWM, pwmValues[currentStep]);
      analogWrite(S2_PWM, pwmValues[currentStep]);
      Serial.print("PWM decreased to: ");
      Serial.println(pwmValues[currentStep]);
      delay(200);
    }
  }
}
