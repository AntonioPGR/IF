#include <stddef.h>

void readBinaryFile(const char *filename, void *buffer, size_t size);

void appendBynaryFile(const char *filename, void *data, size_t size);

void writeBinaryFile(const char *filename, void *data, size_t size);

long sizeOfBinaryFile(FILE *file);

int handleOpenBinaryFile(FILE **file, const char* operation, char* name);

int isBinaryFileEmpty(FILE *file, size_t size);

int handleBinaryFileEmpty(FILE *file, size_t size, char* message);

int getAmountInBinaryFile(FILE *file, int size);