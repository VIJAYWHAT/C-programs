#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *lastWord;
    char *token;

    fp = fopen("127101234.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        token = strtok(line, " \t\n");

        while (token != NULL) {
            lastWord = token;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    printf("Last word: %s\n", lastWord);

    return EXIT_SUCCESS;
}
