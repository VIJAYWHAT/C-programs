#include<stdio.h>

void main()
{
    int n,i=1,k=0;
    
    printf("\n Enter the any number");
    scanf("%d",&n);

    while(i<=n)
    {

    if(n%i==0)
    k++; 
    i++; 

    }

    if(k==2) 
    printf("%d is a prime number",n);
    
    else
    printf("%d is a not prime number",n);
    
}

