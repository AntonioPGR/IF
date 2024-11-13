#include <stdio.h>

int main(){

  int times, n, sum = 0;
  
  scanf("%d", &times);

  for(int i = 0; i < times; i++){
    scanf("%d", &n);
    sum = 0;
    for(int i = 1; i < n; i++){
      if(n % i == 0){
        sum += i;
      }
    }
    if(n == sum) printf("%d eh perfeito\n", n);
    else printf("%d nao eh perfeito\n", n);
  }
  
  return 0;
}