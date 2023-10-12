#include <stdio.h>

void main(){

    int n,s=0,r,t;

    printf("Enter the number: ");
    scanf("%d",&n);

    t = n;

    while(n>0){

        r = n % 10;
        s = (s * 10) + r;
        n = n / 10;
    }

    if(t == s)
        printf("%d is a Palindrome",t);
    else
        printf("%d is not a Palindrome",t);

}