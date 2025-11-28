#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void solve_3x3(double A[3][3], double B[3], double X[3]) {
  for (int k = 0; k < 3; ++k) {
    int p = k;
    double max = fabs(A[k][k]);
    for (int i = k + 1; i < 3; ++i) {
      double v = fabs(A[i][k]);
      if (v > max) {
        max = v;
        p = i;
      }
    }
    if (p != k) {
      for (int j = k; j < 3; ++j) {
        double tmp = A[k][j];
        A[k][j] = A[p][j];
        A[p][j] = tmp;
      }
      double tmp = B[k];
      B[k] = B[p];
      B[p] = tmp;
    }
    for (int i = k + 1; i < 3; ++i) {
      if (A[k][k] == 0.0) continue; 
      double factor = A[i][k] / A[k][k];
      for (int j = k; j < 3; ++j) A[i][j] -= factor * A[k][j];
      B[i] -= factor * B[k];
    }
  }
  for (int i = 2; i >= 0; --i) {
    double s = B[i];
    for (int j = i + 1; j < 3; ++j) s -= A[i][j] * X[j];
    X[i] = (A[i][i] == 0.0) ? 0.0 : s / A[i][i];
  }
}

int main() {
  int n;
  printf("Quantidade de pontos: ");
  scanf("%d", &n);

  float* x = malloc(n * sizeof(float));
  float* y = malloc(n * sizeof(float));

  printf("Valores de x:\n");
  for (int i = 0; i < n; i++)
    scanf("%f", &x[i]);

  printf("Valores de y:\n");
  for (int i = 0; i < n; i++)
    scanf("%f", &y[i]);

  double A[3][3] = {0};
  double B[3] = {0};

  for (int i = 0; i < n; i++) {
    A[2][2] += 1;
    A[1][2] += x[i];
    A[2][1] += x[i];
    A[0][2] += pow(x[i], 2);
    A[1][1] += pow(x[i], 2);
    A[2][0] += pow(x[i], 2);
    A[0][1] += pow(x[i], 3);
    A[1][0] += pow(x[i], 3);
    A[0][0] += pow(x[i], 4);

    B[0] += y[i] * pow(x[i], 2);
    B[1] += y[i] * x[i];
    B[2] += y[i];
  }

  double X[3] = {0, 0, 0};
  solve_3x3(A, B, X);
  printf("Ajuste: y = %g*x^2 + %g*x + %g\n", X[0], X[1], X[2]);

  free(x);
  free(y);

  return 0;
}
