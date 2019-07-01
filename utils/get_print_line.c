/*
 * ex: #include "../utils/get_print_lin.c"
 *
 * my_get_line:
 * print_line:
 * */

#include <stdio.h>
// named as such because there's already a get_line on my system
void my_get_line (char s[], int lim);
void print_line (char line[]);

void my_get_line (char s[], int lim) {
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return;
}

void print_line (char line[]) {
  int stop = 0;

  for (int l = 0; stop == 0; ++l) {
    if (line[l] > '\0') {
      printf("%c", line[l]);
    } else {
      stop = 1;
    }
  }
  return;
}

