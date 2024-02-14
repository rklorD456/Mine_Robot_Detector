#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void TIM0_voidInitialize(void);

void TIM0_voidSetTimerReg(u8 Copy_u8Value);

void TIM0_voidSetCompareVal(u8 Copy_u8Value);

void TIM0_voidEnableOVINT(void);

void TIM0_voidDisableOVINT(void);

void TIM0_voidEnableCTCINT(void);

void TIM0_voidDisableCTCINT(void);

void TIM0_voidSetOVCallback( void (*callback_Copy_ptr) (void) );

void TIM0_voidSetCTCCallback( void (*callback_Copy_ptr) (void) );

void TIM1_voidInitialize(void);

void TIM1_A_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_B_voidSetCompareVal(u16 Copy_u16Value);

void TIM1_A_voidSetICR(u16 Copy_u16Value);

#endif /* TIMER_INTERFACE_H_ */
