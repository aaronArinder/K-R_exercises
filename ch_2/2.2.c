/*
 * Write a for loop equivalent to:
 *
 *   getline (from ch. 1):
 *   int getline(char s[], int lim) {
 *     int, c, i;
 *     for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
 *       s[i] = c;
 *     }
 *     if (c == '\n) {
 *       s[i] = c;
 *       ++i;
 *     }
 *     s[i] = '\0';
 *     return i;
 *   }
 *
 * without using && or ||.
 * */

#include <stdio.h>
#define MAXLINE 1000

int mygetline(char s[], int limit);
void print_line(char line[]);

void main () {
  char line[MAXLINE];
  mygetline(line, MAXLINE);
  print_line(line);
}

int mygetline(char s[], int lim) { /*already getline on system*/

  int c, k = 0, stop = 0;
  while (stop != 1) {
    c = getchar();
    if ((lim - 1) <= k) stop = 1;
    if (c == '\n') stop = 1;
    if (c == EOF) stop = 1;
    if (stop != 1) s[k] = c;
    if (stop != 1) ++k;
  }

  if (c == '\n') {
    s[k] = c;
    ++k;
  }
  s[k] = '\0';
  return k;
}

void print_line(char line[]) {
  int stop = 0;

  printf("\n");

  for (int l = 0; stop == 0; ++l) {
    if (line[l] != '\0') {
      printf("%c", line[l]);
    } else {
      stop = 1;
    }
  }
  printf("\n");
  return;
}
