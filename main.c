#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {

  FILE *csvptr = readCsv();

  parseCsv(csvptr);

  printf("Successed!");

  fclose(csvptr);

  return 0;
}
