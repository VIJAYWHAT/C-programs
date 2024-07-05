#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants or macros
#define Length 55 
#define MaxLength 255

// Function Declarations
void welcome(); 
void login();
void userDetails(bool UserLogged, int UserIndex);
void UserProfile(int UserIndex);
void UserOptions();
void printStatment(int ac_no);
float balanceCheck(int ac_no);
void deposit(int ac_no);
bool depositPrint(int ac_no, float amount);
void logout();

struct Users { // create a structure for store the user credential
    int account_no;
    char user_name[Length];
    char password[Length];
};

struct Users users[] = { // call the struct to assign the values
    {127101234, "Vijay", "vijay@123"},
    {127102345, "Gopi", "gopi@123"},
    {127103456, "Ram", "ram@123"},
    {127104567, "Hari", "hari@123"}
};

// Function definition
void welcome(){ // Function without parameter and no return value
    printf("===========================================\n");
    printf("\t Welcome to Banking App \n");
    printf("===========================================\n");
}

void login()
{
    
    char re;
    char username[Length];
    char password[Length]; 
    int userIndex;
    int usercount = sizeof(users) / sizeof(users[0]); // calculate the usercount
    int TryPass = 0;
    // printf("Total users: %d\n",usercount);

    login: // create label for goto
        printf("\nEnter the user name: ");
        scanf("%s", username);

        bool userFound = false;
        for (int i = 0; i < usercount; i++) {
            if (strcmp(username, users[i].user_name) == 0) { // users[i].user_name used to call the username in the index i 
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

            if (strcmp(users[userIndex].password, password) == 0) // strcmp == 0 used to compare two string
            {  
                system("cls");
                printf("User Logged Successful\n");
                bool userLogged = true;
                userDetails(userLogged,userIndex);
            }
            else
            {
                printf("Password Wrong!\n");
                TryPass++; // TryPass variable used to count the given wrong passwords 
                if(TryPass == 4){
                    printf("You have exceeded the number of attempts!!!\n");
                    exit(1); // used to terminate the entire program
                    
                }
                goto password; // used to go for the particular label line 
            }

        }

        else {
            printf("User Not Found\n");
            printf("Retry (Y/N): ");
            scanf(" %c", &re);

            if(re != 'n' && re != 'N')
                goto login;
            else
                exit(1);   
        }
}

void userDetails(bool UserLogged, int UserIndex){ // Function with parameter and no return value
    if(UserLogged){
        int option;
        char cont;

        UserOptions();

        printf("Enter your choice: ");
        scanf("%d", &option);

        if(option == 1)
            printf("\nYour Balance is: %.2f\n", balanceCheck(users[UserIndex].account_no));
        
        else if(option == 2)
           UserProfile(UserIndex);

        else if(option == 3)
            printStatment(users[UserIndex].account_no);
        
        else if(option == 4)
            deposit(Users[UserIndex].account_no); 

        else
            printf("Invalid Option\n");
        

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
    printf("User Balance: %.2f\n", balanceCheck(users[UserIndex].account_no));
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
        system("cls");
        printf("Thank you for using our services.\n");
        exit(1);
    }
}

float balanceCheck(int ac_no){ // Function with parameter and return value

    FILE *fp; // create a fp FILE pointer to access the files
    char line[MaxLength];
    char *balanceStr;
    char *token;
    char filename[Length];
    float balance;

    sprintf(filename, "%d.txt",ac_no); // concat the string and int

    fp = fopen(filename, "r"); // open the file and assign the address in fp

    if (fp == NULL) // check the file NULL or not
        perror("Account not found"); // display error messages
        
    while (fgets(line, MaxLength, fp) != NULL) {   // Read each line until the end of file

        // Split the line into tokens separated by whitespace
        token = strtok(line, " \t\n"); // used to tokenize (split) strings into smaller tokens based on a delimiter
    
        while (token != NULL) {  // Traverse to the last token in the line
            balanceStr = token;  // Update lastWord to the current token because we give the balance in last
            token = strtok(NULL, " \t\n"); // Get the next token
        }
    }

    fclose(fp); // Close the file

    balance = atof(balanceStr); // convert ascii into float (atoi - convert into int) 

    return balance;

}

void printStatment(int ac_no)
{   

    system("cls");
    char filename[Length];
    char statement[MaxLength];
    
    sprintf(filename, "%d.txt", ac_no);

    FILE *st = fopen(filename, "r"); // also we directly open the file in the FILE declaration
    printf("\n");

    if(st == NULL) perror("No statement Available");
    
    while(fgets(statement, sizeof(statement), st)){
        printf("%s", statement);
    }
    
}

void deposit(int ac_no){

    float amount;
    char confirm;

    printf("Enter the amount you want to deposit: ");
    scanf("%f", &amount);
    system("cls");

    printf("Are you sure you want to deposit %f? (y/n): ", amount);
    scanf("%c", &confirm);
    system("cls");

    if(confirm == 'y' || confirm == 'N'){
        
        bool deposited = depositPrint(ac_no, amount);

        if (deposited)
            printf("Amount deposited successfully\n");
        else
            printf("Deposit failed\n");
    }
    else
        printf("Deposit cancelled\n");

}

bool depositPrint(int ac_no, float amount){

    char filename[Length];
    FILE* dp;

    sprintf(filename, "%d.txt", ac_no);

    if(filename == NULL){
        perror("Account not found");
        return false;
    }

    dp = fopen(filename, "a"); // append the file
    fputs("%s\tDeposit\tCredit\t%d" ,getCurrentDate(), amount);
    
    fclose(dp);
    return true;


}

char* getCurrentDate() { // Function with return value and No Parameter
    static char date[80];  // Static array to hold the date string
    time_t t = time(NULL);
    struct tm *tmp = localtime(&t);
    
    strftime(date, sizeof(date), "%d-%m-%Y", tmp);
    return date;
}