#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Global_Interrupt_interface.h"
#include "Global_Interrupt_register.h"

void Global_Interrupt_Enable(void){

	SET_BIT(SREG,I);

}

void Global_Interrupt_disable(void){

	CLR_BIT(SREG,I);

}
