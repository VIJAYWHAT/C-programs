#include <stdio.h>

int main(){

int i,j,k,r,s,t=1;

printf("Enter the number of rows:");
scanf("%d",&r);

for(i=1;i<=r;i++){
    for(j=1;j<=(r-i);j++)
    printf("  ");

        s=(2*i)-1;
        for(k=1;k<=s;k++){

        if(t<10)
        printf(" %d",t);

        else
        printf("%d ",t);
        t++;

        }
        printf("\n");
}
return 0;

}