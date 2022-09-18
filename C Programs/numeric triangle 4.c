#include <stdio.h>

int main()
{

    int i,j,num,k;


     printf("enter the number:");
     scanf("%d",&num);


    for(i=1;i<=num;i++){
      
        for(j=i;j<=num;j++) {
        printf(" ");

    }
    
    for(k=i;k>=1;k--){
        
        
        printf("%d",k);
        
    
    }
    
    printf("\n");
       }
    }
