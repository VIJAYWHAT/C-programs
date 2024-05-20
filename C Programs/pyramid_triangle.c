#include <stdio.h>

void main(){

    int i,j,k,s,rows,t=1;

    printf("Enter the Number of rows: ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++){
        for(j=1;j<=(rows-i);j++)
            printf("  ");

        s = (i*2) - 1;

    for(k=1;k<=s;k++){

        if(t<10)
            printf(" %d",t);
        else
            printf("%d ",t);
        t++;
    }
    printf("\n\n");
    }
}