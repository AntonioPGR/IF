#include <stddef.h>

int doesFileExists(char* FILENAME);

void readBinaryFile(const char *filename, void *buffer, size_t size);

void appendBynaryFile(const char *filename, void *data, size_t size);

void writeBinaryFile(const char *filename, void *data, size_t size);

long sizeOfBinaryFile(FILE *file);

int getAmountInBinaryFile(FILE *file, int size);