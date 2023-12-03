#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordInt(char *wordEnd) {
  int num = 0;
  char *prev = wordEnd - 1;

  num = *wordEnd - '0';

  if (isdigit(*prev)) {
    num = num + 10 * wordInt(prev);
  };

  return num;
};

char *intEnd(char *digit) {
  char *next = digit + 1;

  if (isdigit(*next)) {
    return intEnd(next);
  };

  return digit;
};

int main() {
  const int size = 160;

  int height = 0;
  int length = 0;

  char *prev = malloc(size);
  char *curr = malloc(size);
  char next[size];

  int total = 0;

  if (NULL == prev || NULL == curr) {
    perror("Failed to allocate memory");
    free(prev);
    free(curr);
    return 1;
  };

  FILE *file = fopen("input", "r");

  if (NULL == file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while (fgets(next, size, file)) {

    if (height > 1) {
      printf("prev %s", prev);
      printf("curr %s", curr);
      printf("next %s", next);

      while (length < size && '\0' != curr[length] && '\n' != curr[length]) {
        if (!isdigit(curr[length]) && '.' != curr[length]) {
          printf("%c", curr[length]);

          if (isdigit(curr[length + 1])) {
            total = total + wordInt(intEnd(&curr[length + 1]));
          };

          if (isdigit(curr[length - 1])) {
            total = total + wordInt(&curr[length - 1]);
          };

          if (isdigit(prev[length])) {
            total = total + wordInt(intEnd(&prev[length]));
          } else {
            if (isdigit(prev[length - 1])) {
              total = total + wordInt(&prev[length - 1]);
            };
            if (isdigit(prev[length + 1])) {
              total = total + wordInt(intEnd(&prev[length + 1]));
            };
          };

          if (isdigit(next[length])) {
            total = total + wordInt(intEnd(&next[length]));
          } else {
            if (isdigit(next[length - 1])) {
              total = total + wordInt(&next[length - 1]);
            };
            if (isdigit(next[length + 1])) {
              total = total + wordInt(intEnd(&next[length + 1]));
            };
          };
        };

        length++;
      };

      printf("\n");
      printf("%d\n", total);
    };

    char *temp = prev;
    prev = curr;
    curr = temp;

    memcpy(curr, next, size);

    length = 0;

    height++;
  };

  free(prev);
  free(curr);
  fclose(file);

  return 0;
};
