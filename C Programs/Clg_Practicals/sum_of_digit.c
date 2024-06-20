#include <stdio.h>

void main(){

    int n,s=0,r,n1=0;

  
    printf("Enter the Number: ");
    scanf("%d",&n);
    
    n1 = n;
    
    while(n>0){
        r = n % 10;
        s = s + r;
        n = n / 10;
    }

    printf("Sum of Digit of %d is %d",n1,s);

}