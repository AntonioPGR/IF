#include <stdio.h>

int main(){
  int code_1;
  int quantity_1;
  float price_1;
  scanf("%i %i %f", &code_1, &quantity_1, &price_1);
  
  int code_2;
  int quantity_2;
  float price_2;
  scanf("%i %i %f", &code_2, &quantity_2, &price_2);

  printf("VALOR A PAGAR: R$ %.2f \n", (quantity_1 * price_1) + (quantity_2 * price_2));

  return 0;
}