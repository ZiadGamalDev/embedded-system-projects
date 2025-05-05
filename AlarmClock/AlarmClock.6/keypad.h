#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "BIT_MATH.h"
#include "Registers.h"
#define F_CPU 16000000UL

#include <util/delay.h>

#define INVALID_KEYPAD_PRESS (0xff)

void keypad_init(void);
unsigned char keypad_read(void);

#endif /* KEYPAD_H_ */