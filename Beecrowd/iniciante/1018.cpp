#include <iostream>
#include <vector>

using namespace std;

int main(){

  int valor;
  cin >> valor;
  int valor_inicial = valor;

  vector<int> cedulas = {100, 50, 20, 10, 5, 2, 1};
  vector<int> valores(7, 0);

  for(int i = 0; i < cedulas.size(); i++){
    if(cedulas[i] > valor) continue;
    valores[i] = valor / cedulas[i];
    valor = valor % cedulas[i];
  }

  cout << valor_inicial << endl;
  for(int i = 0; i < cedulas.size(); i++){
    cout << valores[i] << " nota(s) de R$ " << cedulas[i] << ",00" << endl;
  }

}