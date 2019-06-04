/*
 * Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
 * (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 *
 * */

#include <stdio.h>
#include "dec_to_bin.c"
// BIN_SIZE available from dec_to_bin: need tighter scope management; assumed C files were
// scoped to the file like a node module

void invert (unsigned x, int p, int n);

void main () {
  int argX, p, n;

  printf("Input a number whose bits will be replaced\n");
  scanf("%d", &argX);
  printf("Position to begin replacement\n");
  scanf("%d", &p);
  printf("How many bits to replace\n");
  scanf("%d", &n);

  printf("\n");
  printf("Replacing %i bit(s) in the binary representation of %i, beginning at position %i.\n\n", n, argX, p);
  printf("%i's binary: ", argX);
  print_dec_to_bin(argX);
  printf("\n");
  invert(argX, p, n);
}

// right-shifting unsigned always fills with 0; so, use that. Right-shifting signed bits fills
// with sign-bits (arithmetic shift) on some machines and -bits (logical shift) on others
void invert (unsigned x, int p, int n) {

  /*
   * Big idea: shift off the bits on both sides of the bits we care about, invert with
   * bitwise AND, and then inclusive OR the original bits (minus the inverted mid-section)
   * and the inverted bits to get the final bits.
   * */

  // invert before shifting
  unsigned int inverted_x = ~x;
  // rightside: keep p + n bits, including n (i.e., -1)
  int right_shift_amount = p - n;
  // leftside: keep p bits to the right
  int left_shift_amount = BIN_SIZE - p;

  unsigned int shifted_inverted_x =
    inverted_x >> right_shift_amount
      << right_shift_amount
      << left_shift_amount
      >> left_shift_amount;

  unsigned int shifted_inverted_x_mask =
    ~0 >> right_shift_amount
    << right_shift_amount
    >> left_shift_amount
    << left_shift_amount;

  unsigned int test = shifted_inverted_x_mask ^ x;
  unsigned int original_with_inverted_bits = x ^ shifted_inverted_x;

  printf("resulting binary: ");
  print_dec_to_bin(original_with_inverted_bits);
  printf("resulting decimal: %i\n\n", original_with_inverted_bits);
}

