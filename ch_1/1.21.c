/*
 * Write a program entab that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same tab
 * stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference?
 * */


#include <stdio.h>
#define MAXLINE 1000 /*max input line size*/
#define TABLENGTH 4 /*how many spaces to replace a tab with*/

void my_get_line(char line[], int maxline); /*already getline on system; renamed*/
void print_line(char line[]); /*print char array*/
void print_tabs_spaces_count(char line[]); /*prints count of tabs/spaces*/
void replace_spaces(char line[], char new_line[]);

int main()
{
  int len; /*current line length*/
  char line[MAXLINE]; /*input line*/
  char new_line[MAXLINE]; /*line to be returned*/

  my_get_line(line, MAXLINE);

  printf("\nTab length set at: %i", TABLENGTH);
  replace_spaces(line, new_line);
  printf("\n\nnew line\n");
  print_line(new_line);

  printf("old line");
  print_tabs_spaces_count(line);
  printf("new line");
  print_tabs_spaces_count(new_line);

  return 0;
}

void replace_spaces(char line[], char new_line[])
{
  int i = 0;
  int k = 0;
  int end = 0; /*this marks ending elm of new_line, which can be longer than line*/

  // while not the end of the array
  while (line[i] != '\0') {
    // if elm isn't a space
    if (line[i] != ' ') {
      // set new array's end to current elm
      new_line[end] = line[i];
      // increase count of elms in new array
      end++;
      i++;
    // otherwise, if we've a space
    } else if (line[i] == ' ') {
      int space_count = 0, spaces = 0, tabs = 0;
      // then so long as we've spaces in a row
      while (line[i + space_count] == ' ') {
        // increase our count of spaces
        space_count++;
      }
      // if tabs divisible by spaces with remainder
      if ((space_count % TABLENGTH) > 0) {
        // set the number of spaces to the remainder
        spaces = space_count % TABLENGTH;
      }
      // if fewer spaces than a tab's length
      if (TABLENGTH > space_count) {
        // set spaces to that count
        spaces = space_count;
      }

      /*
       * the following conditional also accounts for when TABLENGTH == 4 and space_count == 3,
       * because 3 - 3 == 0, and 0/4 == 0, setting tabs == 0. Stupid, I know. This whole
       * loop needs a good refactoring.
       * */

      // if tabs divisible by remaining spaces _without_ remainder
      if (((space_count - spaces) % TABLENGTH) == 0) {
        // set number of tabs to quotient
        tabs = space_count / TABLENGTH;
      }


      // add tabs to newline
      while (tabs > 0) {
        new_line[end] = '\t';
        end++;
        tabs--;
      }
      // add spaces to newline
      while (spaces > 0) {
        new_line[end] = ' ';
        end++;
        spaces--;
      }
      // update index to include spaces we've accounted for
      i = i + space_count;
    }
  }

  return;
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

void print_tabs_spaces_count(char line[])
{
  int index = 0, tabs = 0, spaces = 0;
  // while not at end of line
  while (line[index] != '\0') {
    // if tab
    if (line[index] == '\t') {
      // increase count
      tabs++;
    // if space
    } else if (line[index] == ' ') {
      // increase count
      spaces++;
    }
    index++;
  }

  printf("\n  tabs: %i \n  spaces: %i \n\n", tabs, spaces);
  return;
}


void print_line(char line[])
{
  int l;
  int stop = 0;

  for (l = 0; stop == 0; ++l) {
    if (line[l] != '\n' && line[l] != '\0') {
      printf("%c", line[l]);
    } else if (line[l] == '\n' || line[l] == '\0' || line[l] == '0') {
      stop = 1;
    }
  }
  printf("\n\n");
  return;
}


