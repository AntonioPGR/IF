#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Quantidade de pontos: ");
  scanf("%d", &n);

  if(n <= 1){
    printf("Numero de pontos deve ser maior que 1\n");
    return 1;
  }

  float* x = malloc(n * sizeof(float));
  float* y = malloc(n * sizeof(float));

  printf("Valores de x:\n");
  for (int i = 0; i < n; i++) {
    scanf("%f", &x[i]);
  }

  printf("Valores de y:\n");
  for (int i = 0; i < n; i++) {
    scanf("%f", &y[i]);
  }

  // M[col][line]
  double** M = malloc((n+1) * sizeof(double*));
  for (int i = 0; i < n+1; i++) {
    M[i] = malloc(n * sizeof(double));
  }

  for(int i = 0; i < n; i++){
    M[0][i] = x[i];
    M[1][i] = y[i];
  }

  for(int col = 2; col < n+1; col++){
    for(int line = col - 1; line < n; line++){
      M[col][line] = (M[col - 1][line] - M[col - 1][line - 1]) / (x[line] - x[line - (col - 1)]);
    }
  }

  printf("Polinomio de Newton:\n");
  for(int i = 0; i < n; i++){
    if(i == 0){
      printf("(%g) ", M[i + 1][i]);
    } else {
      printf("+ (%g) ", M[i + 1][i]);
      for(int j = 0; j < i; j++){
        if (x[j] < 0)
          printf("* (x + %g) ", -x[j]);
        else
        printf("* (x - %g) ", x[j]);
      }
    }
  }
  printf("\n");

  for (int i = 0; i < n+1; i++) free(M[i]);
  free(M);
  free(x);
  free(y);
  return 0;
}
