#include <stdio.h>

void main(){

  float n1;
  printf("Digite a 1° nota: ");
  scanf("%f", &n1);
  float n2;
  printf("Digite a 2° nota: ");
  scanf("%f", &n2);
  float n3;
  printf("Digite a 3° nota: ");
  scanf("%f", &n3);
  float n4;
  printf("Digite a 4° nota: ");
  scanf("%f", &n4);

  float media = (n1*1 + n2*2 + n3*3 +n4*4)/10;

  printf("Media: %.2f \n", media);
}