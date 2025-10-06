// ADC128s.cpp
/******************************************************************************
This library reads all channels from the ADC128s 

IENAI SPACE
*******************************************************************************/

#include "ADC128s-v1.0.0.h"
size_t numChannels = 8;        // Number of channels


void ADCraw(uint8_t csPin, uint16_t* buffer) {

uint16_t acqBuffer[8]; // Acquire buffer. It gets the shifted data from the ADC

for (size_t i = 0; i < numChannels; i++)
{
  acqBuffer[i] = readADCsingle(csPin, i);
}

// Re-organize data buffer
for (size_t i = 0; i < numChannels-1; i++)
{
  buffer[i] = acqBuffer[i+1];
}
buffer[numChannels-1] = acqBuffer[0];

}


uint16_t readADCsingle(uint8_t csPin, uint8_t chan) {

// Select ADC
digitalWrite(csPin, LOW);

// Send channel address and read two bytes
uint8_t hi = SPI.transfer(chan << 3);
uint8_t lo = SPI.transfer(0x00);

// Deselect ADC
digitalWrite(csPin, HIGH);

// Combine into 12-bit result (mask off any garbage bits)
uint16_t adcVal = ((hi << 8) | lo) & 0x0FFF;

// Lab offset correction
adcVal += 1;

return adcVal;
}