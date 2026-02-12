SIM6822M Arduino Library

CARA PENGGUNAAN:

1. Include Library
#include <SIM6822M.h>

2. Buat Object
SIM6822M ipm(2,3,4,5,6,7,8);

Urutan Pin:
HIN_U,HIN_V,HIN_W,LIN_U,LIN_V,LIN_W,FO

3. Setup Awal
ipm.begin(10000);   // set frekuensi PWM
ipm.enable();       // mulai PWM

4. Set Duty
ipm.setDuty(120,120,120);

5. Jalankan di loop
ipm.run();

6. Cek Fault
if(ipm.fault()){
  // fault aktif
}

CATATAN:
FO Active LOW
Gunakan resistor pullup 10K
