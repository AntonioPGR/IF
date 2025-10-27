#include <stdio.h>
#include <math.h>

double f(double x){
  return x*x - cos(x);
}

void find_initial_interval(double *a, double *b){
  double fl, fh;

  int x = 0;
  double fx = f(x);
  for (int i = 1;; i++){
    fl = f(x - i);
    fh = f(x + i);
    if (fl * fx < 0){
      *a = x - i;
      *b = x - i + 1;
      return;
    }
    if (fh * fx < 0){
      *a = x + i - 1;
      *b = x + i;
      return;
    }
  }
}

double find_mean(double a, double b){
  return (a + b) / 2;
}

int main(){

  double a, b;
  find_initial_interval(&a, &b);

  double x = find_mean(a, b);
  while (fabs(f(x)) > 1e-6){
    if (f(a) * f(x) < 0)
      b = x;
    else
      a = x;
    x = find_mean(a, b);
  }

  printf("Raiz aproximada: %.6f\n", x);
  printf("f(x) = %.6f\n", f(x));
  return 0;
}