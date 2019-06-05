/*
 * Rerwite the function `lower`, which converts upper case letters to lower case, with a conditional
 * expression instead of if-else.
 *
 * lower: convert c to lower case; ASCII only
 *
 * int lower(int c)
 * {
 *   if (c >= 'A' && c <= 'z')
 *     return c + 'a' - 'A';
 *   else
 *     return c;
 * }
 *
 * */

#include <stdio.h>
int lower_old(int character);
int lower_new(int character);

void main ()
{
  char character = 'Z';
  // both expect an uppercase letter
  printf("\nold character: %c\n", lower_old(character));
  printf("new character: %c\n\n", lower_new(character));
}

int lower_old(int c)
{
  if (c >= 'A' && c <= 'z')
    return c + 'a' - 'A';
  else
    return c;
}

int lower_new(int c)
{
  return (c >= 'A' && c <= 'z')
    ? c + 'a' - 'A'
    : c;
}
