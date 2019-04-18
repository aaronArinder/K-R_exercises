/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set
 * to the rightmost n bits of y, leaving the other bits unchanged.
 *
 * notes:
 *   - example, pg. 49: x = x & ~077
 *     - integer literals that start with 0 are intepreted in octal base (base 8), which means
 *       each digit corresponds to three bits in binary: 000 111 111.
 *     - 077 stored in 16 bits: 0000 0000 0011 1111.
 *     - ~ is the one's complement: it flips 0 to 1 and 1 to 0.
 *       - ~ 0000 0000 0000 1111 == 1111 1111 1100 000
 *     - & returns 1 if both bits are 1, 0 otherwise
 *     - x & ~077 compares each pair of bits with bitwise-and
 *       - xxxx xxxx xxxx xxxx
 *         1111 1111 1100 0000
 *       - this effectively 'masks off' the lowest 6 bits because they can only be 0 from &
 *       - so, xxxx xxxx xx00 0000 is the result (who knows what x is)
 * */

#include <stdio.h>
#include "dec_to_bin.c"

int setbits (unsigned x, int p, int n, int y); // why unsigned?

void main () {
  int argX = 4;
  int argY = 2;
  print_dec_to_bin(~2);
  //setbits(argX, 3, 2, argY);
}

int setbits (unsigned x, int p, int n, int y) {
  // get all 1s in y's positions
  int mask = y | ~y;
  // shift y to the left p bits
  mask =  mask << p;
  // now we have something like 1111 1111 1111 0000; so, let's XOR it with y to get only
  // the bits from place p from y: something like 0000 0000 0000 1101
  mask = mask ^ y;

  // we're done masking; we've got all and only those bits from position p onward; so, let's
  // mutate x

  // 'bump' off p bits from the right; shifting back p to put 0 bits in those places
  x = (x >> p) << p;
  // inclusive OR to take any bits from x, which now has 0s in the rightmost p places so that
  // any mask bits in those positions will be taken
  x = mask | x;
  return x;
}

