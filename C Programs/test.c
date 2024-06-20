#include <stdio.h>

int main(void) {
   
    FILE *file;
    char c;
    file = fopen("test.txt","a");

    // fputs("\nI am Vj!",file);
    fprintf(file,"\nHi vijay,How can i help you ?");

    printf("file writed");

    fclose(file);

    return 0;
}