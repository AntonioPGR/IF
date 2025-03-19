// Selection Sort Normal
// Fazer selection sort melhorado posteriormente
// Melhor: O(n2)
// Médio: O(n2)
// Pior: O(n2)
#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

void selectionSort(vector<int>&arr){
  int n = arr.size();
  for(int i = 0, j = n - 1; i < j; i++, j--){
    int min = arr[i], max = arr[j];
    int min_i = i, max_i = j;

    for(int k = i; k <= j; k++){
      if(arr[k] < min){
        min = arr[k];
        min_i = k;
      }
      if(arr[k] > max){
        max = arr[k];
        max_i = k;
      }
    }

    swap(arr[i], arr[min_i]); 

    if (max_i == i)
      max_i = min_i; 

    swap(arr[j], arr[max_i]);
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

    selectionSort(arr);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << amount << " Items: " << duration.count() << " microsegundos" << endl;
  }
}