#ifndef __MEADC_H__
#define __MEADC_H__

void InitEADC();
void SetADCState(uint32_t module, int onoff);
uint32_t ADC_Read(uint32_t module);

#endif
