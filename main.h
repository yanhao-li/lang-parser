#include <stdio.h>
#include <stdlib.h>

FILE *readCsv();
void parseCsv(FILE *csvptr);
int countCsvRows(FILE *csvptr);
int countCsvColumns(FILE *csvptr);
