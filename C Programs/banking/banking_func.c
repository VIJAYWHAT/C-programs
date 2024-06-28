#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define Row 3
#define Col 50

void welcome(){
    printf("===========================================\n");
    printf("\t Welcome to Banking App \n");
    printf("===========================================\n");

}

bool login(){

    char Users[][Col] = {"Vijay", "Gopi", "Ram", "Hari"};
    char username[50];

    int usercount = sizeof(Users) / sizeof(Users[0]);
    printf("Total users: %d",usercount);
    printf("Enter the user name: ");
    scanf("%s",&username);

    bool userfound = false;
    for(int i = 0; i < Row; i++ ){
        if(strcmp(username, Users[i]) == 0){
            userfound = true;
            break;
        }
    }
    if(userfound){
            printf("User is valid");
    }
    else{
    printf("User is invalid");
    }

}