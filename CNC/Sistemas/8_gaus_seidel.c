#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

  float* x_final = (float*) malloc(n * sizeof(float));
  float* b_estimated = (float*) malloc(n * sizeof(float));
  for (int i = 0; i < n; i++) {
    x_final[i] = 0;
    b_estimated[i] = 0;
  }

  for(int k = 0; k < 1000; k++){
    for(int i = 0; i < n; i++){
      float sum = 0;
      for(int j = 0; j < n; j++) if(i != j) sum += a[i][j] * x_final[j];
      x_final[i] = (b[i] - sum) / a[i][i];
    }

    for(int i = 0; i < n; i++){
      b_estimated[i] = 0;
      for(int j = 0; j < n; j++){
        b_estimated[i] += a[i][j] * x_final[j];
      }
    }

    float err = 0;
    for(int i = 0; i < n; i++){
      err += pow(b[i] - b_estimated[i], 2);
    }
    err = sqrt(err); 
    if(err < 1e-5) break;
  }

  printf("A solucao do sistema eh: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x_final[i]);
  printf("\n");

  for (int i = 0; i < n; i++) free(a[i]);
  free(a);
  free(b);
  free(x_final);
  free(b_estimated);

  return 0;
}