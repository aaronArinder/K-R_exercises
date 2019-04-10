#include <stdio.h>
#include <stdlib.h>

int main () {
  // source, target files
  FILE *fs, *ft;
  char ch;

  fs = fopen("", "r");
  ft = fopen("", "w");

  if (fs == NULL || ft == NULL) {
    printf("File cannot be opened");
    exit(1);
  }

  while ((ch = getc(fs)) != EOF) {
    putc(~ch, ft);
  }
  fclose(fs);
  fclose(ft);
  return 0;
}
