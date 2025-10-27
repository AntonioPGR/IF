#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bringLineUp(int start_index, int n, float** a, float* b) {
  int greatest_line = start_index;
  for (int i = start_index + 1; i < n; i++) {
    if (fabsf(a[i][start_index]) > fabsf(a[greatest_line][start_index])) greatest_line = i;
  }
  float* temp = a[greatest_line];
  a[greatest_line] = a[start_index];
  a[start_index] = temp;

  float temp_b = b[greatest_line];
  b[greatest_line] = b[start_index];
  b[start_index] = temp_b;
}

void solveSuperiorTriangle(int n, float** a, float* b, float* x){
  for(int i = n-1; i >= 0; i--){
    float soma = 0.0;
    for(int j = i+1; j < n; j++){
      soma += a[i][j] * x[j];
    }
    x[i] = (b[i] - soma) / a[i][i];
  }  
}

void solveGaussLine(int j, int n, float** a, float* b){
  for(int i = j+1; i < n; i++){
    float m = - (a[i][j] / a[j][j]);
    for(int k = j; k < n; k++){
      a[i][k] += m * a[j][k];
    }
    b[i] += m * b[j];
  }
}

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

  for(int j = 0; j < (n-1); j++){
    bringLineUp(j, n, a, b);
    solveGaussLine(j, n, a, b);
  }

  float* x = (float*) malloc(n * sizeof(float));
  solveSuperiorTriangle(n, a, b, x);
  
  printf("A solução do sistema é: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x[i]);
  printf("\n");

  return 0;
}