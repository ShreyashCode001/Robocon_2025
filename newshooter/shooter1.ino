void dribble(){
  
  if (ps5.Left()) {
    // lastPWM = pwmValues[currentStep]; // Save last PWM before stopping
    for(currentStep1; currentStep1>=0; currentStep1-=2){
      analogWrite(shoot1pwm, pwmValues[currentStep1]);
      
      Serial.println(pwmValues[currentStep1]);
      SerialBT.println(pwmValues[currentStep1]);
      delay(10);
    }
    lastPWM1=0;
    analogWrite(shoot1pwm, 0); // Stop the motor 
    isStopped1 = true;
    currentStep1 =0;
    Serial.println("Motor1 Stopped. "); //Press R1 to resume last PWM value.
    SerialBT.println("Motor1 Stopped. "); //Press R1 to resume last PWM value.
  }
  
  else if (ps5.Circle()) {
    // lastPWM = pwmValues[currentStep]; // Save last PWM before stopping
    for(currentStep2; currentStep2>=0; currentStep2-=2){
      analogWrite(shoot2pwm, pwmValues[currentStep2]);
      
      Serial.println(pwmValues[currentStep2]);
      SerialBT.println(pwmValues[currentStep2]);
      delay(10);
    }
    lastPWM2=0;
    analogWrite(shoot2pwm, 0); 
    isStopped2 = true;
    currentStep2 = 0;
    Serial.println("Motor2 Stopped. "); //Press R1 to resume last PWM value.
    SerialBT.println("Motor2 Stopped. "); //Press R1 to resume last PWM value.
  }

  else if (ps5.Right() && isStopped1) { 
    analogWrite(shoot1pwm, lastPWM1);
    isStopped1 = false;
    Serial.print("Motor1 Resumed at PWM: ");
    Serial.println(lastPWM1);
    SerialBT.print("Motor Resumed1 at PWM: ");
    SerialBT.println(lastPWM1);
  }

   else if (ps5.Square() && isStopped2) { 
    analogWrite(shoot2pwm, lastPWM2);
    isStopped2 = false;
    Serial.print("Motor2 Resumed at PWM: ");
    Serial.println(lastPWM2);
    SerialBT.print("Motor2 Resumed at PWM: ");
    SerialBT.println(lastPWM2);
  }

  if (!isStopped1) {
    if (ps5.L1() && currentStep1 < 15) { // Step up PWM
      currentStep1++;
      analogWrite(shoot1pwm, pwmValues[currentStep1]);
      Serial.print("PWM1 increased to: ");
      Serial.println(pwmValues[currentStep1]);
      SerialBT.print("PWM1 increased to: ");
      SerialBT.println(pwmValues[currentStep1]);
      delay(200); // Debounce delay
    } 
    else if (ps5.L2() && currentStep1 >0) { // Step down PWM
      currentStep1--;
      analogWrite(shoot1pwm, pwmValues[currentStep1]);
      Serial.print("PWM1 decreased to: ");
      Serial.println(pwmValues[currentStep1]);
      SerialBT.print("PWM1 decreased to: ");
      SerialBT.println(pwmValues[currentStep1]);
      delay(200); // Debounce delay
    }
  }
  
  if (!isStopped2) {
    if (ps5.R1() && currentStep2 < 15) { // Step up PWM
      currentStep2++;
      analogWrite(shoot2pwm, pwmValues[currentStep2]);
      Serial.print("PWM2 increased to: ");
      Serial.println(pwmValues[currentStep2]);
      SerialBT.print("PWM2 increased to: ");
      SerialBT.println(pwmValues[currentStep2]);
      delay(200); // Debounce delay
    } 
    else if (ps5.R2() && currentStep2 >0) { // Step down PWM
      currentStep2--;
      analogWrite(shoot2pwm, pwmValues[currentStep2]);
      Serial.print("PWM2 decreased to: ");
      Serial.println(pwmValues[currentStep2]);
      SerialBT.print("PWM2 decreased to: ");
      SerialBT.println(pwmValues[currentStep2]);
      delay(200); // Debounce delay
    }
  }
}
