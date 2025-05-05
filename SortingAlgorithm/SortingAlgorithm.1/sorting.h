#ifndef SORTING_H_
#define SORTING_H_

#include "LCD.h"
#include "keypad.h"
#include "seven_segment.h"
#include <stdio.h>

#define Size 100
int numbers[Size], pos;

void sort_init();
void input_numbers();
void sort();
void display_numbers();


#endif /* SORTING_H_ */