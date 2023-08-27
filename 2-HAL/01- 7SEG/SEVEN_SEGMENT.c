#include<avr/io.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_Interface.h"
#include"SEVEN_SEGMENT.h"

#define ZERO     0b00111111
#define ONE      0b00000110
#define TWO      0b01011011
#define THREE    0b01001111
#define FOUR     0b01100110
#define FIVE     0b01101101
#define SIX      0b01111101
#define SEVEN    0b00000111
#define EIGHT    0b01111111
#define NINE     0b01101111

u8 arr[10] = {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
};

void SEVEN_SEGMENT_u8SetValue(u8 copy_u8port, u8 copy_u8Value){
	DIO_voidSetPortDirection(copy_u8port,0xFF);
	DIO_voidSetPortValue(copy_u8port,arr[copy_u8Value]) ;
	
}


