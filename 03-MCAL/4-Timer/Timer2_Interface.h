#ifndef		TIMER2_H_
#define 	TIMER2_H_



void TIMER2_voidTimer2OVFInit(f32 sec);
void TIMER2_voidTimer2CTCInit(void);


void TIMER2_voidTimer2OVFSetCallBack (void (*Copy_PFvoidTimer0OVF) (void));
void TIMER2_voidTimer2CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void));

// Seconds needed
void TIMER_voidCountsCalc(f32 sec);

#define PRESCALER 8

#endif
