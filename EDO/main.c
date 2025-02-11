#include <stdio.h>
#include <math.h>

#define a 0.0
#define b 1.0
#define m 6.0
#define y0 2.0
#define h (b-a)/(m-1)

double xn(int n){
  return a + n * h;
}

double f(double x, double y){
  return x - y + 2;
}

double df(double x, double y){
  double dfx = 1;
  double dfy = -1;
  return dfx + dfy * f(x, y);
}

double fexata(double x){
  return (1 + (x+1)*exp(x) ) * exp(-x);
}

double main(){

  // Cabeçalho
  printf("|         X        |");
  for(int j = 0; j < m; j++){
    printf("     %.2f    |", a + j * h);
  }
  printf("\n");

  // Metodo de Taylor de 1 Ordem
  printf("|  Taylor 1 Ordem  |");
  double y = y0;
  for(int i = 0; i < m; i++){
    printf(" %.9f |", y);
    double x = xn(i);
    y = y + h * f(x, y);
  }
  printf("\n");

  // Metodo de Taylor de 2 Ordem
  printf("|  Taylor 2 Ordem  |");
  y = y0;
  for(int i = 0; i < m; i++){
    printf(" %.9f |", y);
    double x = xn(i);
    y = y + h * f(x, y) + ((h*h)/2) * df(x, y);
  }
  printf("\n");

  // Metodo de Euler melhorado
  printf("| Euler Melhorado  |");
  y = y0;
  for(int i = 0; i < m; i++){
    printf(" %.9f |", y);
    double x = xn(i);
    double k1 = f(x, y);
    double k2 = f(x + h, y + (h * k1));
    y = y + (h/2) * (k1 + k2);
  }
  printf("\n");

  // Metodo de Euler modificado
  printf("| Euler modificado |");
  y = y0;
  for(int i = 0; i < m; i++){
    printf(" %.9f |", y);
    double x = xn(i);
    double k1 = f(x, y);
    double k2 = f(x + (h/2), y + (h/2)*k1);
    y = y + h * k2;
  }
  printf("\n");

  // Metodo de runge-kutta de 4 ordem
  printf("|   Runge-Kutta    |");
  y = y0;
  for(int i = 0; i < m; i++){
    printf(" %.9lf |", y);
    double x = xn(i);
    double k1 = f(x, y);
    double k2 = f(x + (h/2), y + (h/2)*k1);
    double k3 = f(x + (h/2), y + (h/2)*k2);
    double k4 = f(x + h, y + h * k3);
    y = y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
  }
  printf("\n");

  // Solução exata
  printf("|      Exata       |");
  y = y0;
  for(int i = 1; i <= m; i++){
    printf(" %.9lf |", y);
    double x = xn(i);
    y = fexata(x);
  }
  printf("\n");
  

  return 0;
}