// 1) Faça uma função que recebe a idade de uma pessoa em anos, meses e dias e retorna essa idade expressa em dias.

#include <stdio.h>
#include <stdlib.h>

void idadeEmDias(int anos, int meses, int dias, int* resultado){
  *resultado = (anos * 365) + (meses * 30) + dias;
}

int main(){
  
  int anos, meses, dias;
  scanf("%d %d %d", &anos, &meses, &dias);

  int* resultado = malloc(sizeof(int));
  idadeEmDias(anos, meses, dias, resultado);

  printf("A idade em dias e: %d\n", *resultado);

  return 0;
}