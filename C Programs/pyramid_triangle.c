#include <stdio.h>

void main(){

    int i,j,k,s,rows;

    printf("Enter the Number of rows: ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++){
        for(j=1;j<=(rows-i);j++)
            printf("  ");

        s = (i*2) - 1;

    for(k=1;k<=s;k++){
            printf(" *");
    }
    printf("\n\n");
    }
}