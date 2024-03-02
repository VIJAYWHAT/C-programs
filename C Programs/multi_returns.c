#include <stdio.h>

typedef struct
{
  int doubled,cubed;
}number_range;


void calculate(int num,int* doubled,int *cubed) {
  
  *doubled = num * num;
  *cubed = num * num * num;

}

number_range calculate2(int num){

  number_range number;
  number.doubled = num * num;
  number.cubed = num * num * num;
  return number;
}

int main(){

  int num = 10;

  number_range nr;
  int doubled , cubed;
  calculate(num,&doubled, &cubed);
  nr = calculate2(num);

  printf("The number using pointer: %d %d\n",doubled, cubed);
  printf("The number using structure: %d %d",nr.doubled,nr.cubed);

  return 0;
}