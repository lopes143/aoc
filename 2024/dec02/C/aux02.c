#include "dec02.h"

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