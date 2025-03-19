// Bubble Sort Normal
// Para melhorar podemos adicionar uma variavel de controle se trocou ou nao, para evitar repetições desnecessárias
// Melhor: O(n)
// Médio: O(n2)
// Pior: O(n2)

#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr){
  for(int i = 0; i < arr.size(); i++){
    for(int j = 0; j < arr.size() - 1; j++){
      if(arr.at(j) > arr.at(j + 1)){
        int temp = arr.at(j);
        arr.at(j) = arr.at(j + 1);
        arr.at(j + 1) = temp;
      }
    }
    if(i % 10000 == 0) cout << i << endl; 
  }
}

void populateArray(vector<int>& arr, int amount, int max){
  for(int i = 0; i < amount; i++){
    arr.push_back(rand() % (max + 1));
  }
}

void printArray(vector<int>& arr){
  for(int i = 0; i < arr.size(); i++){
    cout << arr.at(i) << " ";
  }
  cout << endl;
}

int main(){

  int max = 100000;
  vector<int> arr;

  for(int i = 1; i <= 6; i++){
    int amount = 1;
    for (int j = 0; j < i; j++) {
      amount *= 10;
    }
    arr.reserve(amount);
    populateArray(arr, amount, max);

    auto start = high_resolution_clock::now();

    bubbleSort(arr);  
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << amount << " Items: " << duration.count() << " microsegundos" << endl;
  }

}