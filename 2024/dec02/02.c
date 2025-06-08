#include <stdio.h>
#include <stdlib.h>
#define NUM_LIN 1000
#define BUFMAX 100
#define NUM_VAL 8 //max number of values each line have

int check_line(int *line, int num) {
    int safe=1; //change to 0 if something is unsafe
    int signal;
    if (line[1]-line[0]>0) signal=1;
    else if (line[1]-line[0]<0) signal=-1;
    else return 0; //if first two values are equal, it's not safe

    for (int i=1; i<num; i++) {
        int delta=line[i]-line[i-1];
        /* Fail if sequence doesn't follow increase/decrease
        or delta isn't a safe value*/
        if (delta*signal<0 || abs(delta)>3 || abs(delta)<1) {
            safe=0;
            break;
        }
    }
    return safe;
}

void remove_line_elem(int *line, int *num, int index) {
    for (int i=index; i<*num-1; i++) {
        line[i]=line[i+1];
    }
    line[*num-1]=0; //last element is 0
    (*num)--; //decrease number of elements
}   

int main(void) {
    FILE *input;
    char line[BUFMAX];
    int safeLines=0;

    input=fopen("input.txt", "r");
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