#include <stdio.h>

int main() {

 int num, sum = 0,a;

 printf("enter the number:");
 scanf("%d",&num);

    while(num > 0)
    {
        a = num % 10; // sum = sum + (n%10)
        sum = sum + a ;
        num = num / 10;
    }   

    printf("sum of digit : %d",sum);
}
