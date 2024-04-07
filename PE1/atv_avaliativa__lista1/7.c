#include <stdio.h>

void main(){

  float temperatura_f;
  printf("Digite a temperatura em F°: ");
  scanf("%f", &temperatura_f);

  float celcius = (temperatura_f - 32) * 5 / 9;

  printf("Temperatura: %.2f°C \n", celcius);
}