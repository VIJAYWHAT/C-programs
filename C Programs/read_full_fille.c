#include <stdio.h>

int main() {
    FILE *fp;
    char string[100];

    fp = fopen("test4.txt", "r");
    if (fp == NULL) {
        printf("Could not open file for reading.\n");
        return 1;
    }

    printf("Contents of the file:\n");

    // Read and print each line until end of file
    while (fgets(string, sizeof(string), fp) != NULL) {
        printf("%s", string);
    }

    fclose(fp); // Close the file

    printf("\nFile read successfully.\n");
    return 0;
}
