/*
 * functionify the temp conversion program from section 1.02
 * */

#include <stdio.h>

float convert_fahr_cels(float); // function prototype

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; // lower limit of temp table
  upper = 300; // upper limit of temp table
  step = 20; // step size

  fahr = lower;
  while (fahr <= upper) {
    celsius = convert_fahr_cels(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

float convert_fahr_cels(float fahr)
{
  return (5.0/9.0) * (fahr - 32.0);
}




