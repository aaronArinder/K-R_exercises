/* Add commands for handling variables. (It's easy to provide twenty-six variables with
 * single-letter names). Add a variable for the most recently printed value.  *
 * Notes
 *   - not really sure what 'add commands for handling variables' means. What sort of handling? It
 *     doesn't seem like using variables with operations, unless those variables already stand for
 *     something (i.e., no algebra).
 *     - going to implement referencing the topmost value in the values array with a variable, and
 *       call that good.
 *
 *   - 26 vars via letters is a lot; I already used some letters for commands, and will likely use
 *     more letters for other commands. So, going to do 5 vars from letters, starting with z and
 *     moving backward to u: u,v,w,x,y,z.
 *     - Ideally, vars would be set with an input like this: 'var a', for any a, such as
 *       'var result_from_blah'. 4.10 refactors the calculator to read whole lines, so maybe that
 *       could be implemented then.
 *
 *
 * !IMPORTANT: this must be compiled with `-lm` to link the standard math library:
 *   https://stackoverflow.com/questions/5005363/undefined-reference-to-sin
 * */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

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
  double op1, op2, handled_val;
  char s[MAXOP];
  // variable handling
  char var;
  char vars[6][2] = {
    { 'u' },
    { 'w' },
    { 'x' },
    { 'y' },
    { 'z' }
  };
  int var_avail_idx = 0;

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
      // make top element negative
      case 'n':
        push(pop() * -1 );
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
        // if the next available position isn't 1, input went afoul
        if (sp != 1) {
          printf("error: operands or operators still available\n");
          break;
        } else {
          printf("\t%.8g\n", pop());
          break;
        }
      // reference topmost val in vals with a variable, printing the variable used
      case '_':








        // left off here: right idea, but incomplete implementation: pushing to vals doesn't
        // work as expected






        var = vars[var_avail_idx][0];
        vars[var_avail_idx][1] = pop();
        push(var);
        printf("var: %c\n", var);
        int val2 = vars[var_avail_idx][1];
        printf("val2: %i\n", val2);
        var_avail_idx++;

        //push(pop() * -1 );
        break;
      // print top element without popping it off
      case 'p':
        printf("\t%.8g\n", val[sp - 1]);
        break;
      // duplicate top element
      case 'd':
        push(val[sp - 1]);
        break;
      // swap top two elements
      case 's':
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
        break;
      // clear stack
      case 'c':
        while (sp > 0)
          pop();
        printf("stack cleared\n");
        break;
      // sine of top elm
      case 'S':
        push(sin(pop()));
        break;
      // cosine
      case 'C':
        push(cos(pop()));
        break;
      // power
      case 'P':
        op2 = pop();
        push(pow(pop(), op2));
        break;
      // tangent
      case 't':
        push(tan(pop()));
        break;
      // exponential function: u for Euler
      case 'u':
        push(exp(pop()));
        break;
      // natural log
      case 'l':
        push(log(pop()));
        break;
      // base 10 log
      case 'L':
        push(log10(pop()));
        break;
      // absolute value
      case 'a':
        push(fabs(pop()));
        break;

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
    // not a number, handle with switch
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

