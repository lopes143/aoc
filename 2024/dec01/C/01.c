#include "dec01.h"

int main(void) {
    int id1[NUM_LINES];
    int id2[NUM_LINES];
    int totalDist=0;

    parse_input(id1, id2);

    qsort(id1,NUM_LINES,sizeof(id1[0]),compare);
    qsort(id2,NUM_LINES,sizeof(id2[0]),compare);

    for (int i=0; i<NUM_LINES; i++)
        totalDist+=abs(id1[i]-id2[i]);

    printf("Total Distance (challenge 1): %d\n", totalDist);
    //Right answer: 1580061

    return 0;
}