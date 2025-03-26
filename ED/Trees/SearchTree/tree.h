#include <iostream>

typedef struct Node{
  int value;
  Node* left;
  Node* right;  
} Node;

class BinarySearchTree{
  private:
    Node* root;

  public:
    BinarySearchTree();
    ~BinarySearchTree();
    void deleteTree(Node* currentNode);
    Node* getRoot();
    bool isEmpty();
    bool isFull();
    void insert(int n);
    void remove(int n);
    void deleteNode(Node*& currentNode);
    void getSucessor(int& n, Node* temp);
    Node* search(int n);
    void printPreordem(Node* currentNode);
    void printInorder(Node* currentNode);
    void printPostOrder(Node* currentNode);
    void deepFirstSeach();
    void breadthFirstSearch();
};