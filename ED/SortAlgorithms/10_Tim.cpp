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

const int RUN = 32;

void insertionSort(vector<int>& arr, int left, int right){
  for(int i = left + 1; i <=right; i++){
    int temp = arr[i];
    int j = i - 1;
    while(j >= left && arr[j] > temp){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

void merge(vector<int>& arr, int l, int m, int r){
  int len1 = m - l + 1, len2 = r - m;
  vector<int> left(len1), right(len2);
  for(int i = 0; i < len1; i++) left.at(i) = arr.at(l + i);
  for(int i = 0; i < len2; i++) right.at(i) = arr.at(m + 1 + i);

  int i = 0, j =0, k = l;
  while(i < len1 && j < len2){
    if (left[i] <= right[j]) { 
      arr[k] = left[i]; 
      i++; 
    } 
    else { 
      arr[k] = right[j]; 
      j++; 
    } 
    k++; 
  }

  while (i < len1) { 
    arr[k] = left[i]; 
    k++; 
    i++; 
  } 

  while (j < len2) { 
    arr[k] = right[j]; 
    k++; 
    j++; 
  } 
}

void timSort(vector<int>& arr){
  int n = arr.size();
  for(int i = 0; i < n; i += RUN)
    insertionSort(arr, i, min((i + RUN -1), (n-1)));

  for(int size = RUN; size < n; size = 2*size){
    for(int left = 0; left < n; left += 2* size){
      int mid = left + size - 1;
      int right = min((left + 2*size -1), (n-1));
      if(mid < right) merge(arr, left, mid, right);
    }
  }
}

int main(){

  int amount = 10000000, type=4;
  vector<int> arr;
  cout << "TIPO " << type << ": " << endl;

  for(int i = 1; i <= MAX_POW - 1; i++){
    arr.reserve(amount);
    populateArray(arr, amount, type);

    auto start = high_resolution_clock::now();
    timSort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

    arr.clear();
    amount *= 10;
  }

}