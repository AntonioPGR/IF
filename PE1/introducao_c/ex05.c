#include <stdio.h>

int main(){
  float n1;
  printf("Insert first: ");
  scanf("%f", &n1);

  float n2;
  printf("Insert last: ");
  scanf("%f", &n2);

  float avarage = ((n1*3.5)+(n2*7.5))/10;
  printf("MEDIA = %.5f \n", avarage);

  return 0;
}