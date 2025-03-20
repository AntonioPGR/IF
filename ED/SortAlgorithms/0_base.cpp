#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void populateArray(vector<int>& arr, int amount){
  for(int i = 0; i < amount; i++) arr.push_back(rand() % (20 + 1));
}

void printArray(vector<int>& arr){
  for(int i = 0; i < arr.size(); i++){
    cout << arr.at(i) << " ";
  }
  cout << endl;
}

int main(){

  int amount = 1000000;
  vector<int> arr;

  arr.reserve(amount);
  populateArray(arr, amount);

  auto start = high_resolution_clock::now();
  sort(arr.begin(), arr.end());
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

  arr.clear();
  amount *= 10;

}