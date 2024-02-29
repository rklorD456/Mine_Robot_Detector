#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "ADC_register.h"
#include"ADC_interface.h"
#include "Global_Interrupt_register.h"
#include "Global_Interrupt_interface.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "Timer_register.h"
#include "Timer_interface.h"
#include "motor_interface.h"


#define ir_pin              PIN_2
#define line_follower_pin   PIN_7
#define Puzzer_pin          PIN_0

unsigned int rand_seed = 1;
u16 detect_flag=1;
u16 ir_flag=0;

void ir (void);
u16 random_direction() {
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 2;
}

void main(void){
	DC_MOTOR_Init();
	PWM_Timer0_Init();
	Set_Motor_Speed(220);
	DIO_SetPinDirection(PORT_D,ir_pin,PIN_INPUT);
	DIO_SetPinValue(PORT_D,ir_pin,PIN_HIGH);
	DIO_SetPinDirection(PORT_A,line_follower_pin,PIN_INPUT);
	DIO_SetPinDirection(PORT_B,Puzzer_pin,PIN_OUTPUT);
	ADC_Init();
	Global_Interrupt_Enable();
	EXT_INTERRUPT_VID_INTI();
	EXT_INTERRUPT_VID_ENABLE(EXT0);
	Init_Timer1();
	
	while(detect_flag){
		u16 direction = random_direction();
		EXT0_VID_SET_CALL_BACK(ir);
		u16 READING=ADC_Read(Channel_A7);
		u32 RESULT=((u32)READING*5000)/1024;
		if (RESULT<300){
			DC_MOTOR_FORWARD();
		}
		else {
        	DC_MOTOR_Turnoff();
        	DIO_SetPinValue(PORT_B,Puzzer_pin,PIN_HIGH);
        	Delay_Seconds(1);
        	DIO_SetPinValue(PORT_B,Puzzer_pin,PIN_LOW);
        	detect_flag=0;
		}
		while (ir_flag) {
		        DC_MOTOR_BACK();
		        Delay_Seconds(1);
			if (direction==1){
				DC_MOTOR_LEFT();
			        Delay_Seconds(1);
		    	        EXT_INTERRUPT_VID_ENABLE(EXT0);
		                ir_flag = 0;}
			else{
				DC_MOTOR_RIGHT();
			        Delay_Seconds(1);
		    	        EXT_INTERRUPT_VID_ENABLE(EXT0);
		                ir_flag = 0;}
			}
		    }
	}

}

void ir (void){
	DC_MOTOR_Turnoff();
	ir_flag=1;
	EXT_INTERRUPT_VID_DISABLE(EXT0);
}
