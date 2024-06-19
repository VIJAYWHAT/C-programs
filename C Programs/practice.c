#include <stdio.h>

int sum(){ 
    
    int a,b;
    printf("enter two numbers: ");
    scanf("%d %d",&a,&b);
    return a+b;
} 

void end(){
    printf("The program was ended!\n");
}

int main(){
    
    printf("Sum of two digits: %d",sum());
    

    
}
    