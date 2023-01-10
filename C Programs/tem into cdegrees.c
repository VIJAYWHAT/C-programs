#include <stdio.h>

int main(){
    float fr,cent;

    printf("\nEnter the temparature(F):");
    scanf("%f",&fr);

    cent = 5.0 / 9.0 * (fr -32);

    printf("temparature in centigrade = %f\n",cent);

    return 0 ;
}