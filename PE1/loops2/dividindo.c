#include <stdio.h>

int main(){

  int n;
  float n1, n2;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%f %f", &n1, &n2);
    if(n2 == 0) printf("divisao impossivel\n");
    else printf("%.1f\n", n1 / n2);
  }


  return 0;
}