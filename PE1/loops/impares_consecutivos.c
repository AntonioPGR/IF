#include <stdio.h>

int main(){

  int n1, n2, lower, bigger, sum=0;
  scanf("%d", &n1);
  scanf("%d", &n2);

  if(n1 > n2){
    lower = n2;
    bigger = n1;
  } else {
    lower = n1;
    bigger = n2;
  }

  if(lower % 2 == 0) lower += 1;
  else lower += 2;

  for(int i = lower; bigger > i ;i += 2){
    sum += i;
  }

  printf("%d\n", sum);

  return 0;
}