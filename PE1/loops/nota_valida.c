#include <stdio.h>

int main(){

  float n, sum=0, times = 0, media;
  
  while(times != 2){
    scanf("%f", &n);
    if(n < 0 || n > 10) printf("nota invalida\n");
    else{
      sum += n;
      times++;
    }
  }

  media = sum / 2;
  printf("media = %.2f\n", media);
  
  return 0;
}