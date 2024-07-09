#include <stdio.h>

int main(){
    FILE *fp = fopen("./ac_statements/127101234.txt","r");
    char c[100];
    fgets(c, 100, fp);

    if(fp == NULL)
        printf("Error");
    
    printf("%s", c);
    
    return 0;
}