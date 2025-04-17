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
  novo->prox = NULL;
  if(frente == NULL) {
    frente = novo;
    return;
  }
  Node* p = frente;
  while(p->prox != NULL) {
    p = p->prox;
  }
  p->prox = novo;
}

void pop(int amount) {
  if (frente == NULL) return;

  // Verifica tamanho
  int queue_size = 0;
  Node* p = frente;
  while(p->prox != NULL) {
    queue_size++;
    p = p->prox;
  }
  if(queue_size < amount) {
    printf("A fila tem menos de %d elementos.\n", amount);
    return;
  }

  for(int i = 0; i < amount; i++) {
    Node* temp = frente;
    frente = frente->prox;
    free(temp);
  }
}

void imprimeFila() {
  Node* p = frente;
  printf("Os elementos da fila sao: ");
  while (p != NULL) {
    printf("%d ", p->valor);
    p = p->prox;
  }
  printf("\n");
}

void imprimeSoma(){
  Node* p = frente;
  printf("A soma dos elementos da fila e: ");
  int sum = 0;
  while (p != NULL) {
    sum += p->valor;
    p = p->prox;
  }
  printf("%d \n", sum);
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  imprimeFila();

  pop(7);
  imprimeFila();

  pop(3);
  imprimeFila();
}
