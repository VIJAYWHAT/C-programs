#include <stdio.h>

int main()
{

    int i,j,num,t=1;

     printf("enter the number:");
     scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++) {
        printf("%d ",t);
        t++;
        }
    printf("\n");
    }
}
