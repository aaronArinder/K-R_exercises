#include <stdio.h>
#include <stdlib.h>

int main()
{
  int c, d, tab, backspace, backslash;
  int original_c, original_d, sum_tab, sum_backspace, sum_backslash;
  tab = '\\' + 't';
  backspace = '\\' + 'b';
  backslash = '\\' + '\\';

  original_c = 0;
  original_d = 0;

  sum_tab = 0;
  sum_backspace = 0;
  sum_backslash = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      sum_tab += tab;
      printf("sum_tab: %d", sum_tab);
      original_c += c;
      original_d += tab;
    } else if (c == '\b') {
      sum_backspace += backspace;
      original_c += c;
      original_d += backspace;
    } else if (c == '\\') {
      sum_backslash += backslash;
      original_c += c;
      original_d += backslash;
    } else {
      original_c += c;
      original_d += c;
    }
  }

  printf("\ntotal tabs: %d\n", (sum_tab / tab));
  printf("total backspaces: %d\n", (sum_backspace / backspace));
  printf("total backslashes: %d\n\n", (sum_backslash / backslash));
  printf("original_c: %d\n", original_c);
  printf("original_d: %d\n", original_d);
  printf("difference: %d\n\n", original_d - original_c);

  return 0;
}
