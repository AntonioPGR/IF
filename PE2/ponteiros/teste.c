#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int *a;

  a = (int*)malloc(3*sizeof(int));

  for(int i=0; i<3; i++){
    *a = i+1;
    a++;
  }

  a = a-3;
  for(int i=0; i<3; i++){
    printf("%d ", *(a+i));
  }

  return 0;
}