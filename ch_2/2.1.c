/*
 * Write a program to determine the ranges of char, short, int, and long variables, both
 * signed and unsigned, by printing appropriate values from standard headers and by direct
 * computation. Harder if you compute them: determine the ranges of various floating-point
 * types.
 *
 * notes: I'm not sure how to do this with what the book has covered up to page 36; if this
 * is meant to cover the range between, say, LONG_MAX and LONG_MIN, then I'm totally lost.
 * */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main () {
  printf("\n");
  // if char intepreted as signed, CHAR_MIN == SCHAR_MIN and CHAR_MAX == SCHAR_MAX. Otherwise,
  // CHAR_MIN == 0 and CHAR_MAX == UCHAR_MAX
  printf("char max: %i, char min: %i. Range: %i\n", CHAR_MAX, CHAR_MIN, CHAR_MAX - CHAR_MIN);
  printf("signed char max: %i, signed char min: %i. Range: %i\n", SCHAR_MAX, SCHAR_MIN, SCHAR_MAX - SCHAR_MIN);
  printf("\n");
  printf("short max: %i, short min: %i. Range: %i\n", SHRT_MAX, SHRT_MIN, SHRT_MAX - SHRT_MIN);
  printf("\n");
  printf("int max: %i, int min: %i. Range: %f\n", INT_MAX, INT_MIN, floor(fabs(INT_MAX) + fabs(INT_MIN)));
  printf("\n");
  //printf("long max: %ld, long min: %ld. Range: %f.\n", LONG_MAX, LONG_MIN, floor(fabs(LONG_MAX) + fabs(LONG_MIN))); // this won't print an accurate result
}

