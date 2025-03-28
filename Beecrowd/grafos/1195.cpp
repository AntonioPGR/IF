#include <iostream>
#include <vector>
#include <queue>
#include <cstddef>

using namespace std;

vector<int> print;

typedef struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val) : value(val), left(NULL), right(NULL) {}
} Node;

Node* insert(int value, Node* node){
  if(node == NULL) {
    return new Node(value);
  }
  if(value > node->value){
    node->right = insert(value, node->right);
  } else {
    node->left = insert(value, node->left);
  }
  return node;
}

void getPrintPreOrder(Node* node){
  if(node != NULL){
    print.push_back(node->value);
    getPrintPreOrder(node->left);
    getPrintPreOrder(node->right);
  }
}

void getPrintInOrder(Node* node){
  if(node != NULL){
    getPrintInOrder(node->left);
    print.push_back(node->value);
    getPrintInOrder(node->right);
  }
}

void getPrintPostOrder(Node* node){
  if(node != NULL){
    getPrintPostOrder(node->left);
    getPrintPostOrder(node->right);
    print.push_back(node->value);
  }
}

int main(){
  int c;
  cin >> c;
  for(int i = 1; i <= c; i++){
    
    Node* root = NULL;

    int n, temp;
    cin >> n;
    while(n--){
      cin >> temp;
      if(root == NULL) root = insert(temp, root);
      else insert(temp, root);
    }

    cout << "Case " << i << ":" << endl;
    cout << "Pre.: ";
    print.clear();
    getPrintPreOrder(root);
    for(int j = 0; j < print.size(); j++){
      if(j == print.size() - 1) cout << print[j] << endl;
      else cout << print[j] << " ";
    }

    cout << "In..: ";
    print.clear();
    getPrintInOrder(root);
    for(int j = 0; j < print.size(); j++){
      if(j == print.size() - 1) cout << print[j] << endl;
      else cout << print[j] << " ";
    }

    cout << "Post: ";
    print.clear();
    getPrintPostOrder(root);
    for(int j = 0; j < print.size(); j++){
      if(j == print.size() - 1) cout << print[j] << endl;
      else cout << print[j] << " ";
    }
    cout << endl;
  }
}