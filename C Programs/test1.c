#include <stdio.h>

int a = 100;

void function(){
    a = 10;
    printf("a in function: %d\n",a);
    a = 50;
}

int main(){
    function();
    printf("a in main: %d",a);
    return 0;
}