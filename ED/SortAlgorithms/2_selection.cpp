/*
  SelectionSort

  Melhor: o(n^2)
  Médio: o(n^2)
  Pior: o(n^2)
*/
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_POW 5
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

int main(){

  for(int type = 1; type <= 4; type++){
    int amount = 100;
    vector<int> arr;
    cout << "TIPO " << type << ": " << endl;

    for(int i = 1; i <= MAX_POW - 1; i++){
      arr.reserve(amount);
      populateArray(arr, amount, type);

      auto start = high_resolution_clock::now();
      selectionSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}