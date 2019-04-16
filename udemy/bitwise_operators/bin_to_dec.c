/*
 * math library not linked? https://stackoverflow.com/questions/12824134/undefined-reference-to-pow-in-c-despite-including-math-h
 *
 * running into trouble with undefined refernce to pow
 *
 * gcc -o sphere sphere.c -lm // stackoverflow command
 *
 * */


#include <stdio.h>
#include <math.h>     // pow()
#include <string.h>   // strlen()

#define STR32 33 // 32-bit binary value + terminating character

int BinToDec (char *);

int main (int argc, char* argv[]) {
  char ch = 0;
  char cBinArray[STR32] = {0};
  do {
    printf("Enter the binary number to be converted to decimal: ");
    // limit length of input to STR32
    fgets(cBinArray, STR32, stdin);
    // clear '\n' from array
    cBinArray[strlen(cBinArray) - 1] = '\0';
    printf("Decimal value of %s is: %d\n", cBinArray, BinToDec(cBinArray));
    printf("\n\nPress 'q' to quit... OR \nPress ANY key to continue...\n");
    ch = getchar();
    fseek(stdin, 0, SEEK_END);
  } while (ch != 'q');
  return 0;

}

int BinToDec(char *buffer) {
  int i = 0;               // iterator
  int positionalValue = 0; // length of string buffer
  int decVal = 0;          // decimal value

  // get length to the buffer minus the terminating character, NULL
  positionalValue = strlen(buffer) - 1;
  while (buffer[i] != '\0') {
    if (buffer[i++] == '1') {
      decVal += pow(2, positionalValue);
    }
    positionalValue--;
  }
  return decVal;
}
