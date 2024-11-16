#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, temp;
  while(cin >> n){
    vector<int> trabalhos;
    long long int aluno1 = 0, aluno2 = 0, soma_total=0, menor_diferenca;

    for(int i = 0; i < n; i++){
      cin >> temp;
      trabalhos.push_back(temp);
      soma_total += temp;
    }

    aluno2 = soma_total;
    menor_diferenca = soma_total;
    for(int i = 0; i < n; i++){
      aluno1 += trabalhos.at(i);
      aluno2 -= trabalhos.at(i);
      long long diferenca_atual = abs(aluno1 - aluno2);
      if(diferenca_atual < menor_diferenca) menor_diferenca = diferenca_atual;
    }

    cout << menor_diferenca << endl;
  }
}