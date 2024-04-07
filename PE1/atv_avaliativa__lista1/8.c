#include <math.h>
#include <stdio.h>

void main(){

  double number;
  printf("Digite um numero: ");
  scanf("%lf", &number);

  printf("Log de %.2lf na base 10: %.2f\n", number, log10(number));
  printf("%.2lf elevado a 5: %.2f \n", number, pow(number, 5));
  printf("Raiz de %.2lf: %.2f \n", number, sqrt(number));
}