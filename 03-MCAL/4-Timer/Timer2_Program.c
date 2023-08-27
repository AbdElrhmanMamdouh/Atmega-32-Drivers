#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO_Interface.h"
#include "Timer2_Interface.h"

u16 count , ticks;
static void (*TIMER_PFTimer2OVF) (void) ;
static void (*TIMER_PFTimer2CTC) (void) ;
void TIMER_voidCountsCalc(f32 sec) {
    u32 us = sec * 8000000.0/PRESCALER;

    if ((us % 256) == 0) {
        count = us / 256;
        ticks = 0;
    } else {
        count = (us / 256) + 1;
        ticks = 256 -(us % 256);
    }
}


void TIMER2_voidTimer2OVFInit(f32 sec)
{
	TIMER_voidCountsCalc(sec);
	/* Choose Normal mode */
	CLR_BIT(TCCR2 , WGM00);
	CLR_BIT(TCCR2 , WGM01);

	/* Enable Timer/Counter0 Overflow */
	SET_BIT(TIMSK , TOIE2);

	/* Initial Preload value ==> Desired Time = 1S */
	TCNT0 = ticks ;

	/* Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR2 , CS00);
	SET_BIT(TCCR2 , CS01);
	CLR_BIT(TCCR2 , CS02);

}

void TIMER2_voidTimer2CTCInit(void)
{
	/* Choose CTC mode */
	CLR_BIT(TCCR2 , WGM00);
	SET_BIT(TCCR2 , WGM01);

	/* Enable Timer/Counter0 CTC AND OVF */
	SET_BIT(TIMSK , OCIE2);

	/*Initial Compare match value ==> OCR = 100 & Desired Time = 1S */
	OCR2 = 99 ;

	/*Select clock " CLK \ 8" ==> Prescaler */
	CLR_BIT(TCCR2 , CS00);
	SET_BIT(TCCR2 , CS01);
	CLR_BIT(TCCR2 , CS02);

}
void TIMER2_voidTimer2OVFSetCallBack (void (*Copy_PFvoidTimer0OVF)(void))
{
	TIMER_PFTimer2OVF = Copy_PFvoidTimer0OVF ;
}

void TIMER2_voidTimer2CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void))
{
	TIMER_PFTimer2CTC = Copy_PFvoidTimer0CTC ;
}

ISR (TIMER2_OVF_vect)
{
	static u16 Local_u16OVFCounter = 0 ;
	Local_u16OVFCounter ++ ;
	if (Local_u16OVFCounter == count)
	{
		/* Clear Local_u8OVFCounter */
		Local_u16OVFCounter = 0 ;
		/* Initial Preload value */
		TCNT2 = ticks ;
		/*Action*/
		TIMER_PFTimer2OVF() ;
	}
}

ISR(TIMER2_COMP_vect)
{
	static u16 Local_u16CTCCounter = 0 ;
	Local_u16CTCCounter ++ ;
	if (Local_u16CTCCounter == 10000)
	{
		/*Action*/
		TIMER_PFTimer2CTC() ;

		/* Clear Local_u8OVFCounter */
		Local_u16CTCCounter = 0 ;
	}
}
