#include <stdio.h>

int main() {
  float idade, sum = 0, quantity = 0;
  
  while(1){
    scanf("%f", &idade);
    if(idade < 0) break;
    sum += idade;
    quantity++;
  }

  float media = sum / quantity;
  printf("%.2f\n", media);

  return 0;
}