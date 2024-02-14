#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR  *((volatile u8*)(0x2D))

#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPSR  *((volatile u8*)(0x2E))

#define SPI2X 0
#define SPIF 7

#define SPDR *((volatile u8*)(0x2F))

#define LSB 0
#define MSB 7

#endif
