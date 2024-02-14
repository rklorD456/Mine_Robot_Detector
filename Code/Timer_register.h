#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0_Register  *((volatile u8*)0x53)
#define OCR0_Register  *((volatile u8*)0x5C)
#define TIFR_Register  *((volatile u8*)0x58)
#define TIMSK_Register  *((volatile u8*)0x59)
#define TCNT0_Register  *((volatile u8*)0x52)

#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register  *((volatile u8*)0x4E)
#define TCNT1_Register  *((volatile u16*)0x4C)
#define OCR1A_Register  *((volatile u16*)0x4A)
#define OCR1B_Register  *((volatile u16*)0x48)
#define ICR1_Register  *((volatile u16*)0x46)

#endif /* TIMER_REGISTER_H_ */
