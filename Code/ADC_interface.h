#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7

void ADC_Init (void);
u16 ADC_Read (u8 Channel);
u32 Mapping (u32 Range1_max,u32 Range1_min,u32 Range2_max,u32 Range2_min,u32 Range1_reading);

#endif
