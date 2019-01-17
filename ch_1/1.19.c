/*
 * Write a function that reverses the character string s. Use it to write a program that reverses its input a line at a time.
 * */

#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

void mygetline(char line[], int maxline);
void reverseline(char line[]);
int linelength(char line[]); // gets line length

void main()
{
  char line[MAXLINE], reversed_line[MAXLINE];
  mygetline(line, MAXLINE);
  reverseline(line);
  return;
}

// creates a char arr
void mygetline(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i){
    s[i] = c;
  }
  s[i] = '\0';
  return;
}

// prints chars of a line in reverse
void reverseline(char line[])
{
  int index, increment;
  printf("\n");
  for (index = linelength(line); index >= 0; --index){
    printf("%c", line[index]);
  }
  printf("\n");
  return;
}

// takes in a line, finds its null char index, and returns it
int linelength(char line[])
{
  int index;
  for (index = 0; line[index] != '\0'; ++index){
    ;
  }
  return index;
}
