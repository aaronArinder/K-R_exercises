/*
 * Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1
 * into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Array that a leading or
 * trailing - is taken literally.
 *
 * core from C answer book (original credit: Axel Schreiner)
 * */

#include <stdio.h>
#include "../utils/get_print_line.c"
#define MAXLINE 1000
void expand (char s1[], char s2[]);

void main ()
{
  // get two char arrays
  char expanded_line[MAXLINE], unexpanded_line[MAXLINE];
  // get unexpanded user input
  my_get_line(unexpanded_line, MAXLINE);
  // expand it
  expand(unexpanded_line, expanded_line);
  // print the escaped user input
  print_line(expanded_line);
}

void expand (char s1[], char s2[])
{
  char c;
  int i, j;
  i = j = 0;

  // while current char isn't end of line
  while((c = s1[i++]) != '\0') {
    // if dash and next char's val greater than current's
    if (s1[i] == '-' && s1[i + 1] >= c) {
      // increment i
      i++;
      // and while current char val less than next val
      while (c < s1[i]) {
        // add incremented next val; this is where expansion`
        // happens. Super, super cool way to expand the values
        s2[j++] = c++;
      }
    // otherwise
    } else {
      // add current char
      s2[j++] = c;
    }
  }
  // add end of char array
  s2[j] = '\0';
}
