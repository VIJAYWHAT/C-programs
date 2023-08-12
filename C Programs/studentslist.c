#include <stdio.h>
#include <string.h>

int main(){

    int i;
    char names[20][20];
    int num, j;

    printf("Enter the number of students:");
    scanf("%d", &num);

    // Clear the input buffer
    getchar();

    for (i = 0; i < num; i++)
    {
        printf("Enter the %d Student Name:", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);

       names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("Students List:\n");

    for (j = 0; j < num; j++)
    {
        puts(names[j]);
    }

    return 0;
}
