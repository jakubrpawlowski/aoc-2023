#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lineLength = 0;
  int firstDigit = -1;
  int secondDigit = -1;
  int total;
  char line[80];

  FILE *file = fopen("input", "r");

  if (NULL == file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while (fgets(line, sizeof(line), file)) {
    while (lineLength < sizeof(line) && line[lineLength] != '\0' &&
           line[lineLength] != '\n') {
      if (isdigit(line[lineLength])) {
        if (-1 == firstDigit) {
          firstDigit = line[lineLength] - '0';
        };

        secondDigit = line[lineLength] - '0';
      };

      if (isalpha(line[lineLength])) {
        switch (line[lineLength]) {
        case 'o':
          if ('n' == line[lineLength + 1] && 'e' == line[lineLength + 2]) {
            if (-1 == firstDigit) {
              firstDigit = 1;
            };
            secondDigit = 1;
          };
          break;
        case 't':
          if ('w' == line[lineLength + 1] && 'o' == line[lineLength + 2]) {
            if (-1 == firstDigit) {
              firstDigit = 2;
            };
            secondDigit = 2;
          };
          if ('h' == line[lineLength + 1] && 'r' == line[lineLength + 2] &&
              'e' == line[lineLength + 3] && 'e' == line[lineLength + 4]) {
            if (-1 == firstDigit) {
              firstDigit = 3;
            };
            secondDigit = 3;
          };
          break;
        case 'f':
          if ('o' == line[lineLength + 1] && 'u' == line[lineLength + 2] &&
              'r' == line[lineLength + 3]) {
            if (-1 == firstDigit) {
              firstDigit = 4;
            };
            secondDigit = 4;
          };
          if ('i' == line[lineLength + 1] && 'v' == line[lineLength + 2] &&
              'e' == line[lineLength + 3]) {
            if (-1 == firstDigit) {
              firstDigit = 5;
            };
            secondDigit = 5;
          };
          break;
        case 's':
          if ('i' == line[lineLength + 1] && 'x' == line[lineLength + 2]) {
            if (-1 == firstDigit) {
              firstDigit = 6;
            };
            secondDigit = 6;
          };
          if ('e' == line[lineLength + 1] && 'v' == line[lineLength + 2] &&
              'e' == line[lineLength + 3] && 'n' == line[lineLength + 4]) {
            if (-1 == firstDigit) {
              firstDigit = 7;
            };
            secondDigit = 7;
          };
          break;
        case 'e':
          if ('i' == line[lineLength + 1] && 'g' == line[lineLength + 2] &&
              'h' == line[lineLength + 3] && 't' == line[lineLength + 4]) {
            if (-1 == firstDigit) {
              firstDigit = 8;
            };
            secondDigit = 8;
          };
          break;
        case 'n':
          if ('i' == line[lineLength + 1] && 'n' == line[lineLength + 2] &&
              'e' == line[lineLength + 3]) {
            if (-1 == firstDigit) {
              firstDigit = 9;
            };
            secondDigit = 9;
          };
          break;
        case 'z':
          if ('e' == line[lineLength + 1] && 'r' == line[lineLength + 2] &&
              'o' == line[lineLength + 3]) {
            if (-1 == firstDigit) {
              firstDigit = 0;
            };
            secondDigit = 0;
          };
          break;
        }
      }

      lineLength++;
    };

    total = total + secondDigit + 10 * firstDigit;

    printf("%d ", firstDigit);
    printf("%d ", secondDigit);
    printf("%d ", total);
    printf("%s", line);

    lineLength = 0;
    firstDigit = -1;
    secondDigit = -1;
  };

  fclose(file);

  printf("%d\n", total);

  return 0;
}
