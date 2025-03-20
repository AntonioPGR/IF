#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void populateArray(vector<int>& arr, int amount){
  for(int i = 0; i < amount; i++) arr.push_back(i);
}

int binarySearch(vector<int>& arr, int search) {
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int cur_value = arr[mid];
    if (cur_value == search) return mid;
    if (cur_value < search) low = mid + 1;
    else high = mid - 1;
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
  int res = binarySearch(arr, arr[arr.size()-1]);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  if(res == -1) cout << "Item não encontrado" << endl;
  else cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

  arr.clear();
}