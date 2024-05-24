#include <stdio.h> // Header file

void main(){ // main function with no returns

    int i,j,k,s,rows; 

    printf("Enter the Number of rows: "); // print function for display and getting input from the user
    scanf("%d",&rows); // scan function for getting input from the user

    for(i=1;i<=rows;i++){ // parent loop 
        for(j=1;j<=(rows-i);j++) // child loop
            printf("  "); // print space for triangle comes center

        s = (i*2) - 1; // s to calculate the rows to print

    for(k=1;k<=s;k++){ // k loop for print the star
            printf(" *");
    }
    printf("\n\n");
    }
}