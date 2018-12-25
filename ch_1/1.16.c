/*
 * Revise the main routine of the longest-line program (pg. 30) so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of the text.
 * */

#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

int mygetline(char line[], int maxline); /*already a getline on system; so, renamed*/
void copy(char to[], char from[]);
int getlength(char longest[]);

/*print longest input line*/
int main()
{
  int len;                /*current line length*/
  int max;                /*max length seen so far*/
  char line[MAXLINE];     /*current input line*/
  char longest[MAXLINE];  /*longest line saved here*/

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /*there was a line*/
    printf("length of longest sentence: %d\n", getlength(longest));
    return 0;
}

/*getline: read a line into s, return length*/
int mygetline(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int getlength(char longest[]) /*print length of longest line*/
{
  int l;
  for (l = 0; ; ++l) {
    printf("char %c\n", longest[l]);
    if (longest[l] == '\n') {
      return l; // arrays 0-indexed
    }
  }
}

/*copy: copy 'from' into 'to'; assume to is big enough*/
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\n')
    ++i;
}

