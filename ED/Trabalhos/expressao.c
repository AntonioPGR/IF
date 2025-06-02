#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ---- QUEUE ----
typedef struct Queue {
  int value; 
  struct Queue *next;
} Queue;

Queue* queue = NULL;

void addToQueue(int value){
  Queue* obj = malloc(sizeof(Queue));
  obj->value = value;
  obj->next = NULL;
  if(queue == NULL) queue = obj;
  else {
    Queue* cur = queue;
    while(cur->next != NULL) cur = cur->next;
    cur->next = obj;
  }
}

int popQueueBack(){
  Queue* cur = queue;
  if(cur == NULL) return 0;
  if(cur->next == NULL){
    int value = cur->value;
    queue = NULL;
    free(cur);
    return value;
  }
  while(cur->next->next != NULL) cur = cur->next;
  int value = cur->next->value;
  free(cur->next);
  cur->next = NULL;
  return value;
}

// --- STACK ----
typedef struct Stack {
  char value;
  struct Stack *next;
} Stack;

Stack* stack = NULL;

void addToStack(char operation){
  Stack* obj = malloc(sizeof(Stack));
  obj->value = operation;
  obj->next = NULL;
  if(stack == NULL) {
    stack = obj;
    return;
  }
  obj->next = stack;
  stack = obj;
}

char popStack(){
  if (!stack) return 0;
  char value = stack->value;
  Stack* temp = stack;
  stack = stack->next;
  free(temp);
  return value;
}

// --- MAIN ----
int main(){
    char expr[] = {"3 + 4 * 5"}; 
    char *token = strtok(expr, " ");
    while (token) {
      if(isdigit(token[0])){
        if(stack && (stack->value == '/' || stack->value == '*')){
          char operator = popStack();
          int n1 = popQueueBack();
          int n2 = atoi(token);
          int result = operator == '*'? n1 * n2: n1 / n2;
          addToQueue(result);
        } else {
          addToQueue(atoi(token));
        }
      } else {
        addToStack(token[0]);
      }
      token = strtok(NULL, " ");
    }

    while(stack){
      int b = popQueueBack();
      int a = popQueueBack();
      char op = popStack();
      int result = op == '+'? a + b: a - b;
      addToQueue(result);
    }


    printf("\nResultado: %d \n:", popQueueBack());

    return 0;
}