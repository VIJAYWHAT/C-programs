#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define Row 3
#define Col 50
#define Length 50

void welcome(){
    printf("===========================================\n");
    printf("\t Welcome to Banking App \n");
    printf("===========================================\n");

}

struct Users {
    char user_name[Length];
    char password[Length];
    char account_number[Length];
    int balance;
};

bool login(){
    struct Users users[] = {
        {"Vijay", "vijay@123"},
        {"Gopi", "gopi@123"},
        {"Ram", "ram@123"},
        {"Hari", "hari@123"}
    };

    char re;
    char username[50];
    char password[50];
    int userIndex;
    int usercount = sizeof(users) / sizeof(users[0]);
    int TryPass = 0;
    // printf("Total users: %d\n",usercount);

    login:
        printf("Enter the user name: ");
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

        // printf("Continue... (Y/N): ");
        // while ((getchar()) != '\n'); 
        // scanf("%c", &re);

    
}