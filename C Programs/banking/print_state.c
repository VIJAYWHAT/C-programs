#include <stdio.h>
#include <stdlib.h>

int main() {
    int ac_no = 127101234;
    char filename[100];
    sprintf(filename, "%d.txt", ac_no); // Concatenate integer with ".txt"
    // printf("File Name: %s\n", filename);

    FILE* st;
    char statement[255];
    st = fopen(filename, "r");

    if (st == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(statement, sizeof(statement), st) != NULL) {
        printf("%s", statement);
    }
    
    fclose(st);
    return 0;
}
