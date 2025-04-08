#include <iostream>

using namespace std;

typedef struct Node {
  Node* left;
  Node* right;
  char value;

  Node(char val) : value(val), left(NULL), right(NULL) {}
} Node;

int preCount = 0;

Node* buildTree(string pre, string in){
  if(in.empty()) return NULL;

  char nodeValue = pre[preCount++];
  Node* node = new Node(nodeValue);

  int rootIndex = in.find(nodeValue);
  string inLeft = in.substr(0, rootIndex);
  string inRight = in.substr(rootIndex+1);

  node->left = buildTree(pre, inLeft);
  node->right = buildTree(pre, inRight);
  
  return node;
}

void printPostOrder(Node* root){
  if(root != NULL){
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->value;
  }
}

int main(){
  int n;
  cin >> n;
  while(n--){
    preCount = 0;

    int amount;
    string pre, in;
    cin >> amount >> pre >> in;

    Node* root = buildTree(pre, in);

    printPostOrder(root);
    cout << endl;
  }
  return 0;
}