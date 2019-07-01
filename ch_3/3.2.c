/*
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
 * */

#include <stdio.h>
#include "../utils/get_print_line.c"
#define MAXLINE 1000

void escape(char s[], char t[]);

void main ()
{
  // get two char arrays
  char escaped_line[MAXLINE], unescaped_line[MAXLINE];
  // get unescaped user input
  my_get_line(unescaped_line, MAXLINE);
  // escape it
  escape(escaped_line, unescaped_line);
  // print the escaped user input
  print_line(escaped_line);
}

void escape(char final_string[], char to_copy[])
{
  // array position placeholders
  int i, j;
  // so long as we're not at the end of the array, \0
  for (i = j = 0; to_copy[i] != '\0'; i++) {
    // take character
    switch (to_copy[i]) {
      // if newline
      case '\n':
        // add slash
        final_string[j++] = '\\';
        // and then n, to escaped user input
        final_string[j++] = 'n';
        break;
      // if tab
      case '\t':
        // add slash
        final_string[j++] = '\\';
        // and t, to escaped user input
        final_string[j++] = 't';
        break;
      // otherwise
      default:
        // just grab char, which isn't newline or tab
        final_string[j++] = to_copy[i];
        break;
    }
  }
  // end of char array, \0
  final_string[j] = '\0';
}
