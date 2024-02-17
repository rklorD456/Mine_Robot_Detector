#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "Timer_register.h"
#include "Timer_interface.h"
#include "motor_interface.h"

void DC_MOTOR_Init(){

	DIO_SetPinDirection(DC_MOTOR_INPUT,DC_MOTOR_IN1,PIN_OUTPUT);

	DIO_SetPinDirection(DC_MOTOR_INPUT,DC_MOTOR_IN2,PIN_OUTPUT);

	DIO_SetPinDirection(DC_MOTOR_INPUT,DC_MOTOR_IN3,PIN_OUTPUT);

	DIO_SetPinDirection(DC_MOTOR_INPUT,DC_MOTOR_IN4,PIN_OUTPUT);

	DIO_SetPinDirection(DC_MOTOR_PWM,DC_MOTOR_ENA_ENB,PIN_OUTPUT);
}
void DC_MOTOR_FORWARD()
{

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN1, PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN2, PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN3,PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN4,PIN_HIGH);
}

void DC_MOTOR_BACK(){

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN1, PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN2, PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN3, PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN4, PIN_LOW);

}

void DC_MOTOR_RIGHT(){

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN1, PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN2, PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN3, PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT, DC_MOTOR_IN4, PIN_LOW);

}

void DC_MOTOR_LEFT(){

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN1,PIN_HIGH);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN2, PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN3,PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN4,PIN_HIGH);


}

void DC_MOTOR_Turnoff(){

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN1,PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN2,PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN3, PIN_LOW);

	DIO_SetPinValue(DC_MOTOR_INPUT,DC_MOTOR_IN4,PIN_LOW);
}

void PWM_Timer0_Init() {
	SET_BIT(TCCR0_Register, 0);
	CLR_BIT(TCCR0_Register, 1);
	SET_BIT(TCCR0_Register, 2);
	CLR_BIT(TCCR0_Register, 3);
	SET_BIT(TCCR0_Register, 4);
	SET_BIT(TCCR0_Register, 5);
	SET_BIT(TCCR0_Register, 6);
	CLR_BIT(TCCR0_Register, 7);

	DIO_SetPortValue(TIMSK_Register,PORT_LOW);

}

void Set_Motor_Speed(u8 speed) {
    // Ensure speed is within valid range (0 to 255)
    if (speed > 255) {
        speed = 255;
    }
    OCR0_Register = speed;
}

void Init_Timer1() {
	SET_BIT(TCCR1B_Register, 0);
	SET_BIT(TCCR1B_Register, 1);
	CLR_BIT(TCCR1B_Register, 2);
}

void Delay_Seconds(u16 seconds) {
    for (u16 i = 0; i <= seconds; ++i) {
        // Wait for the Timer 1 overflow flag
        while (!GET_BIT(TIFR_Register, 2));
        // Clear the Timer 1 overflow flag by writing a logic 1 to it
        SET_BIT(TIFR_Register, 2);
    }
}
