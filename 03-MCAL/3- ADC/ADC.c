//LIB Layer
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include <avr/interrupt.h>
//MCAL
#include "DIO_interface.h"
#include "EXTI_Interface.h"
#include "ADC.h"
//HAL


void ADC_voidInit (void) {
	switch(REFS){
		case 0 : CLR_BIT(ADMUX,REFS0); SET_BIT(ADMUX,REFS0); break;
		case 1 : SET_BIT(ADMUX,REFS0); SET_BIT(ADMUX,REFS0); break;
		case 2 : CLR_BIT(ADMUX,REFS0); SET_BIT(ADMUX,REFS1); break;
		case 3 : SET_BIT(ADMUX,REFS0); SET_BIT(ADMUX,REFS1); break;
	}
	/* 	Select Right Adjust*/
	CLR_BIT(ADMUX , ADLAR);
	/* 	Disable AutoTrigger Enable*/
	CLR_BIT(ADCSRA , ADATE);
	/*  Enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	/*  Enable INT*/
//	SET_BIT(ADCSRA,ADIE);
	/* 	Select CLK */
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

}
u16  ADC_u16GetDigitalValue(u8 Copy_u8ChannelNum){

	// Channel
	ADMUX = ((ADMUX & 0xE0) | Copy_u8ChannelNum);

	// Start
	SET_BIT(ADCSRA,ADSC);

	// Wait
	while (GET_BIT(ADCSRA,ADIF)==0) {}

	SET_BIT(ADCSRA,ADIF);

	return ADC_REG ;

}


