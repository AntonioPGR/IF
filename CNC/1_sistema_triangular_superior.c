#include <stdio.h>

int getOffset(i, j, n){
  return i * n + j;
}

int main(){

  int n;
  printf("Ordem do sistema: ");
  scanf("%d", &n);

  float* a = (float*) malloc(n * n * sizeof(float));
  float temp;
  printf("Matriz dos coeficientes: \n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%f", a[getOffset(i, j, n)]);
    }
  }

  float* b = (float*) malloc(n * sizeof(float));
  printf("Termos independentes: \n");
  for(int i = 0; i < n; i++){
    scanf("%f", b[i]);
  }

  float* x = (float*) malloc(n * sizeof(float));
  float soma;
  for(int i = (n-1); i > 0; i--){
    
  }

  printf("A solução do sistema é: ");
  for(int i = 0; i < n; i++) printf("%.3f ", x[i]);
  printf("\n");

}