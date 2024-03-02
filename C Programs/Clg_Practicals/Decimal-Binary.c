#include <stdio.h>

int main(){

    int num,i,k,a[10];

    printf("Enter the Number:");
    scanf("%d",&num);

    i = 1;

    while(num > 0){
        a[i] = num%2;
        num /= 2;
        i++;
    }
    printf("Before i:%d\n",i);
    i--;
    printf("after i:%d\n",i);

    printf("Binary Number of given number is: ");
    for(k=i;k>0;k--){
        printf("%d",a[k]);
    }

}