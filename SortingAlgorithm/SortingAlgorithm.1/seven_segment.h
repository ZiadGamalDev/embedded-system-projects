#include "Registers.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

void seven_segment_init(void);
void seven_segment_display(int num);
void disply_number(int number);

#endif /* SEVEN_SEGMENT_H_ */