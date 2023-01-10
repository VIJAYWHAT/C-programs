#include <stdio.h>

int main(){

    float bp,da,hra,grpay;

    printf("\nenter the basic salary of ramesh:");
    scanf("%f",&bp);

    da=0.4 * bp;
    hra = 0.2 * bp;
    grpay = bp + da + hra;

    printf("basic salary of ramesh = %f\n",bp);
    printf("dearness allowance = %f\n",da);
    printf("house rent allowance = %f\n",hra);
    printf("gross pay of ramesh is %f\n",grpay);

}