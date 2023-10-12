#include <stdio.h>

void main(){

    int a[10],i,j,t,n;
    printf("Enter the Number of n: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){

        printf("Enter the Number %d: ",i);
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(a[i] > a[j]){

                t = a[i];
                a[i] = a[j];
                a[j] = t;

            }
        
        }
    }

    printf("\nThe Ascending order is: ");

    for(i=1;i<=n;i++){
        printf("%d ",a[i]);
    }

}