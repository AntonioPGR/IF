#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_POW 5
#define MAX_VALUE 30000

// Função de preenchimento do vetor
void populateArray(vector<int>& arr, int amount, int type) {
  arr.clear();  // Limpa o vetor antes de popular
  switch (type) {
    case 1:
      for (int i = 0; i < amount; i++) arr.push_back(rand() % (MAX_VALUE + 1));
      break;
    case 2:
      for (int i = 0; i < amount; i++) arr.push_back(i);
      break;
    case 3:
      for (int i = amount; i > 0; i--) arr.push_back(i);
      break;
    case 4:
      for (int i = 0; i < amount; i++) arr.push_back(rand() % ((amount / 3) + 1));
      break;
  }
}

// Função de impressão do vetor
void printArray(const vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// Bubble sort melhorado
void bubbleSort(vector<int>& arr) {
  int lastComparison = arr.size() - 1;
  for (int i = 0; i < arr.size(); i++) {
    bool isSorted = true;
    for (int j = 0; j < lastComparison; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSorted = false;
      }
    }
    if (isSorted) return;
    lastComparison--;
  }
}

int main() {
  for (int type = 1; type <= 4; type++) {
    int amount = 100;
    vector<int> arr;
    cout << "TIPO " << type << ": " << endl;

    for (int i = 1; i <= MAX_POW - 1; i++) {
      populateArray(arr, amount, type);
      auto start = high_resolution_clock::now();
      bubbleSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      amount *= 10;  // Aumenta a quantidade de elementos para o próximo teste
    }
  }
}
