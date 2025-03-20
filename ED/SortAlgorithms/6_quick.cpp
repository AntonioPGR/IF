// QuickSort 
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

int partition(vector<int>& arr, int low, int high){
  int random_pivot = low + rand() % (high - low + 1);
  swap(arr.at(random_pivot), arr.at(high));

  int pivot = arr.at(high);
  int i = low - 1;

  for(int j = low; j <= high - 1; j++){
    if(arr.at(j) < pivot){
      i++;
      swap(arr.at(i), arr.at(j));
    }
  }

  swap(arr.at(i+1), arr.at(high));
  return i + 1;
}

// Escolhe o pivo e arruma o pivo na sua posição, isso ocorre até que o vetor seja apenas um elemento.
void quickSort(vector<int>& arr, int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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
      quickSort(arr, 0, arr.size() - 1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}