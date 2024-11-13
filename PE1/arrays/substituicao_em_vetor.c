#include <stdio.h>

int main(){

  int array[10], n;

  for(int i = 0; i < 10; i++){
    scanf("%d", &n);
    if(n <= 0) n = 1;
    array[i] = n;
  }

  for(int i = 0; i < 10; i++){
    printf("X[%d] = %d\n", i, array[i]);
  }

  return 0;
}