/*
 * Write the function htoi(s), which converts a string of hexadecimal digits (including an
 * optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9,
 * a through f, and A through F.
 *
 * notes:
 * hexadecimal 16-based; find charset int equivalent, multiply each charset int with power of
 * 16, where the power is each digit's location from right to left: 7DE = (7*16^2) + (13*16^1)
 * + (14*16^0). Why the weird powers? Changing from base 10 to base 16; so, from 0, 10, 100,
 * etc., to 0, 16, 256, etc.
 *
 * test vals:
 * C8 = 200
 * 7DE = 2014
 * 7de = 2014
 * AD5f = 44383
 * 7DEeFf = 8253183
 * 0x7DEeFf = 8253183
 * */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000
#define HEX_BASE 16

int htoi(char s[], int lim);
void my_get_line(char s[], int lim);
int get_line_length (char line[]);
int power(int base, int exponent);

void main () {
  char line[MAXLINE];
  my_get_line(line, MAXLINE);
  int line_length = get_line_length(line);
  int result = htoi(line, line_length);

  if (result) printf("\ninteger value: %i", result);
  else printf("\nInvalid hexadecimal");
  printf("\n");
}

int get_line_length (char line[]) {
  int i = 0;
  while (line[i] != '\0') {
    i++;
  }
  return i;
}

int htoi(char s[], int lim) {
  int i = lim - 1;
  int exponent = 0; // 0s place == 0, 16s == 1, 256s == 2, etc.

  /*
   * more detailed explanation of the index and exponent initial values:
   *
   * we're going to increment the exponent as the index decrements. That way,
   * a hex like 7DE, [7, D, E], will be treated as [7*(16^2), D*(16^1), E*(16^0)],
   * i.e., [7*(16^2), 13*(16^1), 14*(16^0)]. So, set the index to the limit and
   * the exponent to 0--they'll work from opposite ends of the array.
   * */

  int sum = 0; // track sum
  signed int successful = 1; // default to success

  while (successful != -1 && s[i] != '\0' && i >= 0) {
    if (!isxdigit(s[i])) {
      successful = -1; // let -1 represent err
    } else if (isxdigit(s[i])) {
      if (isupper(s[i])) {
        sum = sum + (power(HEX_BASE, exponent) * (s[i] - 55));
      } else if (islower(s[i])) {
        sum = sum + (power(HEX_BASE, exponent) * (s[i] - 87));
      } else {
        sum = sum + (power(HEX_BASE, exponent) * (s[i] - 48));
      }
    }

    i--;
    exponent++;
  }

  if (successful) return sum;
  else return successful;
};

int power(int base, int exponent) {
  int sum = 1;
  while (exponent > 0) {
    sum = sum * base;
    exponent--;
  }

  return sum;
}

void my_get_line(char s[], int lim) { // already a get_line on system
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return;
}
