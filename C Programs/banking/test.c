#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Assuming banking_func.h contains the declaration for getCurrentDate()

char*  getCurrentDate
int main() {
    char filename[55];
    FILE *dp;

    strcpy(filename, "127101234.txt");
    int amount = 500;
    int balance = 1500;

    dp = fopen(filename, "a"); // append the file
    if (dp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fprintf(dp, "%s\tDeposit\tCredit\t%d\t%d\n", getCurrentDate(), amount, balance);

    fclose(dp);

    return EXIT_SUCCESS;
}


char* getCurrentDate() { // Function with return value and No Parameter
    static char date[80];  // Static array to hold the date string
    time_t t = time(NULL);
    struct tm *tmp = localtime(&t);
    
    strftime(date, sizeof(date), "%d-%m-%Y", tmp);
    return date;
}