#include <stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    if( scanf("%d", &n) == 1 ){
        printf("You entered: %d\n", n);
    }
    else{
        printf("Input in not a Integer");
    }

}