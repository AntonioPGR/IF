#include <stdio.h>

int main(){
  int n1;
  scanf("%i", &n1);
  int n2;
  scanf("%i", &n2);
  int n3;
  scanf("%i", &n3);
  int n4;
  scanf("%i", &n4);

  int diff = (n1*n2 - n3*n4);
  printf("DIFERENCA = %i \n", diff);

  return 0;
}