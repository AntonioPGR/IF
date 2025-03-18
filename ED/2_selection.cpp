#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> a= {4, 8, 1, 0, 9, 0, 2, 7, 3, 6};

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

  // Selection Sort Normal
  // Fazer selection sort melhorado posteriormente
  // Melhor: O(n2)
  // Médio: O(n2)
  // Pior: O(n2)
  int pos, i, j, temp;
  for(i = 0; i < a.size() - 1; i++){
    pos = i;
    for(j = i+1; j < a.size(); j++){
      if(a.at(j) < a.at(pos)){
        pos = j;
      }
    }
    if(pos != i){
      temp = a.at(i);
      a.at(i) = a.at(pos);
      a.at(pos) = temp;
    }
  }


  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

}