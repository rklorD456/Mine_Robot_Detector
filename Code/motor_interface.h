#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#define DC_MOTOR_INPUT    PORT_A

#define DC_MOTOR_IN1      PIN_0
#define DC_MOTOR_IN2      PIN_1
#define DC_MOTOR_IN3      PIN_2
#define DC_MOTOR_IN4      PIN_3

#define DC_MOTOR_PWM      PORT_B

#define DC_MOTOR_ENA_ENB  PIN_3

void DC_MOTOR_Init();

void DC_MOTOR_FORWARD();

void DC_MOTOR_BACK();

void DC_MOTOR_RIGHT();

void DC_MOTOR_LEFT();

void DC_MOTOR_Turnoff();

void PWM_Timer0_Init();

void Set_Motor_Speed(u8 speed);

void Init_Timer1();

void Delay_Seconds(u16 seconds);

#endif

