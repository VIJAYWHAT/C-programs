#include <stdio.h>

int main() {

    int i,j,n,print=0;

    printf("enter the number:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            print++;
            printf("%d ",print);
        }
        printf("\n");

    }
}