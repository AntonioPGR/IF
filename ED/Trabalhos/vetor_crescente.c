#include <stdio.h>
#include <stdlib.h>

int main(){

  int v[] = {1, 2, 4, 6, 7, 8, 100, 10, 11, 12};
  int n = sizeof(v)/sizeof(v[0]);

  int last = 0;
  int in_order = 1; 
  for(int i = 1; i < n; i++){
    if(v[i] < last){
      in_order = 0;
      break;
    }
    last = v[i];
  }

  if(in_order){
    printf("O vetor esta em ordem crescente.\n");
  } else {
    printf("O vetor nao esta em ordem crescente.\n");
  }

  return 0;
}