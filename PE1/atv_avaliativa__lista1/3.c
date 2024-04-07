#include <stdio.h>

void main(){
  printHeader();
  breakLine();
  printOption(0, "Fim");
  printOption(1, "Inclui");
  printOption(2, "Altera");
  printOption(3, "Exclui");
  printOption(3, "Consulta");
  breakLine();
  int option = getOption();
}

void printHeader(){
  printf("Cadastro de clientes\n");
}

void breakLine(){
  printf("\n");
}

void printOption(int option_id, char label[]){
  printf("%d - %s\n", option_id, label);
}

int getOption(){
  int option;
  printf("Opção: ");
  scanf("%d", &option);
  return option;
}