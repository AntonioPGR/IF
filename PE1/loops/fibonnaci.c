#include <stdio.h>

int main() {
  int n, value = 1, last_value = 1, aux;
  scanf("%d", &n);
    
  printf("0 1");
  for(int i = 0; i < n - 2; i++){
    printf(" %d", value);
    aux = last_value;
    last_value = value;
    value += aux;
  }

  printf("\n");

  return 0;
}