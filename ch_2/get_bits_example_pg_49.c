/*
 * based on pg. 49: here to make sense of what's going on in that example
 * */

#include <stdio.h>
#include "dec_to_bin.c"

unsigned getbits(unsigned x, int p, int n);

void main () {
  getbits();
}

unsigned getbits(unsigned x, int p, int n) {
  printf("%i\n", x);
  printf("%i\n", p);
  printf("%i\n", n);

  printf("x >> (p+1-n): %i\n", x >> (p+1-n));

  return (x >> (p+1-n)) & ~(~0 << n);
}
