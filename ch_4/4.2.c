/*
 * Extend atof (found on pg 71 and given below) to handle scientific notation of the form:
 * 123.45e-6, where a floating-point number may be followed by e or E and an optionally signed
 * component.
 *
 * atof
 * ```
 *   #include <ctype.h>
 *   double atof (char s[])
 *   {
 *     double val, power;
 *     int i, sign;
 *
 *     for (i = 0; isspace(s[i]; i++) // skip whitespace
 *       ;
 *     sign = (s[i] == '-') ? -1 : 1;
 *     if (s[i] == '+' || s[i] == '-') i++;
 *     for (val = 0.0; isdigit(s[i]); i++) {
 *       val = 10.0 * val + (s[i] - '0');
 *     }
 *     if (s[i] == '.') i++;
 *     for (power = 1.0; isdigit(s[i]); i++) {
 *       val = 10.0 * val + (s[i] - '0');
 *       power *= 10.0;
 *     }
 *     return sign * val / power;
 *   }
 * ```
 * */



// standard lib
#include <stdio.h>
#include <ctype.h>

// local deps
#include "../utils/get_print_line.c"

#define MAXLINE 100
double extended_atof (char s[]);

void main ()
{
  char user_str[MAXLINE];
  printf("Enter number to convert:\n");
  my_get_line(user_str, MAXLINE);
  double handled = extended_atof(user_str);
  printf("converted number: %g\n", handled);
}

double extended_atof (char s[])
{
  double val, power, scientific_power;
  int i, sign, negative_power;

  // why skip leading whitespace
  for (i = 0; isspace(s[i]); i++) // skip whitespace
    ;

  // determine sign
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') i++;

  for (val = 0.0; isdigit(s[i]); i++) {
    // this confused me from OG atof; but, multiplying val by 10
    // and then adding the value of the char at s[i] (after ascii
    // handling) puts the resulting value in the right place.
    val = 10.0 * val + (s[i] - '0');

    // E.g., imagine s == 1234. val begins at 0.
    //
    // 1st iteration: val == 10.0 * 0 + (31 - 30) [ascii handling],
    // which is 1. So, val == 1.
    //
    // 2nd iteration: initially, val == 1. We're now evaluating
    // the second char in s, 2. So, val is set to 10.0 * 1 + 2,
    // or 12. Notice that we're beginning to build the number as
    // we'd expect to see it.
    //
    // 3rd iteration: initially, val == 12. Now evaluating 3. So,
    // val to be 10.0 * 12 + 3 == 120 + 3 == 123.
    //
    // 4th iteration: val == 1234, evaluating 4; giving 1234.
    //
    // Pretty clever!
  }

  // skip over decimals because the return type, double, includes
  // the decimal
  if (s[i] == '.') i++;

  // test for scientific notation
  if (s[i] == 'e' || s[i] == 'E') {
    // skip over e/E
    i++;
    // determine signed exponent
    negative_power = (s[i] == '-') ? 1 : 0;
    if (s[i] == '+' || s[i] == '-') i++;

    // convert and track decimal places via sci__power
    for (scientific_power = 1.0; isdigit(s[i]); i++) {
      val = 10 * val + (s[i] - '0');
      scientific_power *= 10.0;
      i++;
    }

    if (negative_power) {
      return (sign * val / scientific_power);
    } else {
      return (sign * val * scientific_power);
    }
  } else {
    // convert the chars after the '.' to float, tracking the number
    // of places deep the chars ago (i.e., what negative power, if any,
    // the final val will need to be raised to)
    for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
    }
    return sign * val / power;
  }

}
