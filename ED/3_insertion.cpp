#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> a= {4, 8, 1, 0, 9, 0, 2, 7, 3, 6};

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

  // InserctionSort 
  // 
  // Melhor: O(n)
  // Médio: O(n2)
  // Pior: O(n2)
  int i, j, key;
  for(i = 1; i < a.size(); i++){
    key = a.at(i);
    j = i-1;
    while(j >= 0 && a.at(j) > key){
      a.at(j+1) = a.at(j);
      j -= 1;
    }
    a.at(j+1) = key;
  }

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

}