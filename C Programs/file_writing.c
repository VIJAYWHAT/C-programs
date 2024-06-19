#include <stdio.h>

int main(){

    FILE *fp;
    char string[100];

    fp = fopen("test.txt","w+"); // file open with the write and read mode

    fputs("Hello VJ!\nI am Happy to help you today\n",fp); // fputs user to write a string
    rewind(fp); // Reset file pointer to the beginning


    fgets(string,50,fp);
    printf("%s",string);

    fclose(fp); // close the file
    printf("File Writed successful");
    return 0;

}