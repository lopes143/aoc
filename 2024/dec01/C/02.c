#include "dec01.h"

int main(void) {
    int id1[NUM_LINES];
    int id2[NUM_LINES];
    int appearance=0, timesFound=0;

    parse_input(id1, id2);

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