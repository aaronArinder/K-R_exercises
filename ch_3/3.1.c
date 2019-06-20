/*
 * Our binary search makes two tests inside the loop, when one would suffice (at the price of
 * more tests outside). Write a version with only one test inside the loop and measure the
 * difference in run-time.
 *
 * binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
 * int binsearch(int x, int v[], int n)
 * {
 *   int low, high, mid;
 *   low = 0;
 *   high = n - 1;
 *   while (low <= high) {
 *     mid = (low + high) / 2;
 *     if ( x < v[mid])
 *       high = mid - 1;
 *     else if (x > v[mid])
 *       low = mid + 1;
 *     else //found match
 *       return mid;
 *   }
 *   return -1; // no match
 * }
 *
 * */

#include <stdio.h>
#include <time.h> // for clock_t

int binsearch_old (int num_to_find, int arr_nums[], int total_elms);
int binsearch_new (int x, int v[], int n);

void main ()
{
  int num_to_find = 5;
  // should obviously be bigger
  int arr_nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
  int total_elms = 10;
  unsigned long int times_to_run = 100000000000000;

  clock_t begin_old = clock();
  for (int i = 0; i < times_to_run; i++) {
    binsearch_old(num_to_find, arr_nums, total_elms);
  }
  clock_t end_old = clock();
  double time_spent_old = (double)(end_old - begin_old) / CLOCKS_PER_SEC;
  printf("result :: %d\n", binsearch_old(num_to_find, arr_nums, total_elms));
  printf("time spent old: %f\n", time_spent_old);

  clock_t begin_new = clock();
  for (int i = 0; i < times_to_run; i++) {
    binsearch_new(num_to_find, arr_nums, total_elms);
  }
  clock_t end_new = clock();
  double time_spent_new = (double)(end_new - begin_new) / CLOCKS_PER_SEC;
  printf("result :: %d\n", binsearch_new(num_to_find, arr_nums, total_elms));
  printf("time spent new: %f\n", time_spent_new);

  printf("difference (old - new): %f\n", time_spent_old - time_spent_new);
}

int binsearch_old (int num_to_find, int arr_nums[], int total_elms)
{

  int low, high, mid;
  low = 0;
  high = total_elms - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (num_to_find < arr_nums[mid])
      high = mid - 1;
    else if (num_to_find > arr_nums[mid])
      low = mid + 1;
    else //found match
      return mid;
  }
  return -1; // no match
}

int binsearch_new (int num_to_find, int arr_nums[], int total_elms)
{
  int low, high, mid;
  low = 0;
  high = total_elms - 1;

  mid = (low + high) / 2;
  while (low <= high && num_to_find != arr_nums[mid]) {
    if (num_to_find < arr_nums[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  if (num_to_find == arr_nums[mid]) {
    return mid;
  } else {
    return -1; // no match
  }
}
