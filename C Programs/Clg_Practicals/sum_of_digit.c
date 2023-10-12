#include <stdio.h>

void main(){

    int n,s=0,r,n1;

    printf("Enter the Number: ");
    scanf("%d",&n);

    while(n>0){
        r = n % 10;
        s = s + r;
        n = n / 10;
    }

    printf("Sum of Digit: %d",s);

}