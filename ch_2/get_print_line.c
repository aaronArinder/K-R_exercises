/*
 * K&R haven't covered this yet, but from a udemy course, I realized you can require in
 * other files with `#include "some_file.c"`, which is great, because I was tired of ferkin
 * copy/pasting the below.
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

