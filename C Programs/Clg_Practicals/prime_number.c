#include <stdio.h>

void main(){

    int i=1,n,k=0;

    printf("Enter the Number: ");
    scanf("%d",&n);

    while(i<=n){
        if(n%i == 0)
            k++;
        i++;
    }

    if(k==2)
        printf("Prime Number");
    else
        printf("Not a Prime Number");

}