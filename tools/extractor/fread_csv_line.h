#ifndef CSV_DOT_H_INCLUDE_GUARD
#define CSV_DOT_H_INCLUDE_GUARD

#define CSV_ERR_LONGLINE 0
#define CSV_ERR_NO_MEMORY 1

int fread_csv_alloc(int size);
void fread_csv_free(void);
char *fread_csv_line(FILE *fp, int *done, int *err);

#endif
