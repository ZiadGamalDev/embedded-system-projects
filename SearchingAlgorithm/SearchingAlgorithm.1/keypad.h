#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Registers.h"
#include "BIT_MATH.h"

void keypad_init(void);
char keypad_read(void);

#endif /* KEYPAD_H_ */