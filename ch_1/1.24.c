/*
 * Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
 * brackets, and braces. Don't forget about quotes, single and souble, escape sequences, and
 * comments. (This program is hard if you do it in full generality.)
 *
 * notes:
 *   - assuming that a C program would be read through something like my_get_line
 *   - this _is_ super hard in its full generality. I'm going to start with minimal syntax checking
 *     and add more support in the future, if I feel like coming back to this exercise.
 *   - currently supports checking for:
 *     - opening/closing (), [], {}
 *
 *   - ideas of what to support next:
 *     - something between ()
 *     - opening/closing of quotes, both single and double
 *       - no strings outside of quotes
 *     - syntax not ill-formed: e.g., () immediately followed by {}, not ()
 * */

#include <stdio.h>
#define MAXLINE 1000 // cap of line size
#define SYMBOLS 3

void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/
int check_block_match (int line_index, char block_demarcator, char line[]);
int check_quote_match (int line_index, char quote, char line[]);
int verify_syntax (char line[]);
int find_first_index_of_symbol (char symbol, char line[]);
int find_last_index_of_symbol (char symbol, int target_symbol_count, char line[]);
char block_openers[SYMBOLS] = { '(', '[', '{' };
char block_closers[SYMBOLS] = { ')', ']', '}' };

void main()
{
  int i = 0;
  char line[MAXLINE], new_line[MAXLINE]; // input line
  my_get_line(line, MAXLINE);
  verify_syntax(line);
  //print_line(new_line);
}

int verify_syntax (char line[]) {
  int openers[SYMBOLS] = { 0,0,0 };
  int closers[SYMBOLS] = { 0,0,0 };
  //int paren_open = 0, brack_open = 0, brace_open = 0;
  //int paren_close = 0, brack_close = 0, brace_close = 0;

  int line_index = 0;
  while (line[line_index] != '\0') {
    char line_char = line[line_index];

    for (int block_symbol_index = 0; block_symbol_index < SYMBOLS; block_symbol_index++) {
      char block_open = block_openers[block_symbol_index];
      char block_close = block_closers[block_symbol_index];

      if (line_char == block_open) {
        openers[block_symbol_index]++;
      } else if (line_char == block_close) {
        closers[block_symbol_index]++;
      }

    }
    line_index++;
  }

  for (int iteration = 0; iteration < SYMBOLS; iteration++) {

    int symbol_open_count = openers[iteration];
    int symbol_close_count = closers[iteration];
    int problem_index;

    // if symbol counts don't match
    if (symbol_open_count != symbol_close_count) {
      // and if open less than close, unmatched close symbol
      if (symbol_open_count < symbol_close_count) {
        // find outermost close symbol's index
        problem_index = find_last_index_of_symbol(block_closers[iteration], symbol_close_count, line);
        // report symbol and index
        printf("Unmatched %c: index %i", block_closers[iteration], problem_index);
      // otherwise, unmatched open symbol
      } else if (symbol_close_count < symbol_open_count) {

        /*
         * TODO: this doesn't work for something like `if (1) {a}; if(2 {b}`, which prints
         * `Unmatched (: index 3`
         * */

        // at the first index of that symbol's occurrence
        problem_index = find_first_index_of_symbol(block_openers[iteration], line);
        // report symbol and index
        printf("Unmatched %c: index %i\n", block_openers[iteration], problem_index);
      }
    }
  }
}

int find_first_index_of_symbol (char symbol, char line[]) {
  int line_index = 0;
  while (line[line_index] != '\0') {
    if (line[line_index] == symbol) {
      return line_index;
    }

    line_index++;
  }
  return 0; // need better int returned; defaulting to 0 might be safe, though
}

int find_last_index_of_symbol (char symbol, int target_symbol_count, char line[]) {
  int line_index = 0;
  int iterating_symbol_count = 0;
  while (line[line_index] != '\0') {
    if (line[line_index] == symbol) {
      iterating_symbol_count++;
    }

    if (iterating_symbol_count == target_symbol_count) {
      return line_index;
    }
    line_index++;
  }
  return 0; // need better int returned; defaulting to 0 might be safe, though
}



int check_block_match (int line_index, char block_demarcator, char line[]) {
  /*
     for each elm of line
     if elm == symbol's close
       return 0
     if no elm == symbol's close
       return 1

     probs: need to check not only that the symbol matches, but that it
     matches appropriately: there can be no other of the same symbol
     opening before a match is found. This is problematic for quotes,
     whose open 'looks' the same as their close

     what about <>, #, ++, --, etc?
   */

  char matching_demarcator;
  // set symbol matches
  if (block_demarcator == '(') {
    matching_demarcator = ')';
  } else if (block_demarcator == '[') {
    matching_demarcator == ']';
  } else if (block_demarcator == '{') {
    matching_demarcator = '}';
  } else if (block_demarcator == '\'') {
    matching_demarcator = '\'';
  } else if (block_demarcator == '"') {
    matching_demarcator = '"';
  }

  while (line[++line_index] != '\0') {

  }
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
