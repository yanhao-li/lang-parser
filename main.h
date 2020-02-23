#include <stdio.h>
#include <stdlib.h>

FILE *readCsv(const char csvPath[]);
void parseCsv(FILE *csvptr);
void printCsv(FILE *csvptr);
int countCsvRows(FILE *csvptr);
int countCsvColumns(FILE *csvptr);
