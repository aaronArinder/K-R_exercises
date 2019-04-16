/*
 * Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
 * brackets, and braces. Don't forget about quotes, single and souble, escape sequences, and
 * comments. (This program is hard if you do it in full generality.)
 *
 * notes:
 *   - assuming that a C program would be read through something like my_get_line
 *   - this _is_ super hard in its full generality. I'm going to start with minimal syntax checking
 *     and add more support in the future if I feel like coming back to this exercise.
 *   - currently supports checking for:
 *     - opening/closing (), [], {}
 *
 *     - big idea for block matching: have two arrays, one that keeps a
 *       running sum of openers/closers, where an opener increments the
 *       sum and a closer decrements the sum. For (){}, the sum == 0. For
 *       ({}, the sum is 1. If the array keeping track of the running sum
 *       has a 0, we find the matching element in the array keeping track
 *       of the symbol indices in the user-inputted line.
 *
 *
 *   - ideas of what to support next:
 *     - that there's something between ()
 *     - opening/closing of quotes, both single and double
 *       - no strings outside of quotes
 *     - syntax not ill-formed: e.g., conditional () immediately followed by {}, not ()
 * */

#include <stdio.h>
#define MAXLINE 1000 // cap of line size
#define SYMBOLS 3

void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/

int get_symbol_count (char line[]);
void set_symbol_and_match_count (int symbol_count, char line[], int count_list[], int symbol_indices[]);
int find_problem_index (int symbol_count, int count_list[], int symbol_indices[]);

char block_openers[SYMBOLS] = { '(', '[', '{' };
char block_closers[SYMBOLS] = { ')', ']', '}' };

int main() {
  char line[MAXLINE]; // input line
  my_get_line(line, MAXLINE); // get user-inputted line
  int symbol_count = get_symbol_count(line); // total number of openers/closers
  int count_list[symbol_count]; // keeps running total of opened/closed symbols
  int symbol_indices[symbol_count]; // keeps track of each symbol's index

  set_symbol_and_match_count(symbol_count, line, count_list, symbol_indices);

  int problem_index = find_problem_index(symbol_count, count_list, symbol_indices);
  if (problem_index) {
    printf("Unmatched %c at index %i", line[problem_index], problem_index);
    return 0;
  } else {
    return 1;
  }
}

int get_symbol_count (char line[]) {
  int symbol_count = 0;
  for (int line_index = 0; line[line_index] != '\0'; line_index++) {
    for (int symbol_index = 0; symbol_index < SYMBOLS; symbol_index++) {
      if (
        block_openers[symbol_index] == line[line_index]
        || block_closers[symbol_index] == line[line_index]
      ) {
        symbol_count++;
      }

    }
  }
  return symbol_count;
}

void set_symbol_and_match_count (int symbol_count, char line[], int count_list[], int symbol_indices[]) {
  int match_count = 0;
  int tracking_index = 0;

  for (int line_index = 0; line[line_index] != '\0'; line_index++) {
    for (int symbol_index = 0; symbol_index < SYMBOLS; symbol_index++) {
      if (block_openers[symbol_index] == line[line_index]) {
        match_count++;
        count_list[tracking_index] = match_count;
        symbol_indices[tracking_index] = line_index;
        tracking_index++;
      } else if (block_closers[symbol_index] == line[line_index]) {
        match_count--;
        count_list[tracking_index] = match_count;
        symbol_indices[tracking_index] = line_index;
        tracking_index++;
      }
    }
  }
  count_list[tracking_index] = '\0';
  symbol_indices[tracking_index] = '\0';
}

int find_problem_index (int symbol_count, int count_list[], int symbol_indices[] ) {
  int symbol_count_iterator = symbol_count - 1; // accounts for zero indexing

  for (symbol_count_iterator; symbol_count_iterator > 0; symbol_count_iterator--) {
    if (count_list[symbol_count_iterator] == 0 && count_list[symbol_count_iterator] != '\0') {
      // we want the index right after the bad count
      return symbol_indices[++symbol_count_iterator];
    }
  }

  return 0; // not great; but, if someone's program is just ( then they've other problems
}

void my_get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return;
}

void print_line(char line[])
{
  int l;
  int stop = 0;

  printf("\n");

  for (l = 0; stop == 0; ++l) {
    if (line[l] != '\0') {
      printf("%c", line[l]);
    } else {
      stop = 1;
    }
  }
  printf("\n");
  return;
}
