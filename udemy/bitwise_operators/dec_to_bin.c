#include <stdio.h>

void decToBinary (int n);

int main() {
  int x;
  printf("Enter any integer\t");
  scanf("%d", &x);
  printf("Binary representation is: ");
  decToBinary(x);
  printf("One's complement of %d is %d\n", x, ~x);
  return 0;
}

void decToBinary (int n) {
  // array to store binary number
  int binaryNum[100];
  // counter for binary array
  int i = 0;
  int j;
  while (n > 0) {
    // storing remainder: this gives either 0, if num is divisible by 2, or 1, if it isn't, which
    // is great because it gives us the binary representation of the number
    binaryNum[i] = n % 2;
    printf("binaryNum[i] i: %i, %i\n", binaryNum[i], i);
    n = n / 2;
    i++;
  }

  // print the binaryNum array in reverse order: why the reverse order, though?
  for (j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);
  }
  printf("\n");
}
