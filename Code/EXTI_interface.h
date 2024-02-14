#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define INT0 6
#define INT1 7
#define INT2 5

#define INTF0 6
#define INTF1 7
#define INTF2 5

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define ISC2 6

#define LOW_LEVEL 0
#define IOC 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define EXT0 0
#define EXT1 1
#define EXT2 2

#define EXT0_MODE LOW_LEVEL
#define EXT1_MODE IOC
#define EXT2_MODE IOC


void EXT_INTERRUPT_VID_INTI(void);
void EXT_INTERRUPT_VID_ENABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_DISABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_SET_MODE(u8 interrupt_number,u8 mode);
void EXT0_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void));


#endif
