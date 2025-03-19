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

void shellSort(vector<int>& arr){
  int n, gap, i, j, temp;
  n = arr.size();
  for(gap=n/2; gap >0; gap /= 2){
    for(j = gap; j < n; j += 1){
      temp = arr.at(j);
      for(i = j; i >= gap &&  arr.at(i-gap) > temp; i -= gap){
        arr.at(i) = arr.at(i - gap);
      }
      arr.at(i) = temp;
    }
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
  cout << "Shell Sort" << endl;
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

    shellSort(arr);  
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << amount << " Items: " << duration.count() << " microsegundos" << endl;
  }

  
}