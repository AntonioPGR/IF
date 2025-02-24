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

void getInputLine(char* label, int max, char input[max]){
  cleanInputBuffer();
  printf("%s", label);
  fgets(input, max, stdin);
  if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
}