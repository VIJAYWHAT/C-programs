#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int a,b;
    printf("Enter two Numbers: ");
    scanf("%d %d",&a,&b);
    printf("Number before swap: a = %d, b = %d\n",a,b);
    swap(&a,&b);
    printf("Number after swap: a = %d, b = %d",a,b);
    return 0;
}