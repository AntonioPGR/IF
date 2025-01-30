// 2) Faça uma função que recebe um vetor de ponto flutuante (criado estaticamente, ou seja, através da notação v[i]), e retorna qual é o maior e qual é o menor valor deste vetor.

#include <stdio.h>
#include <stdlib.h>

void maiorEMenor(float* arr, int size, float* maior, float* menor){
  for(int i = 0; i < size; i++){
    if(i == 0){
      *maior = arr[i];
      *menor = arr[i];
      continue;
    }
    if(arr[i] > *maior){
      *maior = arr[i];
      continue;
    }
    if(arr[i] < *menor){
      *menor = arr[i];
    }
  }
}

int main(){
  
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  float* vetor = malloc(n * sizeof(float));
  if(vetor == NULL){
    return 0;
  }
  
  for(int i = 0; i < n; i++){
    printf("Digite o valor %d: ", i);
    scanf("%f", &vetor[i]);
  }

  float maior, menor;
  maiorEMenor(vetor, n, &maior, &menor);

  printf("Maior valor: %.2f \n", maior);
  printf("Menor valor: %.2f \n", menor);

  return 0;
}