#include<stdio.h>
 
int main() {
    int i, j, rows,k;
    int count = 1;
 
    printf("Enter the number of rows\n");
    scanf("%d", &rows);
 
    for (i = 1; i < rows; i++) {
        for (j = 0; j <= i; j++) {
        printf(" ");
        }

        for(k=i;k>=1;k--){
            printf("%d ", count);
            count = !count;
        }
        count = i % 2;
        printf("\n");
    }
    return(0);
}