// ShellSort 
// 
// Melhor: O(n logn)
// Médio: O(n logn)
// Pior: O(n2) 
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_POW 8
#define MAX_VALUE 30000

/*
1: Aleatórios
2: Crescente (Ja ordenado )
3: Decrescente
4: Mais numeros iguais
*/
void populateArray(vector<int>& arr, int amount, int type){
  switch (type){
    case 1: 
      for(int i = 0; i < amount; i++) arr.push_back(rand() % (MAX_VALUE + 1));
      break;
    case 2:
      for(int i = 0; i < amount; i++) arr.push_back(i);
      break;
    case 3: for(int i = amount; i > 0; i--) arr.push_back(i);
      break;
    case 4: for(int i = 0; i < amount; i++) arr.push_back(rand() % ((amount/3) + 1));
      break;
  }
}

void printArray(vector<int>& arr){
  for(int i = 0; i < arr.size(); i++){
    cout << arr.at(i) << " ";
  }
  cout << endl;
}

void shellSort(vector<int>& arr){
  int n, gap, i, j, temp;
  n = arr.size();
  for(gap=n/2; gap >0; gap /= 2){
    for(j = gap; j < n; j += 1){
      temp = arr[j];
      for(i = j; i >= gap &&  arr[i-gap] > temp; i -= gap){
        arr[i] = arr[i- gap];
      }
      arr[i] = temp;
    }
  }
}

int main(){

  for(int type = 1; type <= 4; type++){
    int amount = 10000000;
    vector<int> arr;
    cout << "TIPO " << type << ": " << endl;

    for(int i = 1; i <= MAX_POW - 1; i++){
      arr.reserve(amount);
      populateArray(arr, amount, type);

      auto start = high_resolution_clock::now();
      shellSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}