#include <stdio.h>

int main() {

int num1,num2;
char op;
    
    printf("enter the number1 :");
    scanf("%d",&num1);
    
    printf("enter the operator :");
    scanf("\n %c",&op);    
    
    printf("enter the number2:");
    scanf("%d",&num2);
    
    if(op == '+'){
        printf("sum:%d + %d = %d",num1,num2,num1+num2);
    }
    else if(op == '-'){
        printf("sum:%d - %d = %d",num1,num2,num1-num2);
    }
    else if(op == '*'){
        printf("sum:%d * %d = %d",num1,num2,num1*num2);
    }
    else if(op == '/'){
        printf("sum:%d / %d = %d",num1,num2,num1/num2);
    }
    else{
    printf("invaild operator");
}
    
    return 0;
}