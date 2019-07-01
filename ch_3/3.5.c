/*
 * Write the function itob(n,s,b) that converts the integer n into a base b character
 * representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal
 * integer in s.
 * */

void itob(int n, char s[], int b)
{
  int i, j, sign;
  void reverse(char s[]);
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    j = n % b;
    s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
  } while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
