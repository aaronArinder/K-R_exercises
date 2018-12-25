/*
 * Write a program to remove trailing blanks and tabs from each line of input, and to delete
 * entirely blank lines
 * */

#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/

void mygetline(char line[], int maxline);

void main()
{
  int c, c_mem, i;
  char line[MAXLINE];

  mygetline(line, MAXLINE);
  for (i = 0; i < MAXLINE; i++) {
    if (line[i] == '\0') {
      return;
    }

    if (
      line[i] != '\n'                          // currently not a newline
      && (
        (c_mem != ' ')                         // mem and current not ' '
        || (c_mem == ' ' && line[i] != ' ' )   // previously a space, but currently not
      )
      && (c_mem != '\t' && line[i] != '\t')    // mem and current not tab
    ) {
      printf( "%c", line[i]);
    }
    c_mem = line[i];                           // set current char to mem
  }
}

/*getline: read a line into s, return length*/
void mygetline(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim - 1 && (c=getchar()) != EOF; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return;
}

