#include <stdio.h>

int main(){

    int i,n,fact = 1;

    printf("enter the number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
    fact = fact * i;
    }
    
    if(n < 0){ 
        printf("number is negative!");
    }
    printf("factorial: %d \n",fact);

}