/*
 * Write a program to print all input lines that are longer than 80 chars
 * */

#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define LOWERBOUND 80

int my_get_line(char line[], int maxline); /*already a getline on system; so, renamed*/
void copy(char to[], char from[]);
int get_length(char longest[]);
void print_longest(char longest[]);

/*print longest input line*/
int main()
{
  int len;                /*current line length*/
  int max;                /*max length seen so far*/
  char line[MAXLINE];     /*current input line*/
  char longest[MAXLINE];  /*longest line saved here*/
  int e;

  max = 0;
  while ((len = my_get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /*there was a line*/
    if (get_length(longest) < LOWERBOUND) {
      printf("\n");
      print_longest(longest);
      printf("\nlength of longest sentence: %d\n", get_length(longest));
    }

  return 0;
}

/*getline: read a line into s, return length*/
int my_get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int get_length(char longest[]) /*get length of line*/
{
  int l;
  for (l = 0; ; ++l) {
    if (longest[l] == '\n') {
      return l;
    }
  }
}

void print_longest(char longest[]) /*print length of longest line*/
{
  int l;
  int stop = 0;
  for (l = 0; stop == 0; ++l) {
    if (longest[l] != '\n' && longest[l] != '\0') {
      printf("%c", longest[l]);
    } else if (longest[l] == '\n' || longest[l] == '\0' || longest[l] == '0') {
      stop = 1;
    }
  }
  return;
}

/*copy: copy 'from' into 'to'; assume to is big enough*/
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\n')
    ++i;
}

