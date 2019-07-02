/*
 * Write the function strrindex(s,t), which returns the position of the rightmost occurrence
 * of t in s, or -1 if there is none.
 * */

#include <stdio.h>
#include "../utils/get_print_line.c"
#define MAXLINE 1000
int rightmost_str_index (char substr[], char str[]);

void main ()
{
  char substr[MAXLINE], str[MAXLINE];
  printf("Enter string:\n");
  my_get_line(str, MAXLINE);
  printf("Enter substring to match on:\n");
  my_get_line(substr, MAXLINE);
  int result = rightmost_str_index(substr, str);
  if (result == -1) printf("No match found\n");
  else printf("Rightmost match found at index %i\n", result);
}

int rightmost_str_index (char substr[], char str[])
{
  int i, j, k;
  // default to -1, which is returned when no match is found
  int rightmost_match = -1;

  // get each char from str
  for (i = 0; str[i] != '\0'; i++) {
    // check the substr against the str, starting at current index of str
    for (j = i, k = 0; substr[k] != '\0' && str[j] == substr[k]; j++, k++)
      // do nothing; loop is meant for incrementing k until end of substr
      // or until a mismatch is found
      ;
    // if we _a_ match and that match is the full substring
    if (k > 0 && substr[k] == '\0')
      // then set the rightmost_match to the str's current index
      rightmost_match = i;
  }
  // return index or -1 to indicate no match was found
  return rightmost_match;
}
