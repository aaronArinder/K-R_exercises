/*
 * Write a program to 'fold' long input lines into two or more shorter lines after the last
 * non-blank character that occurs before the n-th column of input. Make sure your program does
 * something intelligent with very long lines, and if there are no blanks or tabs before the
 * specified column.
 * */

#include <stdio.h>
#define LINE_LENGTH 30 // n -- not sure if this is what KR meant
#define MAXLINE 1000 // cap of line size

void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/
void add_new_lines(char line[], char new_line[]); /* set \n in new_line*/

int find_line_end(char line[]); /*find length of array*/

void main()
{
  char line[MAXLINE], new_line[MAXLINE]; // input line
  my_get_line(line, MAXLINE);
  add_new_lines(line, new_line);
  print_line(new_line);
}

void my_get_line(char s[], int lim)
{
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return;
}

int find_line_end(char line[])
{
  int index = 0, stop = 0;
  while (stop != 1) {
    if (line[index] == '\0') {
      stop = 1;
    } else {
      index++;
    }
  }
  return index;
}

int find_next_blank_tab (char line[], int begin, int end)
{
  int checking = 1, index, blank_tab_index = 0;
  for (index = end; index >= begin && checking == 1; index--) {
    if (line[index] == ' ' || line[index] == '\t') {
      checking = 0;
      blank_tab_index = index;
    }
  }

  // returns 0 if no index found (or if first blank in 0th position)
  return blank_tab_index;
}

void add_new_lines(char line[], char new_line[])
{
  int line_index = 0, new_line_index = 0;
  int chunk = 0;
  int next_blank_tab_index;
  int actual_line_length = find_line_end(line);

  while(line_index < actual_line_length) {
    chunk = line_index + LINE_LENGTH;
    next_blank_tab_index = find_next_blank_tab(line, line_index, chunk);
    while (line_index <= chunk) {
      if (next_blank_tab_index == 0 && line_index == chunk) {
        new_line[new_line_index] = '-';
        new_line[++new_line_index] = '\n';
        new_line[++new_line_index] = line[line_index];
      } else if (line_index == next_blank_tab_index) {
        new_line[new_line_index] = '\n';
      } else {
        new_line[new_line_index] = line[line_index];
      }
      new_line_index++;
      line_index++;
    }
  }
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
