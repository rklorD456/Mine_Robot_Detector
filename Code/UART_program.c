
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_register.h"
#include "UART_interface.h"

void UART_init(void){
// control UCSRC register
u8 UCSRC_value=0;
SET_BIT(UCSRC_value,7);

// make 8 bits for data
SET_BIT(UCSRC_value,1);
SET_BIT(UCSRC_value,2);

UCSRC=UCSRC_value;

// make baud rate = 9600 bps

 UBRRL=51;


//enable transmit and recive
SET_BIT(UCSRB,RXEN);
SET_BIT(UCSRB,TXEN);
}
void UART_sendchar(u8 data){
	while(GET_BIT(UCSRA,UDRE)==0);
 UDR=data;
}
u8 UART_recievechar(void){
while(GET_BIT(UCSRA,RXC)==0);
return UDR;
}


