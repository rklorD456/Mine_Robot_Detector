#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_register.h"

void func_init(u8 prescaler){
	switch(prescaler){
	case WDG_163MS:{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_325MS:{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_65MS:{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_13S:{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_26S:{
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_52S:{
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_1:{
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
	}
	case WDG_2_1:{
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
	}
	default:
		break;
	}
}
void WDT_ON(void){
	SET_BIT(WDTCR,WDE);
}
void WDT_OFF(void){
	WDTCR = (1<<WDE) | (1<<WDTOE);
	WDTCR=0x00;
}
