#include <stdio.h>

int main() {
 int num,copy,rev=0;
 
 printf("enter the number:");
 scanf("%d",&num);
 
 copy = num;
 
 while(copy > 0){
     
     rev = rev*10;
     rev = rev + (copy%10); 
     copy /= 10;
     
 }
 
if(num == rev){

printf("palindrome");


}

else {
    printf("not a palindrome");
}

    return 0;
}