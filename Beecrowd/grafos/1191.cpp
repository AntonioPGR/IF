#include <iostream>

using namespace std;

typedef struct Node{
  Node* left;
  Node* right;
  char value;

  Node(char _value) : value(_value), left(NULL), right(NULL){}
} Node;

int preorderIndex;

Node* buildPreInTree(string preorder, string inorder){
  if(inorder.empty()) return NULL;

  char rootValue = preorder[preorderIndex++];
  Node* node = new Node(rootValue);

  char inorderIndex = inorder.find(rootValue);
  string inorderLeft = inorder.substr(0, inorderIndex);
  string inorderRight = inorder.substr(inorderIndex + 1);

  node->left = buildPreInTree(preorder, inorderLeft);
  node->right = buildPreInTree(preorder, inorderRight);

  return node;
}

void printPostOrder(Node* node, string& output){
  if(node != NULL){
    printPostOrder(node->left, output);
    printPostOrder(node->right, output);
    output += node->value;
  }
}

int main(){
  string pre, in;
  while(cin >> pre >> in){
    preorderIndex = 0;
    Node* root = buildPreInTree(pre, in);

    string output;
    printPostOrder(root, output);
    cout << output << endl;
  }
  return 0;
}