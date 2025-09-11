#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUFMAX 32768

int mul(int n1, int n2) {
    return n1*n2;
}

int main() {
    FILE *input;
    char file[BUFMAX]={0};
    char doExec[] = "do()";
    char doNotExec[] = "don't()";
    int totalCount=0;
    int n1,n2,charsRead;
    bool exec = true;
    
    input=fopen("input.txt","r");
    if (input==NULL) return 1;
    fread(file,1,BUFMAX,input);

    for (char *filePos = file; filePos < file+BUFMAX; filePos++) {
        if (memcmp(filePos,doExec,4)==0)
            exec = true;
        else if (memcmp(filePos,doNotExec,7)==0)
            exec = false;
        else if (sscanf(filePos,"mul(%d,%d)%n",&n1,&n2,&charsRead) == 2) {
            if (filePos[charsRead-1] == ')' && exec) {
                totalCount+=mul(n1,n2);
            } 
        }
    }

    printf("Sum of enabled multiplications (challenge 2): %d\n",totalCount);
    //Right answer: 74838033
    fclose(input);
    return 0;
}