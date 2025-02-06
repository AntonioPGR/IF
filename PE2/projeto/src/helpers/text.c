#include <stdio.h>
#include <stdlib.h>

void closeFile(FILE *file){
  fclose(file);
}

FILE* createFile(const char *filename){
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    perror("Failed to create file");
    return NULL;
  }
  closeFile(file);
}

FILE* openFileForReadingOrCreate(const char *filename){
  FILE *file = fopen(filename, "r");
  if(file == NULL){
    file = createFile(filename);

    file = fopen(filename, "r");
    if(file == NULL){
      return NULL;
    }
  }
  return file;
}

FILE* openFileForWriting(const char *filename){
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    perror("Failed to create file");
    return NULL;
  }
  return file;
}

void writeInFile(const char *filename, char *message){
  FILE *file = openFileForWriting(filename);
  fprintf(file, "%s", message);
  closeFile(file);
}

char* readFile(const char *filename){
  FILE *file = openFileForReadingOrCreate(filename);
  char* content = (char *) malloc(1000 * sizeof(char));
  fgets(content, 1000, file);
  closeFile(file);
  return content;
}