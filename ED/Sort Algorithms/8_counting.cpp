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

vector<int> countSort(vector<int>& input){
  int n = input.size();

  // Acha o maior elemento do vetor input (se o vetor tiver elementos negativos, tem que mudar o m)
  int m = 0;
  for(int i = 0; i < n; i++) m = max(m, input.at(i));

  // Cria um vetor count cheio de 0 e com m + 1 casas
  vector<int> count(m+1, 0);

  // Na casa do numero do vetor input, adiciona 1. 
  // Exemplo: se input[i] == 5, count[5] += 1
  for(int i = 0; i < n; i++) count.at(input.at(i))++;

  // Faz a soma dos preficos, auxiliando na hora de por os elementos do index no lugar correto do output
  // Exemplo: [2 0 2 3 0 1] -> [2 2 4 7 7 1]
  for(int i = 1; i <= m; i++) count.at(i) += count.at(i-1);

  // Cria o vetor de output
  vector<int> output(n);
  for(int i = n-1; i >= 0; i--){
    output.at(count.at(input.at(i)) - 1) = input.at(i);
    count.at(input.at(i))--;
  }
  return output;
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
      countSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}