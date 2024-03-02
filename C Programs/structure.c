#include <stdio.h>

// Create a structure called myStructure
struct myStructure {
  int myNum;
  char myLetter;
};

void printing(){
  struct myStructure s1;

  printf("the Number: %d",s1.myNum);
  
}

int main() {
  // Create a structure variable of myStructure called s1
  struct myStructure s1;

  // Assign values to members of s1
  s1.myNum = 16;
  s1.myLetter = 'V';

  // Print values
  printf("My number: %d\n", s1.myNum);
  printf("My letter: %c\n", s1.myLetter);

  printing();

  return 0;
}

