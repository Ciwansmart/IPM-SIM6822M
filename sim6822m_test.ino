#include <SIM6822M.h>

#define BTN_START 10
#define BTN_STOP  11

SIM6822M ipm(
  2,3,4,
  5,6,7,
  8
);

bool running=false;

void setup(){

  Serial.begin(115200);

  pinMode(BTN_START,INPUT_PULLUP);
  pinMode(BTN_STOP,INPUT_PULLUP);

  ipm.begin(10000); //10kHz

}

void loop(){

  if(digitalRead(BTN_START)==LOW){
    running=true;
    ipm.enable();
    delay(200);
  }

  if(digitalRead(BTN_STOP)==LOW){
    running=false;
    ipm.disable();
    delay(200);
  }

  if(ipm.fault()){
    Serial.println("FAULT IPM !");
    running=false;
    ipm.disable();
  }

  if(running){
    ipm.setDuty(120,120,120);
    ipm.run();
  }
}
