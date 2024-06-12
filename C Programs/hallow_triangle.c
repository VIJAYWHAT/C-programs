#include <stdio.h>
// #include "lab.c"

void main(){

int a,b;

int sum(int num1, int num2){
    return num1 + num2;
}

printf("Enter two numbers: ");
scanf("%d %d",&a,&b);

int result = sum(a,b);

printf("The result is: %d", result);

}