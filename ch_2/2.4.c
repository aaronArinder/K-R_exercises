/*
 * Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches
 * any character in the string s2.
 *
 * OG squeeze:
 *   void squeeze (char s[], int c) {
 *     int i, j;
 *     for (i = j = 0; s[i] != '\0'; i++)
 *       if (s[i] != c)
 *         s[j++] = s[i];
 *     s[j] = '\0';
 *   }
 *
 * */

#include <stdio.h>
#define MAXLINE 1000
void my_get_line(char s[], int lim);  // already a get_line on system
void print_line(char line[]);
void remove_chars_from_line(char original_line[], char mutating_chars[], char mutated_line[]);

void main () {
  char original_line[MAXLINE], mutating_chars[MAXLINE], mutated_line[MAXLINE];
  my_get_line(original_line, MAXLINE);
  my_get_line(mutating_chars, MAXLINE);
  remove_chars_from_line(original_line, mutating_chars, mutated_line);
  printf("\n");
  printf("Original Input\n");
  print_line(original_line);
  printf("\n");
  print_line(mutating_chars);
  printf("\n\n");
  print_line(mutated_line);
  printf("\n");
}

void remove_chars_from_line (char original_line[], char mutating_chars[], char mutated_line[]) {
  int orig_index = 0, mutated_index = 0;
  while (original_line[orig_index] != '\0') {
    int found = 0;
    for (int iter_index = 0; mutating_chars[iter_index] != '\0' && !found; iter_index++) {
      if (original_line[orig_index] == mutating_chars[iter_index]) {
        found = 1;
      }
    }
    if (!found) {
      mutated_line[mutated_index++] = original_line[orig_index];
    }
    orig_index++;
  }
}

void my_get_line (char s[], int lim) { // already a get_line on system
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return;
}

void print_line (char line[]) {
  int stop = 0;

  /*
   * getting weird values for this with carriage returns and what (I think) are
   * supposed to be empty char arrays
   * */
  for (int l = 0; stop == 0; ++l) {
    if (line[l] > '\0' && line[l] != 127) { // newer condition: not sure why I'm getting weird
      printf("%c", line[l]);                // char vals, e.g., -80, -104, -3, and 68 (D--wtf?)
    } else {
      stop = 1;
    }
  }
  return;
}
