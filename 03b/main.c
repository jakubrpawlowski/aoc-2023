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

  int n = 1;
  int s = 1;
  int e = 1;
  int w = 1;
  int ne = 1;
  int nw = 1;
  int se = 1;
  int sw = 1;

  int gear = 0;

  long total = 0;

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
        if ('*' == curr[length]) {
          if (isdigit(curr[length + 1])) {
            e = wordInt(intEnd(&curr[length + 1]));
            gear = gear + 1;
          };

          if (isdigit(curr[length - 1])) {
            w = wordInt(&curr[length - 1]);
            gear = gear + 1;
          };

          if (isdigit(prev[length])) {
            n = wordInt(intEnd(&prev[length]));
            gear = gear + 1;
          } else {
            if (isdigit(prev[length - 1])) {
              nw = wordInt(&prev[length - 1]);
              gear = gear + 1;
            };
            if (isdigit(prev[length + 1])) {
              ne = wordInt(intEnd(&prev[length + 1]));
              gear = gear + 1;
            };
          };

          if (isdigit(next[length])) {
            s = wordInt(intEnd(&next[length]));
            gear = gear + 1;
          } else {
            if (isdigit(next[length - 1])) {
              sw = wordInt(&next[length - 1]);
              gear = gear + 1;
            };
            if (isdigit(next[length + 1])) {
              se = wordInt(intEnd(&next[length + 1]));
              gear = gear + 1;
            };
          };

          if (2 == gear) {
            total = total + n * s * e * w * nw * ne * sw * se;
          };

          gear = 0;

          n = 1;
          s = 1;
          e = 1;
          w = 1;
          ne = 1;
          nw = 1;
          se = 1;
          sw = 1;
        };

        length++;
      };

      printf("%ld\n", total);
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
