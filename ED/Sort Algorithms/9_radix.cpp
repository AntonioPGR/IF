#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_POW 7
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

int getMax(vector<int>& arr){
  int mx = arr.at(0);
  for(int i = 1; i < arr.size(); i++){
    if(arr.at(i) > mx) mx = arr.at(i);
  }
  return mx;
}

void countSort(vector<int>& arr, int exp){
  vector<int> output(arr.size()), count(10, 0);

  for(int i = 0; i < arr.size(); i++) 
    count.at((arr.at(i)/exp) % 10)++;
  
  for(int i = 1; i < 10; i++)
    count.at(i) += count.at(i - 1);

  for(int i = arr.size() - 1; i >= 0; i--){
    output.at(count.at((arr.at(i)/exp) % 10) - 1) = arr.at(i);
    count.at((arr.at(i)/exp) % 10)--;
  }

  for(int i = 0; i < arr.size(); i++){
    arr.at(i) = output.at(i);
  }

}

void radixSort(vector<int>& arr){
  int m = getMax(arr);
  for(int exp = 1; m/exp > 0; exp*=10){
    countSort(arr, exp);
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
      radixSort(arr);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      cout << amount << " Items: " << duration.count() << " microsegundos" << endl;

      arr.clear();
      amount *= 10;
    }
  }

}