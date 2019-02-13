/*
 * Write a program `detab` that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of tab
 * stops, say every n columns. Should n be a variable or a symbolic parameter?
 * */

#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define TABLENGTH 4 /*how many spaces to replace a tab with*/

void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/
void replace_tabs(char line[], char new_line[]);

int main()
{
  int len; /*current line length*/
  char line[MAXLINE]; /*input line*/
  char new_line[MAXLINE]; /*line to be returned*/

  my_get_line(line, MAXLINE);
  replace_tabs(line, new_line);
  print_line(new_line);

  return 0;
}

void replace_tabs(char line[], char new_line[])
{
  int i = 0;
  int k = 0;
  int end = 0; /*this marks ending elm of new_line, which can be longer than line*/

  while (line[i] != EOF) {
    if (line[i] == '\t') {
      // add however many spaces make a tab
      while (k < TABLENGTH) {
        new_line[end] = ' ';
        k++;
        end++;
      }
      // reset k count
      k = 0;
    } else {
      new_line[end] = line[i];
      i++;
      end++;
    }
  }

  return;
}

void my_get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return;
}

void print_line(char line[]) /*print line*/
{
  int l;
  int stop = 0;

  for (l = 0; stop == 0; ++l) {
    if (line[l] != '\n' && line[l] != '\0') {
      printf("%c", line[l]);
    } else if (line[l] == '\n' || line[l] == '\0' || line[l] == '0') {
      stop = 1;
    }
  }
  return;
}

