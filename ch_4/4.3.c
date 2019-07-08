/* Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%)
 * operator and provisions for negative numbers
 *
 * Based on the following link, I'm going to represent the negative sign with `n`, rather than
 * have it be part of a number (e.g.: 1, n, 1, - instead of -1, 1, -)
 * https://www.scss.tcd.ie/John.Waldron/3d1/rpn.pdf
 *
 *
 * EXAMPLES:
 *   100
 *   n
 *   10
 *   +
 *   =
 *          -90
 *
 *   10
 *   10
 *   %
 *   =
 *          0
 *
 *   0
 *   0
 *  \/ (esc. for comment)
 *   =
 *          error: zero divisor
 * */

#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);

// hoisting these from pop/push
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* reverse Polish calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      // subtraction not commutative; so, must guaruntee order
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      // must guarantee order
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push((int) pop() % (int) op2);
        } else
          printf("error: zero divisor\n");
        break;
      // need to figure out how to process input without \n
      case '\n':
        // used as a way to process input
        break;
      case '=':
        if (sp != 1) {
          printf("error: operands still available\n");
          break;
        } else {
          printf("\t%.8g\n", pop());
          break;
        }
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}


// see hoisted defs above
/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  // strip whitespace, but last iter will have a
  // operand, operator, or non-whitespace char
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  // end array
  s[1] = '\0';
  // if not a digit or decimal
  if (!isdigit(c) && c != '.')
    // not a number, and will be thrown to switch default
    return c;

  i = 0;
  // collect integer part
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  // end array
  s[i] ='\0';
  // if not EOF
  if (c != EOF)
    // then put the last read character into 'input' buffer
    ungetch(c);
  // return signal that we've a number
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

