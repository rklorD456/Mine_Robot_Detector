#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_register.h"

void ADC_Init (void){
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	CLR_BIT(ADMUX,ADLAR);

	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);

	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_Read (u8 Channel){

	ADMUX=((ADMUX&0b11100000)|(Channel));
	SET_BIT(ADCSRA,ADSC);

	while(GET_BIT(ADCSRA,ADIF)==0);

	SET_BIT(ADCSRA,ADIF);

	return ADC_Reg;
}
u32 Mapping (u32 Range1_max,u32 Range1_min,u32 Range2_max,u32 Range2_min,u32 Range1_reading){

	return (Range2_max-((Range2_max-Range2_min)*(Range1_max-Range1_reading)/(Range1_max-Range1_min)));
}

