#include "dec04.h"

int main() {
    FILE *file;
    char input[ROWS][COLUMNS] = {0};
    int r=0,c=0;
    char ch;

    file=fopen("../input.txt","r");
    if (file==NULL) return 1;
    
    //prepare 2D array
    while ((ch = fgetc(file)) != EOF && r<ROWS) {
        if (ch == '\n') {
            r++;
            c=0;
        }
        else {
            input[r][c]=ch;
            c++;
        }
    }

    int XmasCount=0;

    for (int linh=0; linh < ROWS; linh++)
        for (int coln=0; coln < COLUMNS; coln++)
            if (x_mas(input, linh, coln)) XmasCount++;

    printf("X-MAS Count (challenge 2): %d\n", XmasCount);
    //Right answer: 1854
    
}