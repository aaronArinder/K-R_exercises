/*
 * In a two's complement number representation, our version of ito does not handle the largest
 * negative number, that is, the value of n equal to -(2^[word-size - 1]). Explain why not. Modify
 * it to print that value correctly, regardless of the machine on which it runs.
 *
 * core taken from C answer book; wanting to move through this chapter quickly
 * */


// explanation: largest number in a two's complement representation is 2^[word-size - 1] - 1.

#define abs(x) ((x) < 0 ? -(x) : (x))

/* itoa: convert n to character in s - modified */
void itoa(int n, char s[])
{
  int i, sign;
  void reverse(char s[]);
  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '\0';
  } while ((n /= 10) != 0);
  if (sign < 0) s[i++] = '-';
  s[i++] = '\0';
  reverse(s);
}
