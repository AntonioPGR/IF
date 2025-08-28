#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// i = linha
// j = coluna
// a[linha][coluna]

int main(){

  int n;
  printf("Ordem do sistema: ");
  scanf("%d", &n);

  float** a = (float**) malloc(n * sizeof(float*));
  for (int i = 0; i < n ; i++) a[i] = (float*) malloc(n * sizeof(float));
  
  float temp;
  printf("Matriz dos coeficientes: \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%f", &a[i][j]);
    }
  }

  float* b = (float*) malloc(n * sizeof(float));
  printf("Termos independentes: \n");
  for(int i = 0; i < n; i++){
    scanf("%f", &b[i]);
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (i == j) continue;
      float m = -a[i][j] / a[j][j];
      for (int k = 0; k < n; k++) {
        a[i][k] += m * a[j][k];
      }
      b[i] += m * b[j];
    }
  }

  float* x_final = (float*) malloc(n * sizeof(float));
  for (int i = 0; i < n; i++) {
    x_final[i] = b[i] / a[i][i];
  }
  
  printf("A solucao do sistema eh: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x_final[i]);
  printf("\n");

  for (int i = 0; i < n; i++) free(a[i]);
  free(a);
  free(b);
  free(x_final);

  return 0;
}