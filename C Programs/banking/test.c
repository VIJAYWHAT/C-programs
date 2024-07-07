#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Assuming banking_func.h contains the declaration for getCurrentDate()


char*  getCurrentDate(); 
void printStatment();

int main() {
    char filename[55];
    FILE *dp;

    strcpy(filename, "127103456.txt");
    int amount = 500;
    int balance = 1500;

    dp = fopen(filename, "a"); // append the file
    if (dp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fprintf(dp, "%s\tDeposit\t\t    Credit\t\t%d  \t    %d\n", getCurrentDate(), amount, balance);

    fclose(dp);
    printStatment();
    return EXIT_SUCCESS;
}

void printStatment()
{   

    system("cls");
    char filename[55];
    char statement[100];
    
    // sprintf(filename, "%d.txt", ac_no);

    FILE *st = fopen("127103456.txt", "r"); // also we directly open the file in the FILE declaration
    printf("\n");

    if(st == NULL) perror("No statement Available");
    
    while(fgets(statement, sizeof(statement), st)){
        printf("%s", statement);
    }
    
}

char* getCurrentDate() { // Function with return value and No Parameter
    static char date[80];  // Static array to hold the date string
    time_t t = time(NULL);
    struct tm *tmp = localtime(&t);
    
    strftime(date, sizeof(date), "%d-%m-%Y", tmp);
    return date;
}