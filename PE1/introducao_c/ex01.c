#include <stdio.h>

int main(){
  int A;
  printf("Insert A: ");
  scanf("%i", &A);

  int B;
  printf("Insert B: ");
  scanf("%i", &B);

  int X = A + B;
  printf("X = %i \n", X);

  return 0;
}