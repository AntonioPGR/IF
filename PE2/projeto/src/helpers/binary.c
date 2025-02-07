#include <stdio.h>
#include <string.h>

int doesFileExists(char* FILENAME){
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL) {
    fclose(file);
    return 0;
  }
  fclose(file);
  return 1;
}

void writeBinaryFile(const char *FILENAME, void *data, size_t size) {
  FILE *file = fopen(FILENAME, "wb");
  if (file == NULL) {
    perror("Error opening file for writing");
    return;
  }
  fwrite(data, size, 1, file);
  fclose(file);
}

void appendBynaryFile(const char *FILENAME, void *data, size_t size) {
  FILE *file = fopen(FILENAME, "ab");
  if (file == NULL) {
    perror("Error opening file for writing");
    return;
  }
  fwrite(data, size, 1, file);
  fclose(file);
}

void readBinaryFile(const char *FILENAME, void *buffer, size_t size) {
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL) {
    memset(buffer, 0, size);
    return;
  }
  fread(buffer, size, 1, file);
  fclose(file);
}
