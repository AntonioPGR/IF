#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  struct Node* prox;
} Node;

Node* frente = NULL;

void push(int x) {
  Node* novo = (Node*) malloc(sizeof(Node));
  novo->valor = x;
  novo->prox = frente;
  frente = novo;
}

int pop() {
  if (frente == NULL) return -1;

  int valor = frente->valor;
  Node* temp = frente;
  frente = frente->prox;
  free(temp);
  return valor;
}

void imprimePilha() {
  Node* p = frente;
  while (p != NULL) {
    printf("%d ", p->valor);
    p = p->prox;
  }
  printf("\n");
}

int main() {
  char palavra[101];

  printf("Digite uma palavra (somente letras minusculas, sem espaco ou acento): ");
  scanf("%100s", palavra);

  for (int i = 0; palavra[i] != '\0'; i++) {
    push(palavra[i]);
  }

  int eh_palindromo = 1;
  for (int i = 0; palavra[i] != '\0'; i++) {
    if (palavra[i] != pop()) {
      eh_palindromo = 0;
      break;
    }
  }

  if (eh_palindromo) {
    printf("A palavra e um palindromo.\n");
  } else {
    printf("A palavra nao e um palindromo.\n");
  }

  return 0;
}
