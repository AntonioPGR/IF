#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<int> a= {4, 8, 1, 0, 9, 0, 2, 7, 3, 6};

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

  // Bubble Sort Normal
  // Para melhorar podemos adicionar uma variavel de controle se trocou ou nao, para evitar repetições desnecessárias
  // Melhor: O(n)
  // Médio: O(n2)
  // Pior: O(n2)
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a.size() - 1; j++){
      if(a.at(j) > a.at(j + 1)){
        int temp = a.at(j);
        a.at(j) = a.at(j + 1);
        a.at(j + 1) = temp;
      }
    }
  }

  for(int i = 0; i < a.size(); i++){
    cout << a.at(i) << " ";
  }
  cout << endl;

}