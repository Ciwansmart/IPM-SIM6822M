#include "SIM6822M.h"

SIM6822M::SIM6822M(
uint8_t hin_u,uint8_t hin_v,uint8_t hin_w,
uint8_t lin_u,uint8_t lin_v,uint8_t lin_w,
uint8_t fo){

  _hin_u=hin_u; _hin_v=hin_v; _hin_w=hin_w;
  _lin_u=lin_u; _lin_v=lin_v; _lin_w=lin_w;
  _fo=fo;
}

void SIM6822M::begin(uint32_t freq){

  _period=1000000UL/freq;

  pinMode(_hin_u,OUTPUT);
  pinMode(_hin_v,OUTPUT);
  pinMode(_hin_w,OUTPUT);

  pinMode(_lin_u,OUTPUT);
  pinMode(_lin_v,OUTPUT);
  pinMode(_lin_w,OUTPUT);

  pinMode(_fo,INPUT_PULLUP);

  disable();
}

void SIM6822M::enable(){
  _last=micros();
}

void SIM6822M::disable(){

  digitalWrite(_hin_u,LOW);
  digitalWrite(_hin_v,LOW);
  digitalWrite(_hin_w,LOW);

  digitalWrite(_lin_u,LOW);
  digitalWrite(_lin_v,LOW);
  digitalWrite(_lin_w,LOW);
}

bool SIM6822M::fault(){
  return digitalRead(_fo)==LOW;
}

void SIM6822M::setDuty(uint8_t du,uint8_t dv,uint8_t dw){
  _du=du; _dv=dv; _dw=dw;
}

void SIM6822M::run(){

  if(fault()){
    disable();
    return;
  }

  uint32_t now=micros();
  uint32_t t=now-_last;

  if(t>=_period){
    _last=now;
    t=0;
  }

  uint32_t on_u=(_period*_du)/255;
  uint32_t on_v=(_period*_dv)/255;
  uint32_t on_w=(_period*_dw)/255;

  digitalWrite(_hin_u,t<on_u);
  digitalWrite(_hin_v,t<on_v);
  digitalWrite(_hin_w,t<on_w);

  digitalWrite(_lin_u,t>=on_u);
  digitalWrite(_lin_v,t>=on_v);
  digitalWrite(_lin_w,t>=on_w);
}
