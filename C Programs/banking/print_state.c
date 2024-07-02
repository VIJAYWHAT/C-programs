#include <stdio.h>

void main(){


    FILE* st;
    char statement[255];
    st = fopen("127101234.txt", "r");

    while(fgets(statement,sizeof(statement), st) != NULL) {
        printf("%s", statement);
    }
}