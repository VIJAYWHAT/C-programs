#include <stdio.h>

int main(){

    FILE *fp;
    char string[100];

    fp = fopen("test4.txt","a+"); // file open with the write and read mode

    if (fp == NULL) {
        printf("Could not open file for writing and reading.\n");
        return 1;
    }

    fputs("Hello VJ!\nI am Happy to help you today\n",fp); // fputs user to write a string
    fprintf(fp,"Hi VJ"); // fprintf also used to write the string
    rewind(fp); // Reset file pointer to the beginning


    fgets(string,50,fp);
    printf("%s",string);


    fclose(fp); // close the file
    printf("File Writed successful");
    return 0;

}