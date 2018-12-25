/*
 * write a program that prints its input one word per line
 * */

#include <stdio.h>

void main()
{
  char ch;

  printf("\n");
  while ((ch = getchar()) != EOF) {
    if (ch != ' ' && ch != '\n' && ch != '\t') {
      putchar(ch);
    } else {
      printf("\n");
    }
  }
}

