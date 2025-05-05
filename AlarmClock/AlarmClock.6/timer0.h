#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "std_types.h"

#define F_CPU 16000000UL
#define NOMBER_OF_OVERFLOWS 63

void timer0_init(void);
void timer0_setCallback(void (*callback)(void));
void timer0_start(void);
void timer0_stop(void);

#endif /* TIMER0_H_ */