#include <stdio.h>

int main(){

  int times, n, divisors = 0;
  
  scanf("%d", &times);

  for(int i = 0; i < times; i++){
    scanf("%d", &n);

    divisors = 0;
    for(int i = 2; i <= (n/2); i++){
      if(n % i == 0){
        divisors += i;
        break;
      }
    }

    if(divisors == 0) printf("%d eh primo\n", n);
    else printf("%d nao eh primo\n", n);
  }
  
  return 0;
}