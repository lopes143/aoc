#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFMAX 32768

int mul(int n1, int n2) {
    return n1*n2;
}

int main() {
    FILE *input;
    char file[BUFMAX]={0};
    char *filePos=file; //is a pointer to the array that goes forward as we read the file
    int totalCount=0;
    int n1,n2,charsRead;
    
    input=fopen("input.txt","r");
    if (input==NULL) return 1;
    fread(file,1,BUFMAX,input);

    while ((filePos = strstr(filePos,"mul(")) != NULL) {
        if (sscanf(filePos,"mul(%d,%d)%n",&n1,&n2,&charsRead) == 2) {
            if (filePos[charsRead-1] == ')' ) {
                totalCount+=mul(n1,n2);
            } 
        }
        filePos++;
    }

    printf("Sum of multiplications (challenge 1): %d\n",totalCount);
    //Right answer: 170807108
    
    filePos=NULL;
    fclose(input);
    return 0;
}


