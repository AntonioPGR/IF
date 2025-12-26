#include <stdio.h>    // fluxo (entrada/saída controlada pelo programa)

int main() {          // fluxo (início do fluxo de execução)
  int x = 5;        // atribuição
  int y = 3;        // atribuição

  x = x + y;        // atribuição

  if (x > 5) {      // fluxo
    printf("Maior que 5\n");   // fluxo (comando dentro de condição)
  } else {          // fluxo
    printf("Menor ou igual a 5\n");  // fluxo
  }

  return 0;         // fluxo (fim do programa)
}
