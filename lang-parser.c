#include <stdio.h>
#include <stdlib.h>
#define CSVNAME "lang.csv"

FILE *readCsv();
void parseCsv(FILE *csvptr);
int countCsvRows(FILE *csvptr);
int countCsvColumns(FILE *csvptr);

int main() {

  FILE *csvptr = readCsv();

  parseCsv(csvptr);

  printf("\nSuccessed!");

  fclose(csvptr);

  return 0;
}

/* Read the csv file and return file stream */
FILE *readCsv()
{
  FILE *csvptr;

  csvptr = fopen(CSVNAME, "r");

  if (!csvptr) {
    fprintf(stderr, "Can't open csv file. \n");
    exit(EXIT_FAILURE);
  }

  return csvptr;
}

/* handleCsv file */
void parseCsv(FILE *csvptr)
{
  int c;
  int rowsCount = countCsvRows(csvptr);
  int columnsCount = countCsvColumns(csvptr);

  while((c = getc(csvptr)) != EOF) {
    // printf("%c", c);
  }

  rewind(csvptr);

  // printf("\nTotally rows: %d", rowsCount);
  printf("\nTotally columns: %d", columnsCount);
}

int countCsvRows(FILE *csvptr)
{
  int rowsCount = 0;
  int c = getc(csvptr);

  if (c == EOF)
    return 0;

  while(c != EOF) {
    if (c == '\n') {
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

