/*
 * Write a program to remove all comments from a C program. Don't forget to handle quoted
 * strings and character constants properly. C comments do not nest.
 *
 * notes: assuming that we'll receive the program by  my_get_line, and also that to be a C
 * program is to be well formed, such that unclosed comments in C code count against that code
 * being a program
 * */

#include <stdio.h>
#define MAXLINE 1000 // cap of line size

int find_comment_close(char line[], int current_index); /*finds comment close, if exists*/
void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/
void remove_comments(char line[], char new_line[]); /*removes comments from C program qua line*/

void main()
{
  char line[MAXLINE], new_line[MAXLINE]; // input line
  my_get_line(line, MAXLINE);
  remove_comments(line, new_line);
  print_line(new_line);
}

void remove_comments(char line[], char new_line[])
{

  /*
   * while not end of array, \0
   * look at char
   * if char /
   * look at next chars until matching / found
   * write new_line without those chars
   * */

  int line_index = 0, new_line_index = 0, comment_close;
  while (line[line_index] != '\0') {
    if (line[line_index] == '/') {
      comment_close = find_comment_close(line, line_index);
      // ignore up to and including comment close
      line_index = comment_close;
    }

    // write new_line char
    new_line[new_line_index] = line[line_index];
    // increment indices
    line_index++;
    new_line_index++;
  }
}

int find_comment_close (char line[], int current_index) {
  // original char, important for checking // ... or /* ...
  int original_index = current_index;
  // set current_index to next char
  current_index++;
  // init for what kind of comment we have (//, /*)
  char terminus;
  // set terminus
  if (line[original_index] == line[current_index]) {
    terminus = '\n'; // unsure that this evaluates correctly in comparisons
  } else {
    terminus = '/';
  }

  while (line[current_index] != '\0') { // line[current_index++]?
    if (line[current_index] == terminus) {
      if (terminus == '\n') {
        // we want to keep newlines
        return current_index;
      } else {
        // but get rid of /s
        return ++current_index;
      }
    }
    current_index++;
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
