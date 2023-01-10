#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
    //....add other stuff later,maybe
} person;

unsigned int hash(char *name){
    return 5;
}

int main() {
    printf("vj => %u\n",hash("vj"));
    printf("goushik => %u\n",hash("goushik"));
    printf("ashraf => %u\n",hash("ashraf"));
    printf("gopi => %u\n",hash("gopi"));

    return 0;
}
