// void shooter(){
  
//   if (ps5.L1()) {
//     // lastPWM = pwmValues[currentStep]; // Save last PWM before stopping
//     for(currentStep; currentStep>=0; currentStep-=2){
//       analogWrite(shoot1pwm, pwmValues[currentStep]);
//       analogWrite(shoot2pwm, pwmValues[currentStep]);
      
//       Serial.println(pwmValues[currentStep]);
//       SerialBT.println(pwmValues[currentStep]);
//       delay(10);
//     }
//     lastPWM=0;
//     analogWrite(shoot1pwm, 0); // Stop the motor
//     analogWrite(shoot2pwm, 0); 
//     isStopped = true;
//     Serial.println("Motor Stopped. "); //Press R1 to resume last PWM value.
//     SerialBT.println("Motor Stopped. "); //Press R1 to resume last PWM value.
//   }

//   else if (ps5.R1() && isStopped) { 
//     analogWrite(shoot1pwm, lastPWM);
//     analogWrite(shoot2pwm, lastPWM);
//     isStopped = false;
//     Serial.print("Motor Resumed at PWM: ");
//     Serial.println(lastPWM);
//     SerialBT.print("Motor Resumed at PWM: ");
//     SerialBT.println(lastPWM);
//   }

//   if (!isStopped) {
//     if (ps5.R2() && currentStep < 15) { // Step up PWM
//       currentStep++;
//       analogWrite(shoot1pwm, pwmValues[currentStep]);
//       analogWrite(shoot2pwm, pwmValues[currentStep]);
//       Serial.print("PWM increased to: ");
//       Serial.println(pwmValues[currentStep]);
//       SerialBT.print("PWM increased to: ");
//       SerialBT.println(pwmValues[currentStep]);
//       delay(200); // Debounce delay
//     } 
//     else if (ps5.L2() && currentStep >0) { // Step down PWM
//       currentStep--;
//       analogWrite(shoot1pwm, pwmValues[currentStep]);
//       analogWrite(shoot2pwm, pwmValues[currentStep]);
//       Serial.print("PWM decreased to: ");
//       Serial.println(pwmValues[currentStep]);
//       SerialBT.print("PWM decreased to: ");
//       SerialBT.println(pwmValues[currentStep]);
//       delay(200); // Debounce delay
//     }
//   }
// }
