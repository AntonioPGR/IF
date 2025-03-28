#include <iostream>
#include <vector>
#include <queue>
#include <cstddef>

using namespace std;

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

vector<int> bfs(Node* root){
  vector<int> res;
  queue<Node*> q;

  q.push(root);

  while(!q.empty()){
    Node* current = q.front();
    q.pop();
    res.push_back(current->value);

    if(current->left) q.push(current->left);
    if(current->right) q.push(current->right);
  }

  return res;
}

int main(){


  int n, cases = 1;
  cin >> n;
  while(n--){
    int nodes;
    cin >> nodes;

    Node* root = NULL;
    int temp;
    for(int i = 0; i < nodes; i++){
      cin >> temp;
      if(i == 0) root = insert(temp, root);
      else insert(temp, root);
    }

    vector<int> res = bfs(root);

    cout << "Case " << cases << ":" << endl;
    for(int i = 0; i < res.size(); i++){
      if(i == res.size() - 1) cout << res[i] << endl;
      else cout << res[i] << " ";
    }
    cout << endl;
    cases++;
  }
}