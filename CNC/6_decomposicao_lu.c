#include <stdio.h>
#include <stdlib.h>

float** allocateMatrix(int n) {
  float** m = malloc(n * sizeof(float*));
  for (int i = 0; i < n; i++) m[i] = malloc(n * sizeof(float));
  return m;
}

void solveInferiorTriangle(int n, float** a, float* b, float* x){
  for(int i = 0; i < n; i++){
    float soma = 0.0;
    for(int j = 0; j < i; j++){
      soma += a[i][j] * x[j];
    }
    x[i] = (b[i] - soma) / a[i][i];
  }  
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


int main(){

  int n;
  printf("Ordem do sistema: ");
  scanf("%d", &n);

  float **a = allocateMatrix(n);
  
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

  float **u = allocateMatrix(n);
  float **l = allocateMatrix(n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) l[i][j] = 1;
      else l[i][j] = 0;
      u[i][j] = a[i][j];
    }
  }


  for(int j = 0; j < (n-1); j++){
    for(int i = j+1; i < n; i++){
      float m = a[i][j] / a[j][j];
      for(int k = j; k < n; k++){
        a[i][k] -= m * a[j][k];
        u[i][k] = a[i][k];
        l[i][j] = m;
      }
    }
  }

  float* y = (float*) malloc(n * sizeof(float));
  solveInferiorTriangle(n, l, b, y);

  float* x = (float*) malloc(n * sizeof(float));
  solveSuperiorTriangle(n, u, y, x);
  
  printf("A solucao do sistema eh: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x[i]);
  printf("\n");

  return 0; 
}