// ADC128s.h
/******************************************************************************
This library reads all channels from the ADC128s 

IENAI SPACE
*******************************************************************************/
//#include "ATH-NANO-PCU-v2.1.0.h"
#ifndef ADC128s_h
#define ADC128s_h

#include "Arduino.h"
#include "SPI.h"

/******************************************************************************************
* Function Declarations
*******************************************************************************************/

uint16_t readADCsingle(uint8_t adcID, uint8_t chan);
void ADCraw(uint8_t csPin, uint16_t* buffer);

#endif

