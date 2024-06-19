#include <stdio.h>
// Reading operation in file handling 

int main(){

    FILE *fp; // Declare the file Pointer
    char c[100],c1;


    fp = fopen("test.txt","r+w"); // Open the file in "read" Mode
   
    // c1 = fgetc(fp); // get the single char from the file fp and store in variable "c1" 
    // printf("%c \n",c1); // print the char

    fgets(c,10,fp); // get the 10char count string from the file fp and store in variable "c"  
    printf("%s",c); // print the string (Hello Wor) only 9char print(bcuz this get n-1 size)

    fclose(fp);
return 0;
}