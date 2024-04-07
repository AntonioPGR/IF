#include <math.h>
#include <stdio.h>

void main(){

  double n1;
  printf("Digite o comprimento: ");
  scanf("%lf", &n1);
  double n2;
  printf("Digite o comprimento: ");
  scanf("%lf", &n2);

  printf("O comprimento da diagonal é: %.2f \n", sqrt(pow(n1, 2) + pow(n2, 2)));
}