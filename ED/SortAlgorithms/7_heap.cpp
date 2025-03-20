// HeapSort
// trata o vetor como uma árvore binária
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

// Faz a raiz da arvore ser o maior numero nela
void heapify(vector<int>& arr, int n, int i){
  int largest = i;

  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if(left < n && arr.at(left) > arr.at(largest)) largest = left;

  if(right < n && arr.at(right) > arr.at(largest)) largest = right;

  if(largest != i){
    swap(arr.at(i), arr.at(largest));
    // Heapify a sub arvore afetada
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int>& arr){
  int n = arr.size();

  // Construir o heap rearanjando o vetor
  for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);

  // Extrair os elementos do heap um por um
  for(int i = n - 1; i >= 0; i--){
    // mover raiz para o final
    swap(arr[0], arr[i]);

    // Chama o heapify no heap reduzido
    heapify(arr, i, 0);
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
      heapSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }
}