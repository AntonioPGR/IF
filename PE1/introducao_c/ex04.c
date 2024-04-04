#include <stdio.h>

int main(){
  int A;
  printf("Insert A: ");
  scanf("%i", &A);

  int B;
  printf("Insert B: ");
  scanf("%i", &B);

  int PROD = A * B;
  printf("PROD = %i \n", PROD);

  return 0;
}