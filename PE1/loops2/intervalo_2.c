#include <stdio.h>

int main(){

  int n, in = 0, out = 0, current;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &current);
    if(current >= 10 && current <= 20) in ++;
    else out++;
  }

  printf("%d in\n", in);
  printf("%d out\n", out);

  return 0;
}