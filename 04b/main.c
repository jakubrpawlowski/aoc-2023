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

void setbit(unsigned char *arr, int bit) { arr[bit / 8] |= 1 << (bit % 8); };

int isbiton(unsigned char *arr, int bit) {
  return (arr[bit / 8] & (1 << (bit % 8))) != 0;
};

int main() {
  const int size = 120;
  const int winsize = 10;

  char line[size];

  int winning[winsize];

  /* 104bits */
  unsigned char bitflags[13];
  memset(bitflags, 0, sizeof(bitflags));

  int power[winsize + 1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  int length = 0;

  int winlength = 0;

  int linetotal = 0;

  int total = 0;

  int section = 0;

  FILE *file = fopen("input", "r");

  if (NULL == file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while (fgets(line, size, file)) {
    while (length < size && '\0' != line[length] && '\n' != line[length]) {
      printf("%c", line[length]);

      switch (line[length]) {
      case '|':
        winlength = 0;
      case ':':
        section++;
        break;
      };

      switch (section) {
      case 0:
        break;
      case 1:
        if (isdigit(line[length])) {
          if (!isdigit(line[length + 1])) {
            winning[winlength] = wordInt(&line[length]);

            winlength++;
          };
        };
        break;
      case 2:
        if (isdigit(line[length])) {
          if (!isdigit(line[length + 1])) {
            setbit(bitflags, wordInt(&line[length]));
          };
        };
        break;
      };

      length++;
    };

    printf("\n");

    while (winlength < winsize) {
      if (isbiton(bitflags, winning[winlength])) {
        printf("T");

        linetotal++;
      } else {
        printf("F");
      };

      winlength++;
    };

    winlength = 0;

    printf(" %d\n", linetotal);

    while (linetotal > 0) {
      power[linetotal] = power[linetotal] + power[0];

      linetotal--;
    };

    printf("%d ", power[0] + 1);

    total = total + power[0];

    while (winlength < winsize) {
      power[winlength] = power[winlength + 1];

      winlength++;
    };

    power[winsize] = 1;

    printf("%d\n", total);

    winlength = 0;
    section = 0;
    memset(bitflags, 0, sizeof(bitflags));
    length = 0;
  };

  fclose(file);

  return 0;
};
