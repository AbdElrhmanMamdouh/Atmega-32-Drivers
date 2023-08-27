#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "STEPPER.h"


void Stepper_voidInit(void)
{
	DIO_voidSetPinDirection(STEPPER_PORT, COIL_BLUE  , DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT, COIL_PINK  , DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT, COIL_YELLOW, DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT, COIL_ORANGE, DIO_OUTPUT);

}
void Stepper_voidRotateCW(void)
{
	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_HIGH);
	_delay_ms(100);

}
void Stepper_voidRotateACW(void)
{
	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_HIGH);
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

	DIO_voidSetPinValue(STEPPER_PORT, COIL_BLUE  , DIO_HIGH);
	DIO_voidSetPinValue(STEPPER_PORT, COIL_PINK  , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_YELLOW, DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT, COIL_ORANGE, DIO_LOW );
	_delay_ms(100);

}
