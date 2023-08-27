#ifndef STEPPER_H
#define STEPPER_H

#define  STEPPER_PORT   DIO_PORTC

#define  COIL_BLUE      DIO_PIN0
#define  COIL_PINK      DIO_PIN1
#define  COIL_YELLOW    DIO_PIN2
#define  COIL_ORANGE    DIO_PIN3



void Stepper_voidInit(void);
void Stepper_voidRotateACW(void);
void Stepper_voidRotateCW(void);





#endif
