#include "dec01.h"

void parse_input(int* id1, int* id2) {
    FILE *file;

    file = fopen("../input.txt", "r");
    if (file==NULL) return;

    for (int i=0; i<NUM_LINES; i++)
        if (fscanf(file, "%d %d", &id1[i], &id2[i])!=2) return;

    fclose(file);
}

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

int compare(const void* a, const void* b) {
    int *intA = (int*)a;
    int *intB = (int*)b;
    if (*intA>*intB) return 1;
    else if (*intA<*intB) return -1;
    else return 0;

}