#include <BluetoothSerial.h>
#include <ps5Controller.h>
#include <esp_system.h>

BluetoothSerial SerialBT;

const int shoot1pwm=23, shoot2pwm=18;
const int shoot1dir=19, shoot2dir=17;

int releasepwm1=0;
int releasepwm2=0;
int pwmValues[20] = {25, 50, 75, 100, 120, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 255}; 
int currentStep1 = 0; // Track the current step index
int lastPWM1 = 0; // Stores last PWM value before stopping
bool isStopped1 = 1; // Start with motor stopped
int currentStep2 = 0; // Track the current step index
int lastPWM2 = 0; // Stores last PWM value before stopping
bool isStopped2 = 1; // Start with motor stopped

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ps5.begin("88:03:4C:93:FE:13");
  SerialBT.begin("R1");

  Serial.println("Bluetooth Started! Ready to pair...");
  SerialBT.println("Bluetooth Started! Ready to pair...");

  pinMode(shoot1pwm, OUTPUT);
  pinMode(shoot1dir, OUTPUT);
  pinMode(shoot2pwm, OUTPUT);
  pinMode(shoot2dir, OUTPUT);

  digitalWrite(shoot1dir, LOW);  // Ensure direction is set initially
  analogWrite(shoot1pwm, 0);     // Ensure motor starts stopped
  digitalWrite(shoot2dir, LOW);  // Ensure direction is set initially
  analogWrite(shoot2pwm, 0);     // Ensure motor starts stopped
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
  // put your main code here, to run repeatedly:
  if (ps5.L2() || ps5.L1() || ps5.R1() || ps5.R2() || ps5.Left() || ps5.Right() || ps5.Square() || ps5.Circle()) {  // for shooter 
    //shooter();
    // SerialBT.print("PWM 1 :");SerialBT.println(pwmValues[currentStep1]);
    // SerialBT.print("PWM 2 :");SerialBT.println(pwmValues[currentStep2]);
    dribble();

  }
  
}
