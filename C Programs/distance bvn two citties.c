#include <stdio.h>

int main (){
    float km,m,cm,ft,inch;

    printf("enter the distance in kilometers: ");

    scanf("%f",&km);
    
    m = km*1000;
    cm = m * 100;
    inch = cm/2.54;
    ft = inch/12;

    printf("distance in meter = %f\n",m);
    printf("distance in centimeter = %f\n",cm);
    printf("distance in feet = %f\n",ft);
    printf("distance in inches = %f\n",inch);

    return 0;
}