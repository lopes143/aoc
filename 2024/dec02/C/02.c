#include "dec02.h"

int main(void) {
    FILE *input;
    char line[BUFMAX];
    int safeLines=0;

    input=fopen("../input.txt", "r");
    if (input==NULL) return 1;

    while (fgets(line,BUFMAX, input) != NULL) {
        int lineVals[NUM_VAL];
        int count=0;
        char *ptr = line; //line pointer copy
        int charsRead; //number to store how many number chars read (to advance pointer)

        /* When we're reading a line, we read a number each iteration
        and advance the line pointer to read the next one
        */
        while (count<8 && sscanf(ptr,"%d%n",&lineVals[count],&charsRead)==1) {
            count++;
            ptr+=charsRead; //advance line pointer
        }

        if (check_line(lineVals, count)) {
            //line is already safe
            safeLines++;
            continue;
        }
        for (int i=0; i<count; i++) {
            //create a copy of current line (to delete elements)
            int lineCopy[NUM_VAL];
            int countCopy=count;
            for (int j=0; j<count; j++) lineCopy[j]=lineVals[j];
            remove_line_elem(lineCopy, &countCopy, i);
            if (check_line(lineCopy, countCopy)) {
                //Line became safe
                safeLines++;
                break;
            }
        }
            
    }

    printf("Safe Reports after Problem Dampener (challenge 2): %d\n", safeLines);
    //Right answer: 366
    return 0;
}