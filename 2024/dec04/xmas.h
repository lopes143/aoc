#ifndef XMAS
#define XMAS

#define COLUMNS 140
#define ROWS 140

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool check_horizontal(char list[][140], int row, int col);

bool check_vertical(char list[][140], int row, int col);

bool check_diagonal(char list[][140], int row, int col);

bool check_anti_diagonal(char list[][140], int row, int col);

bool x_mas(char list[][140], int row, int col);

#endif