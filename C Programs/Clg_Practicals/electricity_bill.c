#include <stdio.h>

int main(){

int cr,pr,units,netunits,n,cn;
float charges;

printf("\nTAMIL NADU ELECTRICITY BOARD CASH BILL\n\n");

printf("Customer Number: ");
scanf("%d",&cn);

printf("Bill Number: ");
scanf("%d",&n);

printf("Particulars\n");

printf("Current Reading: ");
scanf("%d",&cr);

printf("Previous Reading: ");
scanf("%d",&pr);

units = cr - pr;

printf("The Units consumed by the Customer is %d\n",units);

if(units <= 100){

    charges = (units*1);
}
else if(units > 100 && units <= 200){

    netunits = units - 100;
    charges = (netunits * 2 + 100);

}
else if(units > 200 && units <= 300){

    netunits = units - 200;
    charges = (netunits * 3 + 300);
}
else if(units > 300 && units <= 400){
    
    netunits = units -  300;
    charges = (netunits * 4 + 600);
}
else if(units > 400){

    netunits = units - 400;
    charges = (netunits * 7 + 1000);
}

printf("The charges for the customer is : %f",charges);

}
