#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/***************************************************************************************/
/* MACROS FOR CLOCK */
#define LOW_LEVEL      0
#define ANY_LOGICAL    1
#define FALLING        2
#define RAISING        3

/* MACROS FOR REGISTERS PINS */
/***** MCUCR ******/
#define MCUCR_ISC00         DIO_PIN0
#define MCUCR_ISC01         DIO_PIN1
#define MCUCR_ISC10         DIO_PIN2
#define MCUCR_ISC11         DIO_PIN3

/***** GICR ******/
#define GICR_INT0           DIO_PIN6
#define GICR_INT1           DIO_PIN7
#define GICR_INT2           DIO_PIN5
/***** SREG ******/
#define SREG_PIN            DIO_PIN7

#define ENABLE              0
#define DISABLE             1


/*
 * LOW_LEVEL
 * ANY_LOGICAL
 * FALLING
 * RAISING
 */
#define EXTI_CLOCK         LOW_LEVEL
/*
 * ENABLE
 * DISABLE
 */
#define GIE              ENABLE

/*************************************************************************************/

/* FUNCTIONS */
void EXTI_voidInit0(void);
void EXTI_voidInit1(void);
void EXTI_voidInit2(void);

void EXTI_voidGIE(void);

void EXTI_voidEXTISetCallBack(u8 copy_u8EXTIIndex, void (*copy_pf)(void));



#endif
