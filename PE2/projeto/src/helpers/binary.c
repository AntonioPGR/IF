#include <stdio.h>

void writeBynaryFile(const char *filename, void *data, size_t size) {
  FILE *file = fopen(filename, "wr");
  if (file == NULL) {
    perror("Error opening file for writing");
    return;
  }
  fwrite(data, size, 1, file);
  fclose(file);
}

void appendBynaryFile(const char *filename, void *data, size_t size) {
  FILE *file = fopen(filename, "ab");
  if (file == NULL) {
    perror("Error opening file for writing");
    return;
  }
  fwrite(data, size, 1, file);
  fclose(file);
}

void readBinaryFile(const char *filename, void *buffer, size_t size) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fclose(file);
    buffer = NULL;
  }
  fread(buffer, size, 1, file);
  fclose(file);
}
