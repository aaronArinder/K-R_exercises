#include <stdio.h>
#define BIN_SIZE 64 // size of binary array: 64 bits and 1 terminating character

/*
 * based on udemy bitwise operators course; extended (dramatically) to support negative
 * decimal numbers
 * */

void convert_binary_and_print (int decNum, int binaryNum[]);

void print_dec_to_bin (int decNum) {
  // array to store binary number
  if (decNum >= 0) {
    int binaryNum[BIN_SIZE] = {0}; // don't need rest operator b/c it defaults to 0
    convert_binary_and_print(decNum, binaryNum);
  } else if (decNum < 0) {
    // apparently this is the OG of spread operators: GNU extension of c89 for gcc, grill
    int binaryNum[BIN_SIZE] = {[0 ...BIN_SIZE - 1] = 1};
    convert_binary_and_print(decNum, binaryNum);
  }
}

void convert_binary_and_print (int decNum, int binaryNum[]) {

  /* holy shit, okay; see the notes on the binary system in ../udemy/bitwise_operators for a deeper
   * explanation of this, but the big idea is that when representing negative numbers using binary,
   * we use the two's complement, which is, essentially, letting (in, e.g., a 4-bit representation)
   * 1111 represent -1, such that getting the negative counterpart of any positive number requires
   * taking the one's complement and then adding 1 because the one's complement is a bit flipper,
   * and it's ignorant of our decision to let 1111 represent -1 rather than -0, which is the one's
   * complement of 0.
   * */

  // counter for binary array
  int i = 0;
  while (decNum != 0) {
    int bin;
    if (decNum < 0) {
      // if negative dec, add 1 to account for 2s complement representation (see above); take one's
      // complement to remove sign
      bin = ~(decNum + 1) % 2;
      // if bin ending up being -1, it's because decNum was -1; adding 1 to -1 gives 0, and taking
      // the one's complement of 0 gives -1; see the notes in ../udemy/bitwise_operators for a
      // deeper explanation of why ~0 gives 1111
      if (bin == -1) {
        bin = 0;
      }
    } else {
      bin = decNum % 2;
    }
    binaryNum[i] = bin;
    decNum = decNum / 2;
    i++;
  }

  // print the binaryNum array in reverse order: the first 2 we divided by goes into the first
  // place, the second two the second place, and so on, because each division d represents d many
  // 2s--I think that makes sense(?)
  for (int j = BIN_SIZE - 1; j >= 0; j--) {
    if ((j + 1) % 4 == 0) printf(" "); // visually break bits into groups of 4
    printf("%d", binaryNum[j]);
  }
  printf("\n");
}
