#include <iostream>
#include <cstddef>
#include <string>
#include <queue>
#include <stack>
#include "tree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
  root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
  deleteTree(root);
  root = NULL;
} 

void BinarySearchTree::deleteTree(Node* currentNode){
  deleteNode(root);
}

Node* BinarySearchTree::getRoot(){
  return root;
}

bool BinarySearchTree::isEmpty(){
  if(root == NULL) return true;
  return false;
}

bool BinarySearchTree::isFull(){
  try{
    Node* node = new Node;
    delete node;
    return false;
  } catch(bad_alloc Excp) {
    return true;
  }
}

void BinarySearchTree::insert(int n){
  if(isFull()){
    throw new bad_alloc();
  }

  Node* node = new Node;
  node->value = n;
  node->left = NULL;
  node->right = NULL;

  if(root == NULL){
    root = node;
    return;
  }

  Node* insertion = root;
  Node* parent = NULL;
  while(insertion != NULL){\
    parent = insertion;
    if(n == insertion->value) return;
    else if(n > insertion->value) insertion = insertion->right;
    else insertion = insertion->left;
  }

  if(n > parent->value) parent->right = node;
  else parent->left = node;
}

void BinarySearchTree::remove(int n){
  Node* node = search(n);
  deleteNode(node);
}

void BinarySearchTree::deleteNode(Node*& currentNode){
  if(currentNode->right == NULL){
    Node* temp = currentNode;
    currentNode = currentNode->left;
    delete temp;
    return;
  }
  if(currentNode->left == NULL){
    Node* temp = currentNode;
    currentNode = currentNode->right;
    delete temp;
    return;
  }

  Node* successor = currentNode->right;
  Node* parent = currentNode;
  while (successor->left != NULL) {
    parent = successor;
    successor = successor->left;
  }

  currentNode->value = successor->value;

  if (parent->left == successor) deleteNode(parent->left);
  else deleteNode(parent->right);
}

Node* BinarySearchTree::search(int n){
  Node* node = root;

  while(node != NULL && node->value != n){
    if(n > node->value) node = node->right;
    else node = node->left;
  }

  return node;
}

void BinarySearchTree::printPreordem(Node* currentNode){
  if(currentNode != NULL){
    cout << currentNode->value << " ";

    printPreordem(currentNode->left);
    printPreordem(currentNode->right);
  }
}

void BinarySearchTree::printInorder(Node* currentNode){
  if(currentNode != NULL){
    printPreordem(currentNode->left);

    cout << currentNode->value << " ";

    printPreordem(currentNode->right);
  }
}

void BinarySearchTree::printPostOrder(Node* currentNode){
  if(currentNode != NULL){
    printPreordem(currentNode->left);
    printPreordem(currentNode->right);
    
    cout << currentNode->value << " ";
  }
}