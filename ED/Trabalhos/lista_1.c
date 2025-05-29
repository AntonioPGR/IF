#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

void insert(Node **head, int data){
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

Node* breakList(Node **head, int value){
  if (head == NULL || *head == NULL) return NULL;
  Node *cur = *head;
  while (cur->next != NULL && cur->data != value) {
    cur = cur->next;
  }
  if(cur->next == NULL) return NULL; 
  Node *second = cur->next;
  cur->next = NULL;
  return second;
}


void printList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node* concatanate(Node **head, Node **second){
  if (head == NULL || *head == NULL) return (second != NULL) ? *second : NULL;
  if (second == NULL || *second == NULL) return *head;
  Node *cur = *head;
  while(cur->next != NULL){
    cur = cur->next;
  }
  cur->next = *second;
  return *head;
}

int main(){
  Node *head = NULL;
  insert(&head, 3);
  insert(&head, 17);
  insert(&head, 5);
  insert(&head, 12);
  insert(&head, 1);

  printf("Initial List: ");
  printList(head);

  Node *second = breakList(&head, 5);

  printf("First list: ");
  printList(head);
  printf("Second list: ");
  printList(second);

  Node *concatenated = concatanate(&head, &second);
  printf("Concatenated List: ");
  printList(head);

  return 0;
}