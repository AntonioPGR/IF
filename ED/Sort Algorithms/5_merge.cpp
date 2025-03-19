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

// Junta dois subvetores, [left ... mid] e [mid+1 ... right]
void merge(vector<int>& arr, int left, int mid, int right){

  // Cria dois vetores temporarios de tamanho metade do final, e preenche ele com os dados
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> left_array(n1), right_array(n2);
  for(int i = 0; i < n1; i++) left_array.at(i) = arr[left+i];
  for(int i = 0; i < n2; i++) right_array.at(i) = arr[mid+1+i];

  // Junta os vetores temporarios em arr[left...right] 
  // k = local onde inserir o proximo menor numero
  // i = ponteiro do vetor left
  // j = ponteiro do vetor right
  // os ponteiros de vetores só andam quando o valor em sua posição é inserido em k
  int i = 0, j = 0, k = left;
  while(i < n1 && j < n2){
    if(left_array.at(i) <= right_array.at(j)){
      arr.at(k) = left_array.at(i);
      i++;
    } else {
      arr.at(k) = right_array.at(j);
      j++;
    }
    k++;
  }

  // copia os elementos restantes do vetor left se existirem
  while(i < n1){
    arr.at(k) = left_array.at(i);
    i++;
    k++;
  }

  while(j < n2){
    arr.at(k) = right_array.at(j);
    j++;
    k++;
  }

}

// Divide o vetor em dois pedaços até que sobre apenas um elemento em cada vetor. Quando o vetor da esquerda e da direita for, por exemplo, [6] e [4], faz o merge deles em ordem cresente, retornando [4, 6], podendo juntar com o merge de outro vetor, como por exemplo o do [7] [5] -> [5, 7] + [4, 6] -> [4, 5, 6, 7]
void mergeSort(vector<int>& arr, int left, int right){
  if(left >= right) return;
  int mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right);
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
      mergeSort(arr, 0, arr.size()-1);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}