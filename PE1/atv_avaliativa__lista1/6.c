#include <stdio.h>

void main(){

  float n1;
  printf("Digite o 1° numero: ");
  scanf("%f", &n1);
  float n2;
  printf("Digite o 2° numero: ");
  scanf("%f", &n2);
  float n3;
  printf("Digite o 3° numero: ");
  scanf("%f", &n3);

  float media = (n1*1 + n2*2 + n3*3)/6;

  printf("Media: %.2f \n", media);
}