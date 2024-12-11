// 3) Faça uma função que recebe três variáveis A, B e C e troca seus valores de modo que A passe  aconter o menor valor, B contenha o valor intermediário e C passe a conter o maior.

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b, int* c){
  int arr[3] = {*a, *b, *c};
  int temp;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(arr[i] < arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  *a = arr[0];
  *b = arr[1];
  *c = arr[2];
}

int main(){
  int* a = malloc(sizeof(int));
  int* b = malloc(sizeof(int));
  int* c = malloc(sizeof(int));

  scanf("%d %d %d", a, b, c);

  swap(a, b, c);

  printf("%d %d %d \n", *a, *b, *c);

  return 0;
}