#include <stdio.h>
#include <math.h>

double f(double x){
  return exp(x) - sin(x) - 2;
}

double df(double x){
  return exp(x) - cos(x);
}

int main(){

  double x = 1;

  while (fabs(f(x)) > 1e-6){
    x = x - (f(x)/df(x));
  }

  printf("Raiz aproximada: %.6f\n", x);
  printf("f(x) = %.6f\n", f(x));
  return 0;
}