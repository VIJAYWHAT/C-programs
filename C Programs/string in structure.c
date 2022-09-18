
#include <stdio.h>
#include <string.h>

// Create a structure called myStructure
struct mystructure{ // Structure declaration
    char String[30]; // String
};// End the structure with a semicolon

int main() {
     // Create a structure variable of myStructure called s1
struct mystructure s1;

// Assign a value to the string using the strcpy function
 strcpy(s1.String, "Hello Vijay");

// Print values
printf("my string: %s",s1.String);

    return 0;
}