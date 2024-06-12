#include <stdio.h>



int fact(int n){

    if(n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

void main(){

    int num = 4;
    printf("The factorial of %d is: %d",num,fact(num));

}