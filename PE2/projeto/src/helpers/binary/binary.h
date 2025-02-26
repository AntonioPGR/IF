#include <stddef.h>

long sizeOfBinaryFile(FILE *file);

int handleOpenBinaryFile(FILE **file, const char* operation, char* name);

int isBinaryFileEmpty(FILE *file, size_t size);

int handleBinaryFileEmpty(FILE *file, size_t size, char* message);

int getAmountInBinaryFile(FILE *file, int size);