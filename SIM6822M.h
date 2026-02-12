#ifndef SIM6822M_h
#define SIM6822M_h

#include <Arduino.h>

class SIM6822M {

public:

  SIM6822M(
    uint8_t hin_u,
    uint8_t hin_v,
    uint8_t hin_w,
    uint8_t lin_u,
    uint8_t lin_v,
    uint8_t lin_w,
    uint8_t fo
  );

  void begin(uint32_t freq);
  void enable();
  void disable();

  void setDuty(uint8_t du,uint8_t dv,uint8_t dw);
  void run();
  bool fault();

private:

  uint8_t _hin_u,_hin_v,_hin_w;
  uint8_t _lin_u,_lin_v,_lin_w;
  uint8_t _fo;

  uint32_t _period;
  uint32_t _last;

  uint8_t _du,_dv,_dw;
};

#endif
