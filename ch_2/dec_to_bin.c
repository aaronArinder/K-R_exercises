#include <stdio.h>
#define BIN_SIZE 65 // size of binary array: 64 bits and 1 terminating character

/*
 * based on udemy bitwise operators course
 * */

void populate_binary_num (int binaryNum[], int populating_bit) {
  int k = 0; // iter for populating binaryNum with 1s or 0s
  while (k < BIN_SIZE - 1) { // leave room for terminating character
    binaryNum[k] = populating_bit;
    k++;
  }
  binaryNum[BIN_SIZE] = '\0'; // terminating character
}

void print_dec_to_bin (int n) {
  // array to store binary number
  int binaryNum[BIN_SIZE];
  // counter for binary array
  int i = 0;
  int j;

  /*
   * TODO: ran into trouble when trying to use this for 2.6; problem is that it can't print signed
   * binary, such as -1; that is, 1111 1111 1111 1111, etc.; that's needed for masking to work
   * properly. Changed it to `'\0'`, but definitely needs to be fixed
   * */
  if (n > 0) {
    populate_binary_num (binaryNum, 0);
    while (n > 0) { // changed from > 0
      // storing remainder: this gives either 0, if num is divisible by 2, or 1, if it isn't, which
      // is great because it gives us the binary representation of the number
      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
    }
  }

  // print the binaryNum array in reverse order: the first 2 we divided by goes into the first
  // place, the second two the second place, and so on, because each division d represents d many
  // 2s--I think that makes sense(?)
  for (j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }
  printf("\n");
}
