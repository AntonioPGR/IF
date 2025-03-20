#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void populateArray(vector<int>& arr, int amount){
  for(int i = 0; i < amount; i++) arr.push_back(i);
}

int twoPointers(vector<int>& arr){
  int search = arr[arr.size() / 2];
  for(int i = 0, j = arr.size(); i <= j; i++, j--){
    if(arr[i] == search) return i;
    if(arr[j] == search) return j;
  }
  return -1;
}

int main(){
  srand(time(0));

  int amount = 100000000;
  vector<int> arr;

  arr.reserve(amount);
  populateArray(arr, amount);

  auto start = high_resolution_clock::now();
  int res = twoPointers(arr);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  if(res == -1) cout << "Item não encontrado" << endl;
  else cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

  arr.clear();
}