#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/* Read the csv file and return file stream */
FILE *readCsv(const char csvPath[])
{
  FILE *csvptr;

  csvptr = fopen(csvPath, "r");

  if (!csvptr) {
    fprintf(stderr, "Can't open csv file. \n");
    exit(EXIT_FAILURE);
  }

  return csvptr;
}

/* handleCsv file */
void parseCsv(FILE *csvptr)
{
  int rowsCount = countCsvRows(csvptr);
  int columnsCount = countCsvColumns(csvptr);


  printCsv(csvptr);

  printf("\nTotally rows: %d", rowsCount);
  printf("\nTotally columns: %d", columnsCount);
}

void printCsv(FILE *csvptr)
{
  char *line = NULL;
  size_t len = 0;

  while((getline(&line, &len, csvptr)) != -1) {
    printf("%s", line);
  }

  free(line);
  exit(EXIT_SUCCESS);
}






int countCsvRows(FILE *csvptr)
{
  int rowsCount = 0;
  int c = getc(csvptr);

  if (c == EOF)
    return 0;

  while(c != EOF) {
    if (c == '\r') {
      rowsCount++;
    }
    c = getc(csvptr);
  }

  rewind(csvptr);
  return rowsCount + 1;
}

int countCsvColumns(FILE *csvptr)
{
  int columnsCount = 0;
  int c = getc(csvptr);

  while(c != EOF && c != '\n') {
    if (c == ',')
      columnsCount++;
    c = getc(csvptr);
  }
  
  rewind(csvptr);
  return columnsCount + 1;
}
