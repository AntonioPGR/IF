#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

  int qnt_titans, tita_p, tita_m, tita_g, vida_atual, tamanho_muralha;
  string ordem_titans;
  int qnt_muralhas = 1;

  cin >> qnt_titans >> tamanho_muralha;
  cin >> ordem_titans;
  cin >> tita_p >> tita_m >> tita_g;

  vida_atual = tamanho_muralha;
  for(int i = 0; i < ordem_titans.size(); i++){
    int vida_tirada;
    switch (ordem_titans.at(i)){
      case 'P': vida_tirada = tita_p;
        break;
      case 'M': vida_tirada = tita_m;
        break;
      case 'G': vida_tirada = tita_g;
        break;
    }
    if(vida_atual > vida_tirada){
      vida_atual -= vida_tirada;
      // cout << "bateu" << endl;
    } else if(vida_atual == vida_tirada){
      vida_atual = tamanho_muralha;
      qnt_muralhas++;
      // cout << "quebrou" << endl;
    } else {
      vida_atual = tamanho_muralha - vida_tirada;
      qnt_muralhas++;
      // cout << "pulou e bateu" << endl;
    }
  }

  cout << qnt_muralhas << endl;

}
