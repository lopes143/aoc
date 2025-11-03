#ifndef DEC_02
#define DEC_02

#include <stdio.h>
#include <stdlib.h>
#define NUM_LIN 1000
#define BUFMAX 100
#define NUM_VAL 8 //max number of values each line have

int check_line(int *line, int num);

void remove_line_elem(int *line, int *num, int index);

#endif