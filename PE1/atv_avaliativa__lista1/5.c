#include <stdio.h>

void main(){

  int idade;
  printf("Digite sua idade: ");
  scanf("%i", &idade);

  int soma = idade * (idade - 1) / 2;

  printf("Somatório das idades: %d \n", soma);
}