#include <stdio.h>

int main(){

    // Method 1 
    char name[] = "Vijay Raja";
    printf("String: %s\n", name);
    printf("String with minimum width: %20s\n", name);
    printf("String with left alignment: %-20s\n", name);
    printf("String with precision (first 5 chars): %.5s\n", name);

    // Method 2
    char dept[50];
    printf("Enter the Dept: ");
    scanf("%s",dept);
    printf("Hello, %s\n", dept);

    // Method 3
    getchar();
    char clg[50];
    printf("Enter the College Name: ");
    // MAX Size if 50 defined
    fgets(clg, 50, stdin);
    printf("String is: ");
    // Displaying Strings using Puts
    puts(clg);

    // Method 4
    char str[50];
    printf("Enter a line of text: ");
    gets(str);  // Unsafe, do not use in real programs
    printf("You entered: %s\n", str);


    // Method 5
    char str2[50];
    printf("Enter a line of text: ");
    scanf("%49[^\n]", str2);  // Read until newline, limit to 49 characters
    // scanf("%[^\n]c", str2);
    printf("You entered: %s\n", str2);

    return 0;
}





