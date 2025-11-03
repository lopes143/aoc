#include "dec04.h"

bool check_horizontal(char list[][140], int row, int col) {
    if (col > COLUMNS-4) return false;

    char word[5]={0}; //it has to include '\0'
    for (int i=0; i<4; i++)
        word[i]=list[row][col+i];
    //printf("%s\n",word);
    return (!strcmp(word,"XMAS") || !strcmp(word,"SAMX"));
}

bool check_vertical(char list[][140], int row, int col) {
    if (row > ROWS-4) return false;
    
    char word[5]={0};
    for (int i=0; i<4; i++)
        word[i]=list[row+i][col];
    //printf("%s\n",word);
    return (!strcmp(word,"XMAS") || !strcmp(word,"SAMX"));
}

bool check_diagonal(char list[][140], int row, int col) {
    if (col > COLUMNS-4 || row > ROWS-4)
        return false;

    char word[5]={0};
    for (int i=0; i<4; i++)
        word[i]=list[row+i][col+i];
    //printf("%s\n",word);
    return (!strcmp(word,"XMAS") || !strcmp(word,"SAMX"));
}

bool check_anti_diagonal(char list[][140], int row, int col) {
    if (col < 3 || row > ROWS-4) return false;

    char word[5]={0};
    for (int i=0; i<4; i++)
        word[i]=list[row+i][col-i];
    //printf("%s\n",word);
    return (!strcmp(word,"XMAS") || !strcmp(word,"SAMX"));
}

bool x_mas(char list[][140], int row, int col) {
    // 1 . .    . . 3
    // . 2 .    . 2 .
    // . . 3    1 . .
    if (col > COLUMNS-3 || row > ROWS-3)
        return false;

    char word1[4]={0},word2[4]={0};
    for (int i=0; i<3; i++) {
        word1[i]=list[row+i][col+i];
        word2[i]=list[row+i][col+2-i];
    }
    bool w1=!(strcmp(word1,"MAS") && strcmp(word1,"SAM"));
    bool w2=!(strcmp(word2,"MAS") && strcmp(word2,"SAM"));

    return w1 && w2;
}