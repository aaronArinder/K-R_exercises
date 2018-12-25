/*
 * count words program from K&R
 * goal: find any bugs present (maybe none?)
 * */

#include <stdio.h>
#define IN 1 /*inside word*/
#define OUT 0 /*outside word*/

/*
 * count lines, words, and characters in input
 * */
void main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("\n nl: %d\n nw: %d\n nc: %d\n", nl, nw, nc);
}
