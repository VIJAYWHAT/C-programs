#include <stdio.h>
#include "lines.c"

void Prime(){

lineb();
printf("\tPrime Number");
line();
//Prime Or Not
int n,k=0,i=1; //Declaring The Variables

printf("Enter the Number:");//Ask the Number From User
scanf("%d",&n);//Scan the Number

while(i<=n){//checking the less the i
        //if the the number is greater than i loop was end

    if(n%i == 0)//checking n%i==0 or not
        k++;//if n%i == 0 k was increament
    i++; //if the loop was entered i was increament

}

if(k==2)//if k = 2 that is a prime number
printf("%d is a prime Number",n);

else//else it is not a prime number
printf("%d is not a Prime Number",n);

}

void SumOfDigit(){

lineb();
printf("\tSum Of Digit");
line();

int n,r,s,n1;

printf("Enter the Number:");
scanf("%d",&n);

n1=n;
s=0;

while(n>0){

    r=n%10;
    s=s+r;
    n=n/10;

}
printf("Sum of Digit of %d is : %d",n1,s);

}

void Palindrome(){

lineb();
printf("\tPalindrome");
line();

int n,t,s,r;

printf("Enter the number:");
scanf("%d",&n);

t=n;
s=0;

while(n>0){

    r=n%10;
    s=(s*10)+r;
    n=n/10;

}

if(t==s)
    printf("%d is a Palindrome",t);
else
    printf("%d is not a palindrome",t);

}

void Rev(){

lineb();
printf("\tReverse The Number");
line();

int n,t,s,r;

printf("Enter the number:");
scanf("%d",&n);

t=n;
s=0;

while(n>0){

    r=n%10;
    s=(s*10)+r;
    n=n/10;

}

printf("Reverse : %d",s);

}

