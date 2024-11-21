#include <stdio.h> 

int pow2(int power){
  if(power == 0) return 1;
  int base = 1;
  for(int i = 0; i<power; i++){
    base *= 2;
  }
  return base;
}

int main() {

  int n;
  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      printf("%d ", pow2(power));
    }
    printf("\n");
  }

  return 0;
}
