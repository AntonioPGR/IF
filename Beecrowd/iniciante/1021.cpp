#include <iostream>
#include <vector>

using namespace std;

int main(){
  
  float valor;
  cin >> valor;

  vector<float> notas = {100, 50, 20, 10, 5, 2};
  vector<int> notas_usadas(notas.size(), 0);

  vector<float> moedas = {1.0, 0.5, 0.25, 0.1, 0.05, 0.01};
  vector<int> moedas_usadas(moedas.size(), 0);

  cout << fixed;
  cout.precision(2);
  cout << "NOTAS:" << endl;
  for(int i = 0; i < notas.size(); i++){
    while(valor >= notas.at(i)){
      valor -= notas.at(i);
      notas_usadas.at(i)++;
    }
    cout << notas_usadas.at(i) << " nota(s) de R$ " << notas.at(i) << endl;
  }

  cout << "MOEDAS:" << endl;
  for(int i = 0; i < moedas.size(); i++){
    while(moedas.at(i) < valor){
      moedas_usadas.at(i)++;
      valor -= moedas.at(i);
    }
    if(valor > 0.005 && i == moedas_usadas.size()-1) moedas_usadas.at(moedas_usadas.size()-1)++;
    cout << moedas_usadas.at(i) << " moeda(s) de R$ " << moedas.at(i) << endl;
  }



}