/*
 * Write the function any(s1, s2), which returns the first location in the string s1 where any
 * character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard
 * library function strpbrk does the same job but returns a pointer to the location.)
 * */

#include <stdio.h>
#define MAXLINE 1000

void any (char original_line[], char matching_line[], int result[]);
void print_line(char line[]);
void my_get_line(char s[], int lim);  // already a get_line on system

void main () {
  char original_line[MAXLINE], matching_line[MAXLINE];
  int result[2];
  my_get_line(original_line, MAXLINE);
  my_get_line(matching_line, MAXLINE);

  any(original_line, matching_line, result);
  printf("\n");
  if (result[0] >= 0) {
    printf("First matching character: %c", result[0]);
    printf("\n");
    printf("Index: %i", result[1]);
  } else if (result[0] == -1) {
    printf("No matching character found");
  } else {
    printf("Something went wrong");
  }
  printf("\n");
}

void any (char original_line[], char matching_line[], int result[]) {
  int orig_index = 0;
  signed int first_found = -1;

  while (original_line[orig_index] != '\0') {
    for (int iter_index = 0; matching_line[iter_index] != '\0' && first_found == -1; iter_index++) {
      if (original_line[orig_index] == matching_line[iter_index]) {
        first_found = orig_index;
      }
    }
    orig_index++;
  }

  if (first_found >= 0) {
    result[0] = original_line[first_found];
    result[1] =  first_found;
  } else {
    result[0] = -1;
  }
}


/*
 * helper fns
 * */

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

  for (int l = 0; stop == 0; ++l) {
    if (line[l] > '\0') {
      printf("%c", line[l]);
    } else {
      stop = 1;
    }
  }
  return;
}
