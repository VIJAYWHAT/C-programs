#include <stdio.h>

void main(){

    int i,j,t,n,a[10];

    printf("Enter the number of N:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("Enter Number %d:",i);
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){

        if(a[i] > a[j]){
            
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            
            }
        }
    }


    printf("Ascending Order of Givem Number: ");
    for(i=1;i<=n;i++){
        printf("%d ",a[i]);
        
    }

}