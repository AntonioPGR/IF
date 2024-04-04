#include <stdio.h>

int main(){
  float n1;
  scanf("%.1f", &n1);

  float n2;
  scanf("%.1f", &n2);
  
  float n3;
  scanf("%.1f", &n3);

  float avarage = ((n1*2)+(n2*3)+(n3*5))/10;
  printf("MEDIA = %.1f \n", avarage);

  return 0;
}