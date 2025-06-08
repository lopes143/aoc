#include <stdio.h>
#include <stdlib.h>
#define NUM_LINES 1000

void sort_arrays(int *array) {
    int i, j, n=NUM_LINES, temp, swapped;
    for (i=0; i<n-1; i++) {
        swapped=0;
        for (j=0; j<n-i-1; j++) {
            if (array[j]>array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swapped=1;
            }
        }
        if (swapped==0) break;
    }
}

int main(void) {
    FILE *input;
    int id1[NUM_LINES];
    int id2[NUM_LINES];
    int appearance=0, timesFound=0;

    input = fopen("input.txt", "r");
    if (input==NULL) return 1;

    //process input
    for (int i=0; i<NUM_LINES; i++)
        if (fscanf(input, "%d %d", &id1[i], &id2[i])!=2) return 1;

    for (int i=0; i<NUM_LINES; i++) {
        for (int j=0; j<NUM_LINES; j++) {
            if (id1[i]==id2[j])
                timesFound+=1;
        }
        appearance += id1[i]*timesFound;
        timesFound=0;
    }

    printf("Similarity score (challenge 2): %d\n", appearance);
    //Right answer: 23046913
    
    return 0;
}