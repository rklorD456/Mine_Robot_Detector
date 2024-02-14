#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_register.h"
#include "SPI_interface.h"

void Mater_init(void)
{

	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);


	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);


}

void Slave_init(void)
{

	CLR_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
}

u8 SPI_u8Transciever(u8 data){
	SPDR=data;
	while(GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}
