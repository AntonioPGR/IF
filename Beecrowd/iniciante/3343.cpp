#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int n, x;
  cin >> n >> x;

  vector<int> muralhas;
  muralhas.push_back(x);

  cin.clear();
  cin.ignore();
  string titas;
  getline(cin, titas);

  int pequeno, medio, grande;
  cin >> pequeno >> medio >> grande;

  int amount = 0;
  for(int i = 0; i < n; i++){
    int damage = 0;
    switch (titas[i]){
      case 'P': damage += pequeno;
      break;
      case 'M': damage += medio;
      break;
      case 'G': damage += grande;
      break;
    }

    int j = 0;
    while(j < muralhas.size() && damage > muralhas[j]) j++;

    if(muralhas.size() == j) muralhas.push_back(x);

    muralhas[j] -= damage;
    if(muralhas[j] < pequeno){
      muralhas.erase(muralhas.begin()+j);
      amount++;
    } 
  }

  cout << muralhas.size() + amount << endl;
}
