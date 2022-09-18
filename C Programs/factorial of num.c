#include <stdio.h>

int main(){

    int i,n,fact = 1;

    printf("enter the number :");
    scanf("%d",&n);



    for(i=1;i<=n;i++){

        fact = fact * i;

    }
    printf("factorial:%d \n",fact);

    if(n < 0){ //for only check the number is negative
        printf("number is negative");
    }
}