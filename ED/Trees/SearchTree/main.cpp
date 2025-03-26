#include <iostream>
#include <cstddef>
#include "tree.h"

using namespace std;

BinarySearchTree tree;

int main(){

  tree.insert(6);
  tree.insert(4);
  tree.insert(8);
  tree.insert(3);
  tree.insert(5);
  tree.insert(7);
  tree.insert(9);

  tree.printPostOrder(tree.getRoot());


}

//   6
// 4   8
//3 5 7  9