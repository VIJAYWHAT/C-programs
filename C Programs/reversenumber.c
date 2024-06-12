#include <stdio.h>

int main() {
 int num,copy,rev=0;
 
 printf("enter the number:");
 scanf("%d",&num);
 
 copy = num;
 
 while(copy > 0){
     
    rev = rev * 10;
    rev = rev + (copy%10);
    copy /= 10;
     
 }
 
 printf("reverse number:%d",rev);

    return 0;
}  