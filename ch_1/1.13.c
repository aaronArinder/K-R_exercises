#include <stdio.h>
/*
 * write a program to print a histogram of the lengths of words in its input. It's easy to draw
 * the historgram with the bars horizontal; a vertical orientation is more challenging.
 * */


void main()
{
  /*
   * while getchar() not EOF, count each char until whitespace
   * when whitespace, start a new count in a new array
   * assign arrays at end?
   */
  int word_length = 15;
  int c, counter, arr[word_length], h, i, j, k;
  counter = 0;

  for (h = 0; h < word_length; h++) {
    arr[h] = 0;
  }

  while ((c = getchar()) != EOF) {
    // while not whitespace, count length
    if (c != ' ' && c != '\n') {
      counter++;
    // if whitespace
    } else {
      // update array of lengths by incrementing index
      arr[counter]++;
      // reset counter to 0
      counter = 0;

    }
  }

  printf("words\tlengths\n");
  for (i = 0; i < word_length; i++) {
    // print column name
    printf("%d:\t", i);
    for (j = 0; j < arr[i]; j++) {
      // print row values
      printf("%s", "|");
    }
    printf("\n");
  }
}
