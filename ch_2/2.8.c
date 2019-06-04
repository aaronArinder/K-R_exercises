/*
 * Write a function `rightrot(x,n)` that returns the value of the integer x rotated
 * to the right by n positions
 *
 * notes:
 *   - less fancy than 2.7: hard-coding arg vals to get through this one more quickly.
 *   - no error handling, but it would likely be easy (4 mins left on lunch and wanting
 *     to move on the next section tomorrow): just make sure that n is greater than or
 *     equal to p
 * */

#include <stdio.h>
#include "dec_to_bin.c"
// BIN_SIZE available from dec_to_bin: need tighter scope management; assumed C files were
// scoped to the file like a node module

void main ()
{
  // x == digit whose binary will be mutated
  int x = 100;
  printf("\n");
  printf("Base number: %i\n", x);
  // p == position whose bit value will be moved
  int p = 7;
  printf("Bit to move: %i\n", p);
  // n == amount to move p to the right
  int n = 2;
  printf("Space moved: %i\n\n", n);

  // shift 1 over to the desired position
  unsigned mask = 1 << (p - 1);
  // figure out if the masked value is 0 or not. If not, we're dealing with
  // a 1 in position p. If we have 0, we're dealing with a 0 in p. Whether we
  // use inclusive or exclusive OR depends on the masked_value
  unsigned masked_value = mask & x;
  // move the value to the right n places
  unsigned rotated_right = mask >> n;

  // init empty unsigned int. This value will be what we eventually print
  unsigned masked;
  // if masked_value is 0, the bit in position p is 0
  if (masked_value == 0) {
    // so use exclusive OR to make sure the bit in p - n is 0 while respecting
    // all of x's values (rotated_right's other bits are all 0)
    masked = rotated_right ^ x;
  } else {
    // if masked_value isn't 0, we have a 1 in position p. Use inclusive OR to
    // capture _either_ a 0 or 1 for the bit in p - n, as well as all of x's other
    // bit values
    masked = rotated_right | x;
  }

  // printing
  printf("test: ");
  print_dec_to_bin(masked_value);
  printf("Binary representation of %i\n", x);
  print_dec_to_bin(x);

  printf("Bit moved: ");
  printf("\n");
  print_dec_to_bin(masked);

}

