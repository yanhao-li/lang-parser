#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
  static const char csvPath[] = "./lang.csv";
  FILE *csvptr = readCsv(csvPath);

  parseCsv(csvptr);

  printf("\nSuccessed!");

  fclose(csvptr);
  return 0;
}
