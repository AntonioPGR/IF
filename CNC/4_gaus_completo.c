#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findGreatestModule(int start_index, int n, float** a, int* grt_i, int* grt_j){
  *grt_i = start_index;
  *grt_j = start_index;
  for (int i = start_index; i < n; i++) {
    for(int j = start_index; j < n; j++) {
      if (fabsf(a[i][j]) > fabsf(a[*grt_i][*grt_j])){
        *grt_i = i;
        *grt_j = j;
      }
    }
  }
}

void bringLineUp(int start_index, int line, int n, float** a, float* b) {
  if (line == start_index) return;

  float* temp = a[line];
  a[line] = a[start_index];
  a[start_index] = temp;

  float temp_b = b[line];
  b[line] = b[start_index];
  b[start_index] = temp_b;
}

void bringColumnLeft(int start_index, int col, int n, float** a, float* b, int* perm) {
  if (col == start_index) return;
  for(int i = 0; i < n; i++){
    float temp = a[i][col];
    a[i][col] = a[i][start_index];
    a[i][start_index] = temp;
  }

  int tmp = perm[col];
  perm[col] = perm[start_index];
  perm[start_index] = tmp;
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

int isPivot0(int j, float** a){
  if (fabsf(a[j][j]) < 1e-7) { 
    printf("Pivot zero encontrado. Sistema pode não ter solução única.\n");
    return 1;
  }
  return 0;
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

  int* perm = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) perm[i] = i;

  for(int j = 0; j < (n-1); j++){
    int grt_i, grt_j;
    findGreatestModule(j, n, a, &grt_i, &grt_j);
    bringLineUp(j, grt_i, n, a, b);
    bringColumnLeft(j, grt_j, n, a, b, perm);
    if(isPivot0(j, a)) return 1;
    solveGaussLine(j, n, a, b);
  }

  float* x = (float*) malloc(n * sizeof(float));
  solveSuperiorTriangle(n, a, b, x);

  float* x_final = (float*) malloc(n * sizeof(float));
  for (int i = 0; i < n; i++) x_final[perm[i]] = x[i];
  
  printf("A solução do sistema é: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x_final[i]);
  printf("\n");

  for (int i = 0; i < n; i++) free(a[i]);
  free(a);
  free(b);
  free(x);
  free(x_final);
  free(perm);

  return 0;
}