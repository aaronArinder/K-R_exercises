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
 *   - going to use dec_to_bin, which returns the two's complement representation of the binary
 * */

#include <stdio.h>
#include "dec_to_bin.c"
// BIN_SIZE available from dec_to_bin: need tighter scope management; assumed C files were
// scoped to the file like a node module

void setbits (unsigned x, int p, int n, unsigned y);

void main () {
  int argX, p, n, argY;

  printf("Input a number whose bits will be replaced\n");
  scanf("%d", &argX);
  printf("Input a number whose bits will be used for replacement in %i's bits\n", argX);
  scanf("%d", &argY);
  printf("Position to begin replacement\n");
  scanf("%d", &p);
  printf("How many bits to replace\n");
  scanf("%d", &n);

  printf("\n");
  printf("Replacing %i bit(s) in %i, beginning at position %i, from binary representation of %i.\n\n", n, argX, p, argY);
  printf("%i's binary: ", argX);
  print_dec_to_bin(argX);
  printf("%i's binary: ", argY);
  print_dec_to_bin(argY);
  printf("\n");
  setbits(argX, p, n, argY);
}

// right-shifting unsigned always fills with 0; so, use that. Right-shifting signed bits fills
// with sign-bits (arithmetic shift) on some machines and -bits (logical shift) on others
void setbits (unsigned x, int p, int n, unsigned y) {

  /*
   * First, find the subset of bits in x beginning at p, with n places, and then clear both sides
   * of x's binary representation by shifting off both sides and using an inclusive OR to have all
   * and only those bits from x not in the subset.
   *
   * Then do the inverse of that for y: shift off the right side of y, but don't shift off the
   * subset of bits we want to use as replacements for x; shift off the bits left of the replacement
   * subset.
   *
   * Finally, use an inclusive OR on both the handled x binary repsentation (it should now have a
   * nicely-subset-sized hole) and the handled y binary representation (which should be an exact
   * fit for that nicely-subset-sized hole in x).
   *
   * Hopefully.
   *
   * TODO: err handling for bad inputs, test negative numbers
   * */

  // clear right-side p bits
  unsigned int right_shifted_x = (x >> p) << p;

  // clear left-side p + n bits
  unsigned int left_shifted_x = (x <<  (BIN_SIZE - p + n)) >> (BIN_SIZE - p + n);
  //printf("left_shifted: ");
  //print_dec_to_bin(left_shifted_x);
  unsigned int x_without_p = right_shifted_x | left_shifted_x;
  //printf("x without n bits at p: ");
  //print_dec_to_bin(x_without_p);
  // clear right-side p bits
  unsigned int right_shifted_y = (y >> p) << p;
  // clear left-side p bits
  unsigned int left_shifted_y = (right_shifted_y << (BIN_SIZE - p)) >> (BIN_SIZE - p);
  //printf("left_shifted Y: ");
  //print_dec_to_bin(left_shifted_y);
  unsigned int combined_bits = x_without_p | left_shifted_y;
  printf("combined bits: ");
  print_dec_to_bin(combined_bits);
}

