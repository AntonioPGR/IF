#include <stdio.h>

FILE* readFile(const char *filename){
  FILE *file = fopen(filename, "r");
  if(file == NULL){
    file = fopen(filename, "w");
    if (file == NULL) {
      perror("Failed to create file");
      return NULL;
    }
    fclose(file);
    file = fopen(filename, "r");
  }
  return file;
}