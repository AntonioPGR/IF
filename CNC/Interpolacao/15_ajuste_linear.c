#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void findGreatestModule(int start_index, int n, float** a, int* grt_i, int* grt_j) {
  *grt_i = start_index;
  *grt_j = start_index;
  for (int i = start_index; i < n; i++) {
    for (int j = start_index; j < n; j++) {
      if (fabsf(a[i][j]) > fabsf(a[*grt_i][*grt_j])) {
        *grt_i = i;
        *grt_j = j;
      }
    }
  }
}

void bringLineUp(int start_index, int line, int n, float** a, float* b) {
  if (line == start_index)
    return;
  float* temp = a[line];
  a[line] = a[start_index];
  a[start_index] = temp;
  float temp_b = b[line];
  b[line] = b[start_index];
  b[start_index] = temp_b;
}

void bringColumnLeft(int start_index, int col, int n, float** a, float* b, int* perm) {
  if (col == start_index)
    return;
  for (int i = 0; i < n; i++) {
    float temp = a[i][col];
    a[i][col] = a[i][start_index];
    a[i][start_index] = temp;
  }
  int t = perm[col];
  perm[col] = perm[start_index];
  perm[start_index] = t;
}

void solveSuperiorTriangle(int n, float** a, float* b, float* x) {
  for (int i = n - 1; i >= 0; i--) {
    float soma = 0;
    for (int j = i + 1; j < n; j++)
      soma += a[i][j] * x[j];
    x[i] = (b[i] - soma) / a[i][i];
  }
}

void solveGaussLine(int j, int n, float** a, float* b) {
  for (int i = j + 1; i < n; i++) {
    float m = -(a[i][j] / a[j][j]);
    for (int k = j; k < n; k++)
      a[i][k] += m * a[j][k];
    b[i] += m * b[j];
  }
}

int isPivot0(int j, float** a) {
  return fabsf(a[j][j]) < 1e-7;
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

  float Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;
  for (int i = 0; i < n; i++) {
    Sx += x[i];
    Sy += y[i];
    Sxx += x[i] * x[i];
    Sxy += x[i] * y[i];
  }

  float** A = malloc(2 * sizeof(float*));
  A[0] = malloc(2 * sizeof(float));
  A[1] = malloc(2 * sizeof(float));

  A[0][0] = Sxx;
  A[0][1] = Sx;
  A[1][0] = Sx;
  A[1][1] = n;

  float* B = malloc(2 * sizeof(float));
  B[0] = Sxy;
  B[1] = Sy;

  int* perm = malloc(2 * sizeof(int));
  perm[0] = 0;
  perm[1] = 1;

  for (int j = 0; j < 1; j++) {
    int gi, gj;
    findGreatestModule(j, 2, A, &gi, &gj);
    bringLineUp(j, gi, 2, A, B);
    bringColumnLeft(j, gj, 2, A, B, perm);
    if (isPivot0(j, A)) {
      printf("Sistema sem solução.\n");
      return 1;
    }
    solveGaussLine(j, 2, A, B);
  }

  float* sol = malloc(2 * sizeof(float));
  solveSuperiorTriangle(2, A, B, sol);

  float a_final, b_final;
  if (perm[0] == 0) {
    a_final = sol[0];
    b_final = sol[1];
  } else {
    a_final = sol[1];
    b_final = sol[0];
  }

  printf("\na = %.6f\nb = %.6f\n", a_final, b_final);

  free(x);
  free(y);
  free(A[0]);
  free(A[1]);
  free(A);
  free(B);
  free(sol);
  free(perm);

  return 0;
}
