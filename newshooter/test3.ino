#include <BluetoothSerial.h>
#include <ps5Controller.h>
#include <esp_system.h>

const int stepper1 = 27;
const int stepdir1 = 14;

const int pwmLF = 16, pwmRF = 23, pwmB = 18;
const int dirLF = 4, dirRF = 19, dirB = 17;

float Lx, Rx, Ly, Ry, z, control;  

const int shootpwm = 21, shootdir = 22; 

const int relay1 = 12;  
const int relay2 = 13;

BluetoothSerial SerialBT;

int releasepwm=0;
int pwmValues[20] = {25, 50, 75, 100, 120, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 255}; 
int currentStep = 0; // Track the current step index
int lastPWM = 0; // Stores last PWM value before stopping
bool isStopped = 1; // Start with motor stopped


void setup() {
  Serial.begin(115200);
  ps5.begin("88:03:4C:93:FE:13");
  SerialBT.begin("R1");

  Serial.println("Bluetooth Started! Ready to pair...");
  SerialBT.println("Bluetooth Started! Ready to pair...");

  pinMode(stepper1, OUTPUT);
  pinMode(stepdir1, OUTPUT);

  pinMode(pwmLF, OUTPUT);
  pinMode(pwmRF, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dirLF, OUTPUT);
  pinMode(dirRF, OUTPUT);
  pinMode(dirB, OUTPUT);

  pinMode(shootpwm, OUTPUT);
  pinMode(shootdir, OUTPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  digitalWrite(relay1, LOW);  
  digitalWrite(relay2, LOW);

  digitalWrite(shootdir, LOW);  // Ensure direction is set initially
  analogWrite(shootpwm, 0);     // Ensure motor starts stopped
  Serial.println("System initialized. Motor is OFF.");
  SerialBT.println("System initialized. Motor is OFF.");

  while (!ps5.isConnected()) {
    Serial.println("Connecting to PS5 Controller...");
    SerialBT.println("Connecting to PS5 Controller...");
    delay(500);
  }
  Serial.println("Connected to PS5 Controller!");

}

void loop() {
  Lx = ps5.LStickX();
  Ly = ps5.LStickY();
  Ry = ps5.RStickY();
  Rx = ps5.RStickX();

  if (Lx || Ly || Ry || Rx) {  //for 3 wheel drive
    drivemode();
  }  
  
  if (ps5.Up() || ps5.Down()) {  //for relay
    relay();
  }

  if (ps5.L2()) {  // for shooter 
    shooter();
  }

  if (ps5.Square() || ps5.Circle()) {  //for arm shooter
     stepper_arm();
  }
  shooter();
  stepper_arm();

}
