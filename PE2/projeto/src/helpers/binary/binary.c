#include <stdio.h>
#include <string.h>
#include "../terminal/terminal.h"

// Abre meu arquivo de acordo com a operação passada
int handleOpenBinaryFile(FILE **file, const char* operation, char* name) {
  *file = fopen(name, operation);
  if (*file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    cleanBufferNContinue();
    return 0;
  }
  return 1;
}

// Dita o tamanho do arquivo
long sizeOfBinaryFile(FILE *file) {
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file); 
  return size;
}

int getAmountInBinaryFile(FILE *file, int size) {
  return sizeOfBinaryFile(file) / size;
}

int isBinaryFileEmpty(FILE *file, size_t size){
  int amount = getAmountInBinaryFile(file, size);
  if (amount == 0) return 1;
  return 0;
}

int handleBinaryFileEmpty(FILE *file, size_t size, char* message){
  if (isBinaryFileEmpty(file, size)) {
    printf("Nenhum %s cadastrado!\n\n", message);
    cleanBufferNContinue();
    return 1;
  }
  return 0;
}

