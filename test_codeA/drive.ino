
float mapping(float control) {
  
  if ((-128 <= control) && (control <= -30)) {
    z = map(control, -30, -128, 0, 150);
  } else if ((30 <= control) && (control <= 128)) {
    z = map(control, 30, 128, 0, 150);
  } else {
    z = 0;
  }
  return z;
}

void driveconditions() {

  if (Ly > 30)                  //FORWARD
  {
    z = mapping(Ly);
    run_motor(7, z);
  } else if (Ly < -30)          //BACKWARD
  {
    z = mapping(Ly);
    run_motor(8, z);
  } else if (Lx < -30)          //LEFT
  {
    z = mapping(Lx);
    run_motor(1, z);
  } else if (Lx > 30)           //RIGHT
  {
    z = mapping(Lx);
    run_motor(2, z);
  } else if (Rx > 30)           //CLOCKWISE
  {
    z = mapping(Rx);
    run_motor(3, z);
  } else if (Rx < -30)          //ANTI_CLOCKWISE
  {
    z = mapping(Rx);
    run_motor(4, z);
  } else if (z > 0)             //stop1 (starts stoping gradually)
  {
    z = -10;
    run_motor(6, z);
    delay(100);
  } else 
    z = 0;
    run_motor(7, z);
  }
}


void run_motor(int condn, int z) {
  switch (condn) { 
    case 1:  //LEFT
      digitalWrite(dirB, LOW);        analogWrite(pwmB, z);
      digitalWrite(dirRF, HIGH);      analogWrite(pwmRF, z / 1.8);
      digitalWrite(dirLF, HIGH);      analogWrite(pwmLF, z / 1.8);
      
      break;
    case 2:  //RIGHT
      digitalWrite(dirB, HIGH);       analogWrite(pwmB, z);
      digitalWrite(dirLF, LOW);       analogWrite(pwmLF, z / 1.8);
      digitalWrite(dirRF, LOW);       analogWrite(pwmRF, z / 1.8);
      
      break;
    case 3:  //CLOCKWISE
      digitalWrite(dirLF, HIGH);    analogWrite(pwmLF, z);
      digitalWrite(dirRF, HIGH);    analogWrite(pwmRF, z);
      digitalWrite(dirB, HIGH);     analogWrite(pwmB,  z);
      
      break;
    case 4:  //ANTI-CLOCKWISE
      digitalWrite(dirB, LOW);      analogWrite(pwmB, z);
      digitalWrite(dirLF, LOW);     analogWrite(pwmLF, z);
      digitalWrite(dirRF, LOW);     analogWrite(pwmRF, z);
      
      break;
    case 6:  //BACKWARD
      digitalWrite(dirLF, HIGH);    analogWrite(pwmLF, z);
      digitalWrite(dirRF, LOW);     analogWrite(pwmRF, z);
                                    analogWrite(pwmB, 0);
      break;
    case 7:  //FORWARD
      digitalWrite(dirLF, LOW);     analogWrite(pwmLF, z);
      digitalWrite(dirRF, HIGH);    analogWrite(pwmRF, z);
                                    analogWrite(pwmB, 0);
      break;
  }
}
