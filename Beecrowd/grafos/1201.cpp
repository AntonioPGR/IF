#include <iostream>

using namespace std;

typedef struct Node{
  int value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(NULL), right(NULL) {}
} Node;

Node* insert(int value, Node* node){
  if(node == NULL) return new Node(value);
  if (value == node->value) return node;
  if(value > node->value) node->right = insert(value, node->right);
  else node->left = insert(value, node->left);
  return node;
}

Node* search(int value, Node* node){
  if(node == NULL || node->value == value) return node;
  if(value > node->value) return search(value, node->right);
  return search(value, node->left);
}

void printInfixa(Node* node, string& output){
  if(node != NULL){
    printInfixa(node->left, output);
    if (!output.empty()) output += " ";
    output += to_string(node->value);
    printInfixa(node->right, output);
  }
}

void printPrefixa(Node* node, string& output){
  if(node != NULL){
    if (!output.empty()) output += " ";
    output += to_string(node->value);
    printPrefixa(node->left, output);
    printPrefixa(node->right, output);
  }
}

void printPosfixa(Node* node, string& output){
  if(node != NULL){
    printPosfixa(node->left, output);
    printPosfixa(node->right, output);
    if (!output.empty()) output += " ";
    output += to_string(node->value);
  }
}

void deleteValue(int n, Node*& currentNode) {
  if (currentNode == NULL) return;
  
  if (n < currentNode->value) {
    deleteValue(n, currentNode->left);
  } else if (n > currentNode->value) {
    deleteValue(n, currentNode->right);
  } else {
    if (currentNode->left == NULL || currentNode->right == NULL) {
      Node* temp = currentNode;
      currentNode = (currentNode->left != NULL) ? currentNode->left : currentNode->right;
      delete temp;
    } else {
      Node* successor = currentNode->right;
      while (successor->left != NULL) {
        successor = successor->left;
      }
      currentNode->value = successor->value;
      deleteValue(successor->value, currentNode->right);
    }
  }
}

int main(){
  Node* root = NULL;

  string op;
  while(cin >> op){

    if(!op.compare("INFIXA")){
      string output = "";
      printInfixa(root, output);
      cout << output << endl;
    } else if(!op.compare("PREFIXA")){
      string output = "";
      printPrefixa(root, output);
      cout << output << endl;
    } else if(!op.compare("POSFIXA")){
      string output = "";
      printPosfixa(root, output);
      cout << output << endl;
    } else {
      int value;
      cin >> value;

      if(op == "I"){
        root = insert(value, root);
      } else if(op == "P") {
        if(search(value, root) == NULL) cout << value << " nao existe" << endl;
        else cout << value << " existe" << endl;
      } else {
        deleteValue(value, root);
      }
    }
  }
  return 0;
}