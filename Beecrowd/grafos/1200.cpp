#include <iostream>

using namespace std;

typedef struct Node{
  char value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(NULL), right(NULL) {}
} Node;

Node* insert(char value, Node* node){
  if(node == NULL) return new Node(value);
  if(value > node->value) node->right = insert(value, node->right);
  else node->left = insert(value, node->left);
  return node;
}

Node* search(char value, Node* node){
  if(node == NULL || node->value == value) return node;
  if(value > node->value) return search(value, node->right);
  return search(value, node->left);
}

void printInfixa(Node* node, string& output){
  if(node != NULL){
    printInfixa(node->left, output);
    if (!output.empty()) output += " ";
    output += node->value;
    printInfixa(node->right, output);
  }
}

void printPrefixa(Node* node, string& output){
  if(node != NULL){
    if (!output.empty()) output += " ";
    output += node->value;
    printPrefixa(node->left, output);
    printPrefixa(node->right, output);
  }
}

void printPosfixa(Node* node, string& output){
  if(node != NULL){
    printPosfixa(node->left, output);
    printPosfixa(node->right, output);
    if (!output.empty()) output += " ";
    output += node->value;
  }
}

int main(){
  Node* root = NULL;

  string line;
  while(getline(cin, line)){
    if(!line.compare("INFIXA")){
      string output = "";
      printInfixa(root, output);
      cout << output << endl;
    } else if(!line.compare("PREFIXA")){
      string output = "";
      printPrefixa(root, output);
      cout << output << endl;
    } else if(!line.compare("POSFIXA")){
      string output = "";
      printPosfixa(root, output);
      cout << output << endl;
    } else {
      char op = line[0], value = line[2];
      if(op == 'I'){
        if(root == NULL) root = insert(value, root);
        else insert(value, root);
      } else {
        if(search(value, root) == NULL) cout << value << " nao existe" << endl;
        else cout << value << " existe" << endl;
      }
    }
  }
  return 0;
}