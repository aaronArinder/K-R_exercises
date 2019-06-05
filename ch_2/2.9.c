/*
 * In a two's complement number system, `x &= (x-1)` deletes the rightmost 1-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount:
 *
 * bitcount: count 1 bits in x:
 *
 * int bitcount (unsigned x)
 * {
 *   int b;
 *   for (b = 0; x != 0; x >>= 1)
 *     if (x & 01)
 *       b++;
 *   return b;
 * }
 *
 * */

/*
 * Explain why:
 *
 * If you take 1 away from x, you take 0001 from its binary representation. When you bitwise AND
 * the difference between x and (x - 1), the comparison of the rightmost bit will never match
 * because x is (x - 1) + 1. That is, x and (x - 1) will always have their rightmost bits differ.
 * */

#include <stdio.h>
int bitcount_old (unsigned x);
int bitcount_new (unsigned x);

void main ()
{
  bitcount_old(15); // 3 1-bits
  bitcount_new(15); // 3 1-bits
}

int bitcount_old (unsigned x)
{
  int b;
  int loop = 0;
  // shift x to the right by 1 bit
  for (b = 0; x != 0; x >>= 1) {
    loop++;
    // check if the lsb is 1
    if (x & 01) {
      b++;
    }
  }
  printf("\nloops old: %i\n", loop);
  printf("b old: %i\n", b);
  return b;
}

// let x == 10 e.g.
// 10 == 1010 :: 2 1-bits total
// 10 - 1 == 1001
// 1010 & 1001 == 1000 :: loop 1
//
// 1000 (i.e., 8) - 1 == 111
// 1000 & 111 == 0 :: loop 2
//
// we count a bit per loop :: 2 1-bits in 1010
//
// 15 == 1111
// 15 - 1 == 1110
// 1111 & 1110 == 1110 :: loop 1
// 1110 - 1 == 1101
// 1110 & 1101 == 1100 :: loop 2
// 1100 - 1 == 1011
// 1100 & 1011 == 1000 :: loop 3
// 1000 - 1 == 111
// 1000 & 111 == 0000  :: loop 4
//
// 4 loops :: 4 1-bits in decimal 15
int bitcount_new (unsigned x)
{
  int b;
  int loop = 0;

  for (b = 0; x != 0; x &= (x - 1)) {
    loop++;
    b++;
  }
  printf("\nloops new: %i\n", loop);
  printf("b new: %i\n", b);
  return b;
}

