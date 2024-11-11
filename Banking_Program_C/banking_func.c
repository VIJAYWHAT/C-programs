#include "bank.h"

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
                system("cls"); // Clear the terminal
                printf("User Logged Successful\n"); // Print msg to ensure the user logged
                bool userLogged = true; // assign userLogged into true to check the user 
                userDetails(userLogged,userIndex); // call the userDetails function to move further option
            }
            else
            {
                printf("Password Wrong!\n\n");
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

        UserOptions(); // call UserOptions to print the Options

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nYour Balance is: %.2f\n", balanceCheck(users[UserIndex].account_no)); // De
            break;
        case 2:
           UserProfile(UserIndex);
            break;
        case 3:
            printStatment(users[UserIndex].account_no);
            break;
        case 4:
            deposit(users[UserIndex].account_no); 
            break;  
        case 5:
            withdraw(users[UserIndex].account_no, UserIndex);
            break;
        default:
            printf("Invalid Option\n");
            break;
        }
        
    cont_check:
        printf("\nContinue (C)/ Logout(L): ");
        scanf(" %c", &cont);

        if(cont == 'C' || cont == 'c'){
            system("cls");
            userDetails(UserLogged,UserIndex); // Recursion Function
        }
        else if(cont == 'L' || cont == 'l') 
            logout();
        else{
            printf("Invalid Input\n");
            goto cont_check;
        }
    }
}

void UserOptions(){

    printf("--- User Menu ---\n");
    printf("1. Check Bank Balance.\n");
    printf("2. View User Details.\n");
    printf("3. Check account statement\n");
    printf("4. Deposit Money.\n");
    printf("5. Withdraw Money.\n");

}

void UserProfile(int UserIndex){
    
    system("cls");
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
        system("cls");
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

    sprintf(filename, "./ac_statements/%d.txt",ac_no); // concat the string and int

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
    
    sprintf(filename, "./ac_statements/%d.txt", ac_no); // concat the string and int

    FILE *st = fopen(filename, "r"); // also we directly open the file in the FILE declaration
    printf("\n");

    if(st == NULL) perror("No statement Available"); // Check if the file exists or not
    
    while(fgets(statement, sizeof(statement), st)){
        printf("%s", statement);
    }
    
}

void deposit(int ac_no){

    int amount;
    char confirm;

    printf("Enter the amount you want to deposit: ");
    scanf("%d", &amount);
    system("cls");

    printf("Are you sure want to deposit %d? (y/n): ", amount);
    scanf(" %c", &confirm);
    system("cls");

    if(confirm == 'y' || confirm == 'Y'){
        
        bool deposited = depositPrint(ac_no, amount);

        if(deposited)
            printf("Amount deposited successfully\n");
        else
            printf("Deposit failed\n");
    }
    else
        printf("Deposit cancelled\n");
}

void withdraw(int ac_no, int userIndex){
    int amount, TryPass = 0;
    float balance;
    char confirm, password[Length];
    balance = balanceCheck(ac_no);

CashWithdraw:
    system("cls");
    printf("Your Balance is: %.2f\n", balance);
    printf("Enter the amount you want to withdraw: ");
    scanf("%d", &amount);
    system("cls");

    if(amount <= balance){
        printf("Are you sure want to withdraw %d? (y/n): ", amount);
        scanf(" %c",&confirm);

        if(confirm == 'y' || confirm == 'Y'){
            printf("\nEnter the \"Password\" to Confirm Withdraw \n");
        
        password:
                printf("Enter your password: ");
                scanf("%s", &password);

                if (strcmp(users[userIndex].password, password) == 0) // strcmp == 0 used to compare two string
                {
                    system("cls");
                    bool withdrawed = withdrawPrint(ac_no, amount);

                    if(withdrawed)
                        printf("Withdrawal Successful\n");
                    else
                        printf("Withdraw failed");
                }
                else
                {   
                    
                    printf("Password Wrong! Try Again... \n\n");
                    TryPass++; // TryPass variable used to count the given wrong passwords 
                    if(TryPass == 4){
                        printf("You have exceeded the number of attempts!!!\n");
                        exit(1); // used to terminate the entire program
                        
                    }
                    goto password; // used to go for the particular label line 
                }
        }
        else
            printf("Withdraw cancelled\n");
    }
    else
        printf("Insufficient Balance\n");
    
}


bool depositPrint(int ac_no, int amount){

    char filename[55];
    FILE *dp;

    sprintf(filename, "./ac_statements/%d.txt", ac_no);

    dp = fopen(filename, "a"); // append the file
    if (dp == NULL) {
        perror("Error opening file");
        return false;
    }
    int balance = balanceCheck(ac_no) + amount;

    fprintf(dp, "%s\tDeposit\t\t    Credit\t\t%d  \t    %d\n", getCurrentDate(), amount, balance);

    fclose(dp);
    return true;

}

bool withdrawPrint(int ac_no, int amount){

    char filename[55];
    FILE *dp;

    sprintf(filename, "./ac_statements/%d.txt", ac_no);

    dp = fopen(filename, "a"); // append the file
    if (dp == NULL) {
        perror("Error opening file");
        return false;
    }
    int balance = balanceCheck(ac_no) - amount;

    fprintf(dp, "%s\tWithdrawal\t    Debit\t\t%d  \t    %d\n", getCurrentDate(), amount, balance);
    
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