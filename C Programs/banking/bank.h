#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants or macros
#define Length 55 
#define MaxLength 255

struct Users { // create a structure for store the user credential
    int account_no;
    char user_name[Length];
    char password[Length];
};

// Function Declarations
void welcome(); 
void login();
void UserOptions();
char* getCurrentDate();
void userDetails(bool UserLogged, int UserIndex);
void UserProfile(int UserIndex);
void printStatment(int ac_no);
float balanceCheck(int ac_no);
void deposit(int ac_no);
void withdraw(int ac_no, int UserIndex);
bool depositPrint(int ac_no, int amount);
bool withdrawPrint(int ac_no, int amount);
void logout();

#endif
