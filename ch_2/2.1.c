/*
 * Write a program to determine the ranges of char, short, int, and long, both signed
 * and unsigned, by printing appropriate values from standard headers and by direct
 * computation. Harder if you compute them: determine the ranges of various floating-point
 * types.
 *
 * */


#include <stdio.h>
#include <limits.h>
#include <float.h>

int main () {
  printf("\n");
  // if char intepreted as signed, CHAR_MIN == SCHAR_MIN and CHAR_MAX == SCHAR_MAX. Otherwise,
  // CHAR_MIN == 0 and CHAR_MAX == UCHAR_MAX
  printf("char max: %i, char min: %i. Distance: %i\n", CHAR_MAX, CHAR_MIN, CHAR_MAX - CHAR_MIN);
  printf("Signed char max: %i, signed char min: %i. Distance: %i\n", SCHAR_MAX, SCHAR_MIN, SCHAR_MAX - SCHAR_MIN);
  printf("short max: %i, short min: %i. Distance: %i\n", SHRT_MAX, SHRT_MIN, SHRT_MAX - SHRT_MIN);
  printf("INT_MAX: %i, INT_MIN: %i.", INT_MAX, INT_MIN);
  //printf("int max: %i, int min: %i. Distance: %i\n", INT_MAX, INT_MIN, INT_MAX - INT_MIN);
  //printf("long max: %ld, long min: %ld. Distance: %ld.\n", LONG_MAX, LONG_MIN, LONG_MAX - LONG_MIN);
}
