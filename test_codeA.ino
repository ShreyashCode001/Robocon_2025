#include <ps5Controller.h>
#include <esp_system.h>

// DRIVE PINOUTS
const int pwmLF = 16, pwmRF = 23, pwmB = 18;
const int dirLF = 4,  dirRF = 19, dirB = 17;

// FEEDER PINOUTS
const int feed_relay = 21;

// DRIBBLE PINOUTS 
const int dribble_relay = 22;

// SHOOTER PINOUTS
const int S1_PWM = 18 , S1_DIR = 12;
const int S2_PWM = 14 , S2_DIR = 15;


float Lx,Ly,Rx, control;
float z;

// SHOOTER pinouts
static int pwmValues[16] = {25, 50, 75, 100, 120, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 255};
static int currentStep = 0;
static int lastPWM = 0;
static bool isStopped = true;

void setup() {
  Serial.begin(115200);
  ps5.begin("88:03:4C:93:FE:13");

  Serial.println("---------------Ready to pair-----------------");
  while (!ps5.isConnected()) {
    Serial.println("----------------Trying to connect--------------");
    delay(500);
  }
  Serial.println("--------------------Connected-------------------");

  pinMode(pwmLF, OUTPUT);  pinMode(dirLF, OUTPUT);
  pinMode(pwmRF, OUTPUT);  pinMode(dirRF, OUTPUT);
  pinMode(pwmB,  OUTPUT);  pinMode(dirB,  OUTPUT);

  pinMode(S1_PWM, OUTPUT);  
  pinMode(S1_DIR, OUTPUT);
  pinMode(S2_PWM, OUTPUT);  
  pinMode(S2_DIR, OUTPUT);

  pinMode(feed_relay, OUTPUT);
  pinMode(dribble_relay, OUTPUT);

  digitalWrite(feed_relay, LOW);  
  digitalWrite(dribble_relay, LOW); 

}

void loop() {


  Lx = ps5.LStickX();
  Ly = ps5.LStickY();
  Rx = ps5.RStickX();

  if (Lx || Ly || Rx) {  //for 3 wheel drive
    driveconditions();
  }
  if(ps5.R1() || ps5.R2() || ps5.L1() || ps5.R2()){
    v7_shooter();
  }
  if(ps5.Up()){
  dribblerelay();
  }
  if(ps5.Down()){
  feedrelay();
  }
 
}
