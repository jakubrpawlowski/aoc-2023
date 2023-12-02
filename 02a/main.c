#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int wordInt(char *wordEnd) {
  int num = 0;
  char *prev = wordEnd - 1;

  num = *wordEnd - '0';

  if (isdigit(*prev)) {
    num = num + 10 * wordInt(prev);
  };

  return num;
};

int main() {
  char line[180];
  int length = 0;

  int num = 0;
  int red = 0;
  int green = 0;
  int blue = 0;
  int id = 0;

  int fail = 0;
  int total = 0;

  FILE *file = fopen("input", "r");

  if (NULL == file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while (fgets(line, sizeof(line), file)) {
    while (length < sizeof(line) && line[length] != '\0' &&
           line[length] != '\n' && fail != 1) {

      if (isdigit(line[length])) {
        if (!isdigit(line[length + 1])) {
          num = wordInt(&line[length]);
        };
      };

      switch (line[length]) {
      case 'r':
        red = num;
        num = 0;
        break;
      case 'g':
        green = num;
        num = 0;
        break;
      case 'b':
        blue = num;
        num = 0;
        break;
      case ':':
        id = num;
        num = 0;
      case ';':
        red = 0;
        green = 0;
        blue = 0;
        num = 0;
        break;
      };

      if (red > 12 || green > 13 || blue > 14) {
        fail = 1;

        printf("red %d green %d blue %d\n", red, green, blue);
      };

      length++;
    }

    if (fail == 0) {
      total = total + id;
    };

    length = 0;

    num = 0;
    red = 0;
    green = 0;
    blue = 0;
    id = 0;

    printf("%d ", fail);
    fail = 0;
    printf("%s", line);
  }

  fclose(file);

  printf("%d\n", total);

  return 0;
};
