#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  int lineLength = 0;
  int firstDigit = -1;
  int secondDigit = -1;
  int total;
  char line[80];
  
  FILE * file = fopen("input", "r");

  if (NULL == file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  };

  while(fgets(line, sizeof(line), file)) {
    while (lineLength < sizeof(line)
    && line[lineLength] != '\0'
    && line[lineLength] != '\n') {
      if (isdigit(line[lineLength])) {
        if (-1 == firstDigit) {
           firstDigit = line[lineLength] - '0';          
           printf("%d ", firstDigit);
        };

        secondDigit = line[lineLength] - '0';
      };

      lineLength++;
    };

    total = total + secondDigit + 10 * firstDigit;

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
