/*
 * Write a version of itoa that accepts three arguments instead of two. The third argument
 * is a minimum field width; the converted number must be padded with blanks on the left
 * if necessary to make it wide enough.
 * */

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w)
{
  int i, sign;
  void reverse(char s[]);
  sign = n;
  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) s[i++] = '-';
  while (i < w) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}
