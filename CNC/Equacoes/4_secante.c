#include <stdio.h>
#include <math.h>

double f(double x){
  return exp(x) - sin(x) - 2;
}

int main(){

  double x1 = 1, x0 = 0, x2;

  while (fabs(f(x1)) > 1e-6){
    x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
    x0 = x1;
    x1 = x2;
  }

  printf("Raiz aproximada: %.6f\n", x1);
  printf("f(x) = %.6f\n", f(x1));
  return 0;
}