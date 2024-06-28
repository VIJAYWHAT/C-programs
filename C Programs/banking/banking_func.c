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
    // printf("Total users: %d\n",usercount);

    do {
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
            printf("Enter the password: ");
            scanf("%s", &password);

            if (strcmp(users[userIndex].password, password) == 0) {
                printf("User Logged Successful\n");
            }
            else{
                printf("Password Wrong!\n");
            }

        } else {
            printf("User Not Found\n");
        }

        printf("Continue... (Y/N): ");
        while ((getchar()) != '\n'); 
        scanf("%c", &re);

    } while (re != 'n' && re != 'N');
}