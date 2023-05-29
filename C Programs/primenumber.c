//Type1

    #include <stdio.h>

int main(){
    
    int i,n,flag=0;
    
    printf("enter n:");
    scanf("%d",&n);
    
    for(i=2;i<n;i++){
        
       int r=n%i;
       if(r == 0){
           flag++;
       }
    }
       if(flag == 0){
           printf("%d is a Prime number",n);
           
       }
       else
       printf("%d is not a prime number",n);
    
    return 0; 
}

//Type2

/*#include <stdio.h>

int main(){
    
    int n,i,flag=0;
    
    printf("enter n:");
    scanf("%d",&n);
    
    for(i=2;i<n;i++){
        
        if(n%i != 0){
            continue;
        }
        else{
            flag++;
            printf("not a prime number");
            break;
        }
    }
    if(flag == 0){
        printf("Prime number");
    }
}*/