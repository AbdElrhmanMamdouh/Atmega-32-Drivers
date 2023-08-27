#include <avr/io.h>
#include "DIO_Interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG, DIO_PIN7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG, DIO_PIN7);
}