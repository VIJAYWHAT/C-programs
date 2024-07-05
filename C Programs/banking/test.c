#include <stdio.h>
#include <time.h>

int main() {
    time_t t;
    struct tm *tmp;
    char buffer[80];

    // Get the current time
    time(&t);
    tmp = localtime(&t);

    // Format the date
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", tmp);
    printf("Current date: %s\n", buffer);

    return 0;
}
