#include <stdio.h>

int main(){

    int i,j,t=1,rows;

    printf("Enter the Number of n");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++){
        for(j=1;j<=i;j++){
            printf("%d ",t);
            t++;
        }
        printf("\n");

    }
    return 0;
}