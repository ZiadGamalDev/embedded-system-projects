#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <util/delay.h>
#define INVALID_KEYPAD_PRESS (0xFF)

#include "Registers.h"
#include "BIT_MATH.h"

void keypad_init(void);
char keypad_get_value(void);

#endif /* KEYPAD_H_ */