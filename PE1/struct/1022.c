#include <stdio.h>

// n1 / n2 op n3 / n4

typedef struct _fract {
  int numerador;
  int denominador;
} fract;

int main(){

  int test_cases;
  fract f1, f2, result;
  char op; 

  scanf("%d", &test_cases);

  for(int i = 0; i < test_cases; i++){
    scanf("%d / %d %c %d / %d", &f1.numerador, &f1.denominador, &op, &f2.numerador, &f2.denominador);

    switch (op){
      case '+':
        result.numerador = f1.numerador*f2.denominador + f2.numerador*f1.denominador;
        result.denominador = f1.denominador*f2.denominador;
        break;
      case '-':
        result.numerador = f1.numerador*f2.denominador - f2.numerador*f1.denominador;
        result.denominador = f1.denominador*f2.denominador;
        break;
      case '*':
        result.numerador = f1.numerador*f2.numerador;
        result.denominador = f1.denominador*f2.denominador;
        break;
      case '/':
        result.numerador = f1.numerador*f2.denominador;
        result.denominador = f1.denominador*f2.numerador;
        break;
    }

    printf("%d/%d = ", result.numerador, result.denominador);

    for(int i = 1; i <= result.numerador || i <= result.denominador; i++){
      if(result.numerador % i == 0 && result.denominador % i == 0){
        result.numerador /= i;
        result.denominador /= i;
        i = 1;
      }
    }

    printf("%d/%d\n", result.numerador, result.denominador);

  }

  return 0;
}