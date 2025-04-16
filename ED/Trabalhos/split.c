#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 100
#define MAX_TAMANHO 50

void para_minusculo(char* str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower((unsigned char) str[i]);
  }
}

int compara(const void* a, const void* b) {
  return strcmp(*(char**)a, *(char**)b);
}

int main() {
  char frase[] = "Eu gosto muito de estudar Estrutura de Dados e usar ponteiros e algo muito legal";
  char* matriz[MAX_PALAVRAS];
  int tamanho = 0;

  char* token = strtok(frase, " ");
  while (token != NULL && tamanho < MAX_PALAVRAS) {
    matriz[tamanho] = (char*)malloc(strlen(token) + 1);
    strcpy(matriz[tamanho], token);
    para_minusculo(matriz[tamanho]);
    tamanho++;
    token = strtok(NULL, " ");
  }

  qsort(matriz, tamanho, sizeof(char*), compara);

  for (int i = 0; i < tamanho; i++) {
    printf("%s ", matriz[i]);
    free(matriz[i]);
  }

  printf("\nFrase ordenada\n");

  return 0;
}
