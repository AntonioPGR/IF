#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Equacao{
  public:
    int n1;
    int n2;
    int resultado;
    char operacao_correta;
};

Equacao leEntrada(){
  Equacao eq;
  string resto;
  stringstream fluxo;

  cin >> eq.n1 >> resto;

  int indice_igual = resto.find("=");
  fluxo << resto.substr(0, indice_igual);
  fluxo >> eq.n2;
  fluxo.clear();
  fluxo << resto.substr(indice_igual+1);
  fluxo >> eq.resultado;
  
  if(eq.n1 + eq.n2 == eq.resultado) eq.operacao_correta = '+';
  else if(eq.n1 - eq.n2 == eq.resultado) eq.operacao_correta = '-';
  else if(eq.n1 * eq.n2 == eq.resultado) eq.operacao_correta = '*';
  else eq.operacao_correta = 'I';

  return eq;
}

int main(){

  int casos;
  vector<Equacao> equacoes;
  vector<string> errados;

  while(cin >> casos){
    equacoes.clear();
    errados.clear();

    for(int i = 0; i < casos; i++){
      Equacao eq = leEntrada();
      equacoes.push_back(eq);
    }

    char op;
    int quest_number;
    string name;
    for(int i = 0; i < casos; i++){
      cin >> name >> quest_number >> op;
      if(equacoes.at(quest_number - 1).operacao_correta != op){
        errados.push_back(name);
      }
    }

    if(errados.size() == 0) cout << "You Shall All Pass!" << endl;
    else if(errados.size() == casos) cout << "None Shall Pass!" << endl;
    else {
      sort(errados.begin(), errados.end());
      cout << errados.at(0);
      for(int i = 1; i<errados.size(); i++) cout << " " << errados.at(i);
      cout << endl;
    }

    equacoes.clear();
    errados.clear();
  }

}