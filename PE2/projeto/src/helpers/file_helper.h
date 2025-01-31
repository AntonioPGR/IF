#include <stdio.h>

FILE* createFile(const char *filename);

FILE* openFileForReadingOrCreate(const char *filename);

char* readFile(const char *filename);

void closeFile(FILE *file);

FILE* openFileForWriting(const char *filename);

void writeInFile(const char *filename, char *message);