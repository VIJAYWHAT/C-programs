#include <stdio.h>
int main(){
    int num;
    printf("enter the number: ");
    scanf("%d",&num);
    
    if(num>0)
    {
        printf("positive");
    }
    else if(num == 0)
    {
        printf("num is 0");
    }
    else if(num<0){
        printf("negative");
    }
    else
    {
        printf("non");
    }
return 0;
}