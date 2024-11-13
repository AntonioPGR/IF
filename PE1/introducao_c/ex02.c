#include <stdio.h>

int main(){
  double pi = 3.14159;
  double r;

  printf("Inser R: ");
  scanf("%f", &r);

  double area = pi * ( r * r );
  printf("A=%f\n", area);

  return 0;
}