#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define Row 3
#define Col 50
#define Length 50

void login();
void userDetails(bool UserLogged, int UserIndex);
void UserProfile(int UserIndex);
void UserOptions();
void printStatment(int ac_no);
float balanceCheck(int ac_no);
void logout();

void welcome(){
    printf("===========================================\n");
    printf("\t Welcome to Banking App \n");
    printf("===========================================\n");

}

struct Users {
    int account_no;
    char user_name[Length];
    char password[Length];
    float balance;
};

struct Users users[] = {
        {127101234, "Vijay", "vijay@123", 120000},
        {127102345, "Gopi", "gopi@123", 15000},
        {127103456, "Ram", "ram@123", 2000000},
        {127104567, "Hari", "hari@123", 10000}
};

void login(){
    char re;
    char username[50];
    char password[50]; 
    int userIndex;
    int usercount = sizeof(users) / sizeof(users[0]);
    int TryPass = 0;
    // printf("Total users: %d\n",usercount);

    login:
        printf("\nEnter the user name: ");
        scanf("%s", username);

        bool userFound = false;
        for (int i = 0; i < usercount; i++) {
            if (strcmp(username, users[i].user_name) == 0) {
                userFound = true;
                userIndex = i;
                break;
            }
        }

        if (userFound) {
            printf("User Found\n");
        password:
            printf("Enter the password: ");
            scanf("%s", &password);

            if (strcmp(users[userIndex].password, password) == 0) {
                printf("User Logged Successful\n");
                bool userLogged = true;
                userDetails(userLogged,userIndex);
            }
            else{
                printf("Password Wrong!\n");
                TryPass++;
                if(TryPass == 4){
                    printf("You have exceeded the number of attempts!!!\n");
                    exit(1);
                    
                }
                goto password;
            }

        } else {
            printf("User Not Found\n");
            printf("Retry (Y/N): ");
            scanf(" %c", &re);
            if(re != 'n' && re != 'N')
                goto login;
            else
                exit(1);
            
        } 

}

void userDetails(bool UserLogged, int UserIndex){
    if(UserLogged){
        int option;
        char cont;

        UserOptions();

        printf("Enter your choice: ");
        scanf("%d", &option);

        if(option == 1){
            printf("\nYour Balance is: %.2f\n", balanceCheck(users[UserIndex].account_no));
        }
        else if(option == 2){
           UserProfile(UserIndex);
        }
        else if(option == 3){
            printStatment(users[UserIndex].account_no);
        }
        else{
            printf("Invalid Option\n");
        }

    cont_check:
        printf("\nContinue (C)/ Logout(L): ");
        scanf(" %c", &cont);

        if(cont == 'C' || cont == 'c')
            userDetails(UserLogged,UserIndex); // Recursion Function
        else if(cont == 'L' || cont == 'l')
            logout();
        else{
            printf("Invalid Input\n");
            goto cont_check;
        }
    }
}

void UserOptions(){

    printf("\n1. Check Bank Balance.\n");
    printf("2. View User Details.\n");
    printf("3. Check account statement\n");
    printf("4. Withdraw Money.\n");
    printf("5. Deposit Money.\n");

}

void UserProfile(int UserIndex){

    printf("\n===================\n");
    printf("***** Profile *****\n");
    printf("===================\n\n");

    printf("User Name: %s\n", users[UserIndex].user_name);
    printf("Account Number: %d\n", users[UserIndex].account_no);
    printf("User Balance: %.2f\n", users[UserIndex].balance);
}

void logout(){
    char check;

    printf("\nYou have successfully logged out.");
    printf("\nLogin(Y) / Exit(N): ");
    while ((getchar()) != '\n'); // Clear the input buffer before using scanf
    scanf("%c", &check);
    
    if(check == 'Y' || check == 'y'){
        login();
    }
    else{
        printf("Thank you for using our services.\n");
        exit(1);
    }
}

float balanceCheck(int ac_no){

    FILE *fp;
    char line[100];
    char *lastWord;
    char *token;
    char filename[50];
    float balance;

    sprintf(filename, "%d.txt",ac_no); 


    fp = fopen(filename, "r");

    if (fp == NULL)
        perror("Account not found");
        
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, " \t\n");

        while (token != NULL) {
            lastWord = token;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    balance = atof(lastWord);

    return balance;

}

void printStatment(int ac_no) {

    char filename[100];
    char statement[255];
    
    sprintf(filename, "%d.txt", ac_no);

    FILE *st = fopen(filename, "r");
    printf("\n");

    if(st == NULL)
        perror("No statement Available");
    

    while(fgets(statement, sizeof(statement), st)){
        printf("%s", statement);
    }
    
}