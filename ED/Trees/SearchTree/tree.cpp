#include <iostream>
#include <cstddef>
#include "tree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
  root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
  deleteTree(root);
  root = NULL;
} 

void BinarySearchTree::deleteTree(Node* currentNode){}

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
    if(n > insertion->value) insertion = insertion->right;
    else insertion = insertion->left;
  }

  if(n > parent->value) parent->right = node;
  else parent->left = node;
}

void BinarySearchTree::remove(int n){}

void BinarySearchTree::removeSearch(int n, Node*& currentNode){}

void BinarySearchTree::deleteNode(Node*& currentNode){}

void BinarySearchTree::getSucessor(int& n, Node* temp){}

Node* BinarySearchTree::search(int n){
  Node* node = root;

  while(node != NULL && node->value != n){
    if(n > node->value) node = node->right;
    else node = node->left;
  }

  return node;
}

void BinarySearchTree::printPreordem(Node* currentNode){}

void BinarySearchTree::printInorder(Node* currentNode){}

void BinarySearchTree::printPostOrder(Node* currentNode){}