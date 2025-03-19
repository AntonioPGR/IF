// InserctionSort 
// 
// Melhor: O(n)
// Médio: O(n2)
// Pior: O(n2)
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr){
  int i, j, key;
  for(i = 1; i < arr.size(); i++){
    key = arr.at(i);
    j = i-1;
    while(j >= 0 && arr.at(j) > key){
      arr.at(j+1) = arr.at(j);
      j -= 1;
    }
    arr.at(j+1) = key;
    if(i % 10000 == 0) cout << "Atual: " << i << endl;
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

  int amount = 10000;
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

    insertionSort(arr);  
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << amount << " Items: " << duration.count() << " microsegundos" << endl;
  }

  
}