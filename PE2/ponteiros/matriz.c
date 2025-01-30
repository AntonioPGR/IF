// 3) Faça um programa que recebe as dimensões de uma matriz quadrada, a instancie na heap e invoque duas funções: i) uma que preenche a matriz com valores aleatórios de 1 a 100, e ii) uma que calcule a soma dos elementos de sua diagonal principal.

#include <stdio.h>
#include <stdlib.h>

int main(){

  int n;
  scanf("%d", &n);

  int** matriz = malloc(n_linhas * sizeof(int*));
  for(int i = 0; i < n_linhas; i++){
    matriz[i] = malloc(n_colunas * sizeof(int));
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matriz[i][j] = i+j;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

}