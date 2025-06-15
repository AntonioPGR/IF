#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  char data;
  struct Node *next;
} Node;

void insert(Node **head, char data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL || *head == NULL){
    *head = newNode;
    return;
  }
  Node *cur = *head;
  while(cur->next != NULL){
    cur = cur->next;
  }
  cur->next = newNode;
}

int getSize(Node **head){
  if(head == NULL || *head == NULL)return 0;
  int size = 1;
  Node *cur = *head;
  while(cur->next != NULL){
    cur = cur->next;
    size++;
  }
  return size;
}

int getAt(Node **head, int pos){
  if(head == NULL || *head == NULL)return 0;
  int size = 1;
  Node *cur = *head;
  while(cur->next != NULL){
    if((size - 1) == pos) break;
    cur = cur->next;
    size++;
  }
  return cur->data;
}

void printList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}


int main(){
  Node *head = NULL;
  insert(&head, 'r');
  insert(&head, 'a');
  insert(&head, 'd');
  insert(&head, 'a');
  insert(&head, 'r');

  int size = getSize(&head);

  int isPalindromo = 1;
  for(int i = 0, j = size-1; i++, j--; i < j){
    if(getAt(&head, i) != getAt(&head, j)){
      isPalindromo = 0;
      break;
    }
  }

  if(isPalindromo) printf("Eh palindromo");
  else printf("Nao eh palindromo");

  return 0;
}