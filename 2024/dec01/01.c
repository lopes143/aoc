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
    int totalDist=0;

    input = fopen("input.txt", "r");
    if (input==NULL) return 1;

    //process input
    for (int i=0; i<NUM_LINES; i++)
        if (fscanf(input, "%d %d", &id1[i], &id2[i])!=2) return 1;

    //sort arrays - Bubble Sort
    sort_arrays(id1);
    sort_arrays(id2);

    for (int i=0; i<NUM_LINES; i++)
        totalDist+=abs(id1[i]-id2[i]);

    printf("Total Distance (challenge 1): %d\n", totalDist);
    //Right answer: 1580061
    
    fclose(input);
    return 0;
}