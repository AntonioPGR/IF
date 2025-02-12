#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void cleanScreen(){
  printf("\e[1;1H\e[2J");
}

void cleanInputBuffer(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

void pressEnterToContinue(){
  printf("Pressione ENTER para continuar...");
  getchar();
}

void cleanBufferNContinue(){
  cleanInputBuffer();
  pressEnterToContinue();
}

char* getInputLine(int max_size, char* label){
  char* line = (char *) malloc(max_size*sizeof(char));
  printf("%s", label);
  cleanInputBuffer();
  fgets(line, max_size, stdin);
  line[strcspn(line, "\n")] = '\0';
  return line;
}

int scanInteger(char* label){
  int number;
  printf("%s", label);
  scanf("%d", &number);
  return number;
}

void printTableLine(int size){
  printf("|");
  for(int i = 0; i < (size - 2); i++){
    printf("-");
  }
  printf("|");
  printf("\n");
}
